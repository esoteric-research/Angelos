
#ifndef _BFVM_RUNTIME
#define _BFVM_RUNTIME

#define SIV static inline void

/* Expects: _BFVM_TYPE - either uint32_t or uint16_t (default).
            _BFVM_FREESTANDING - if building in freestanding mode. */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define Q 16

static _BFVM_TYPE mp, sp, scale_factor = 2;

#ifndef _BFVM_FREESTANDING
    static _BFVM_TYPE * tape;

    SIV debug(void) {
        fprintf(stderr, "\n~ BFVM Breakpoint ~\n");
        
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++)
                if(i * 10 + j == mp)
                    fprintf(stderr, " !%X! ", tape[i * 10 + j]);
                else
                    fprintf(stderr, "  %X  ", tape[i * 10 + j]);
            fputs("\n", stderr);
        }

        fprintf(stderr, "\n~   registers   ~\n");
        fprintf(stderr, "G:  %04X IP: %04X\n", tape[0], tape[1]);
        fprintf(stderr, "R1: %04X R2: %04X\n", tape[5], tape[6]);
        fprintf(stderr, "R3: %04X R4: %04X\n", tape[7], tape[8]);
        fprintf(stderr, "IM: %04X R5: %04X\n", tape[9], tape[17]);
        fprintf(stderr, "R6: %04X sp: %04X\n\n", tape[18], sp);
    }
#else
    static _BFVM_TYPE * tape = (_BFVM_TYPE *) 0x7000;
#endif

#define _BFVM_OFF(x) ((x) - 'a')

/* unsigned pow */
static inline _BFVM_TYPE bfvm_pow(_BFVM_TYPE x, _BFVM_TYPE y) {
    _BFVM_TYPE i = 1, s = x;

    for(; i < y; i++)
        s *= x;
    
    return s;
}

static inline _BFVM_TYPE bfvm_par(_BFVM_TYPE x) {
    _BFVM_TYPE parity = 0;
    
    while(x) {
        parity ^= x;
        x >>= 1;
    }

    return parity & 1;
}

static inline _BFVM_TYPE gcd(_BFVM_TYPE a, _BFVM_TYPE b) {
    _BFVM_TYPE temp;

    while(b) {
        temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

#define asmbf_first \
    tape[0] = 1; tape[1] = 1; \
    mp = 1; while(tape[mp]) {

#define asmbf_last \
    if(tape[0]) tape[1] = 0; mp = 1; }

#define asmbf_pre \
    mp = 0; if(tape[mp]) {

#define asmbf_post \
    mp = 2; }

#define asmbf_end \
    return 0;

#define bfvm_pop \
    tape[mp + scale_factor * --sp]

#define bfvm_push \
    tape[mp + scale_factor * sp++]

SIV asmbf_immed(int offset) { mp += offset; }
SIV asmbf_clear(int offset) { mp += offset; tape[mp] = 0; }

#define _BFVM_DYAD(name, oper) \
    SIV asmbf_ ## name(int from1, int from2) {\
        mp += from1; \
        _BFVM_TYPE * cell = tape + mp; \
        *cell = (*cell) oper (tape[mp += from2]); \
    }

_BFVM_DYAD(add, +)
_BFVM_DYAD(and, &&)
_BFVM_DYAD(div, /)
_BFVM_DYAD(eq, ==)
_BFVM_DYAD(ge, >=)
_BFVM_DYAD(gt, >)
_BFVM_DYAD(le, <=)
_BFVM_DYAD(lt, <)
_BFVM_DYAD(mod, %)
_BFVM_DYAD(mul, *)
_BFVM_DYAD(ne, !=)
_BFVM_DYAD(or, ||)
_BFVM_DYAD(sub, -)

SIV asmbf_rse_toggle(void) {
    scale_factor = 1 + !(scale_factor - 1);
}

SIV asmbf_pow(int from1, int from2) {
    mp += from1;
    _BFVM_TYPE * cell = tape + mp;
    *cell = bfvm_pow(*cell, tape[mp += from2]);
}

SIV asmbf_dec(int offset) { mp += offset; tape[mp]--; }
SIV asmbf_inc(int offset) { mp += offset; tape[mp]++; }
SIV asmbf_asr(int offset) { mp += offset; tape[mp] >>= 1; }
SIV asmbf_asl(int offset) { mp += offset; tape[mp] <<= 1; }
SIV asmbf_jmp(int loc) { mp += loc; tape[0] = 0; tape[1] = tape[mp]; }
SIV asmbf_neg(int offset) { mp += offset; tape[mp] = 0 - tape[mp]; }
SIV asmbf_not(int offset) { mp += offset; tape[mp] = 1 - tape[mp]; }
SIV asmbf_log(int offset) { mp += offset; tape[mp] = tape[mp] > 0; }

SIV asmbf_in(int offset) {
    mp += offset;

    #ifndef _FREESTANDING
        int8_t v = getchar();
        tape[mp] = v == EOF ? 0 : v;
    #else
        tape[mp] = 0;
    #endif
}

SIV asmbf_out(int offset) {
    mp += offset;

    #ifndef _FREESTANDING
        putchar(tape[mp]);
    #endif
}

SIV asmbf_jnz(int offset, int loc) {
    mp += offset; _BFVM_TYPE val = tape[mp]; mp += loc;
    if(val == 0) return; tape[0] = 0; tape[1] = tape[mp];
}

SIV asmbf_jz(int offset, int loc) {
    mp += offset; _BFVM_TYPE val = tape[mp]; mp += loc;
    if(val != 0) return; tape[0] = 0; tape[1] = tape[mp];
}

SIV asmbf_mov(int from1, int from2) {
    mp += from1;
    _BFVM_TYPE * cell = tape + mp;
    *cell = tape[mp += from2];
}

SIV asmbf_push(int from, int stack_off) {
    mp += from;
    _BFVM_TYPE to_push = tape[mp];
    mp += stack_off;
    bfvm_push = to_push;
}

SIV asmbf_srv(int stack_off) {
    mp += stack_off;
    _BFVM_TYPE val1 = bfvm_pop;
    _BFVM_TYPE val2 = bfvm_pop;
    bfvm_push = val1;
    bfvm_push = val2;
}

SIV asmbf_dup(int stack_off) {
    mp += stack_off;
    _BFVM_TYPE val1 = bfvm_pop;
    bfvm_push = val1;
    bfvm_push = val1;
}

SIV asmbf_pop(int dest, int stack_off) {
    mp += dest;
    _BFVM_TYPE * cell = tape + mp;
    mp += stack_off;
    *cell = bfvm_pop;
}

SIV asmbf_rcl(int dest, int addr, int ram_off) {
    mp += dest;
    _BFVM_TYPE * data = tape + mp;
    mp += addr;
    _BFVM_TYPE xaddr = tape[mp];
    mp += ram_off;
    *data = tape[mp + 2 + scale_factor * xaddr];
}

SIV asmbf_sto(int addr, int src, int ram_off) {
    mp += addr;
    _BFVM_TYPE xaddr = tape[mp];
    mp += src;
    _BFVM_TYPE xsrc = tape[mp];
    mp += ram_off;
    tape[mp + 2 + scale_factor * xaddr] = xsrc;
}

SIV asmbf_amp(int addr, int src, int ram_off) {
    mp += addr;
    _BFVM_TYPE xaddr = tape[mp];
    mp += src;
    _BFVM_TYPE xsrc = tape[mp];
    mp += ram_off;
    tape[mp + 2 + scale_factor * xaddr] += xsrc;
}

SIV asmbf_smp(int addr, int src, int ram_off) {
    mp += addr;
    _BFVM_TYPE xaddr = tape[mp];
    mp += src;
    _BFVM_TYPE xsrc = tape[mp];
    mp += ram_off;
    tape[mp + 2 + scale_factor * xaddr] -= xsrc;
}

SIV asmbf_swp(int opr1, int opr2) {
    mp += opr1; _BFVM_TYPE * addr1 = tape + mp;
    mp += opr2; _BFVM_TYPE * addr2 = tape + mp;

    _BFVM_TYPE tmp = *addr1;
    *addr1 = *addr2;
    *addr2 = tmp;
}

SIV asmbf_ret(int stack_off) {
    mp += stack_off;
    tape[0] = 0;
    tape[1] = bfvm_pop;
}

#define _BFVM_CC(name, kind) \
    SIV asmbf_c ## name(int opr1, int opr2, int qflag) { \
        _BFVM_TYPE v1, v2; mp += opr1; v1 = tape[mp]; mp += opr2; v2 = tape[mp]; \
        mp += qflag; tape[mp] = v1 kind v2; }

_BFVM_CC(eq, ==)
_BFVM_CC(ne, !=)
_BFVM_CC(le, <=)
_BFVM_CC(lt, <)
_BFVM_CC(ge, >=)
_BFVM_CC(gt, >)

SIV asmbf_cjn(int target) { mp += target; if(tape[Q] == 0) return; tape[0] = 0; tape[1] = tape[mp]; }
SIV asmbf_cjz(int target) { mp += target; if(tape[Q] != 0) return; tape[0] = 0; tape[1] = tape[mp]; }

#define _BFVM_CV1(orig) SIV asmbf_c ## orig (int opr) { if(tape[Q]) asmbf_ ## orig(opr); }
#define _BFVM_CV2(orig) SIV asmbf_c ## orig (int opr1, int opr2) { if(tape[Q]) asmbf_ ## orig(opr1, opr2); }
#define _BFVM_CV3(orig) SIV asmbf_c ## orig (int opr1, int opr2, int opr3) { if(tape[Q]) asmbf_ ## orig(opr1, opr2, opr3); }

_BFVM_CV2(add); _BFVM_CV2(sub); _BFVM_CV2(mul); _BFVM_CV2(div); _BFVM_CV2(mod);
_BFVM_CV1(asl); _BFVM_CV1(asr); _BFVM_CV2(pow); _BFVM_CV2(push); _BFVM_CV2(pop);
_BFVM_CV2(swp); _BFVM_CV1(srv); _BFVM_CV2(mov); _BFVM_CV3(rcl); _BFVM_CV3(sto);
_BFVM_CV3(amp); _BFVM_CV3(smp); _BFVM_CV1(in); _BFVM_CV1(out); _BFVM_CV1(dup);

SIV asmbf_cflip() { tape[Q] = !tape[Q]; }

_BFVM_DYAD(band, &)
_BFVM_DYAD(bor, |)
_BFVM_DYAD(bxor, ^)

SIV asmbf_bneg(int off) { mp += off; tape[mp] = ~tape[mp]; }

_BFVM_DYAD(shl, <<)
_BFVM_DYAD(shr, >>)

SIV asmbf_par(int dest, int src) { mp += dest; _BFVM_TYPE * cell = tape + mp; mp += src; *cell = bfvm_par(tape[mp]); }
SIV asmbf_cpar(int src) { mp += src; tape[Q] = bfvm_par(tape[mp]); }

SIV asmbf_gcd(int to, int from) {
    mp += to;
    _BFVM_TYPE * cell = tape + mp;
    *cell = gcd(*cell, tape[mp += from]);
}

_BFVM_CV2(gcd); _BFVM_CV1(ret);

SIV asmbf_fmul(int stkof) {
    mp += stkof;
    _BFVM_TYPE val1 = bfvm_pop;
    _BFVM_TYPE val2 = bfvm_pop;
    _BFVM_TYPE val3 = bfvm_pop;
    _BFVM_TYPE val4 = bfvm_pop;
    val1 *= val3;
    val2 *= val4;
    bfvm_push = val2;
    bfvm_push = val1;
}

SIV asmbf_fdiv(int stkof) {
    mp += stkof;
    _BFVM_TYPE val1 = bfvm_pop;
    _BFVM_TYPE val2 = bfvm_pop;
    _BFVM_TYPE val3 = bfvm_pop;
    _BFVM_TYPE val4 = bfvm_pop;
    val1 *= val4;
    val2 *= val3;
    bfvm_push = val2;
    bfvm_push = val1;
}

SIV asmbf_fadd(int stkof) {
    mp += stkof;
    _BFVM_TYPE n1 = bfvm_pop;
    _BFVM_TYPE d1 = bfvm_pop;
    _BFVM_TYPE n2 = bfvm_pop;
    _BFVM_TYPE d2 = bfvm_pop;
    if(d1 == d2) {
        bfvm_push = d1;
        bfvm_push = n1 + n2;
    } else {
        bfvm_push = d1 * d2;
        bfvm_push = n1 * d2 + n2 * d1;
    }
}

SIV asmbf_fsub(int stkof) {
    mp += stkof;
    _BFVM_TYPE n1 = bfvm_pop;
    _BFVM_TYPE d1 = bfvm_pop;
    _BFVM_TYPE n2 = bfvm_pop;
    _BFVM_TYPE d2 = bfvm_pop;
    if(d1 == d2) {
        bfvm_push = d1;
        bfvm_push = n1 - n2;
    } else {
        bfvm_push = d1 * d2;
        bfvm_push = n1 * d2 - n2 * d1;
    }
}

SIV asmbf_freduce(int stkof) {
    mp += stkof;
    _BFVM_TYPE val1 = bfvm_pop;
    _BFVM_TYPE val2 = bfvm_pop;
    _BFVM_TYPE nval1 = val1 / gcd(val1, val2);
    _BFVM_TYPE nval2 = val2 / gcd(val1, val2);
    bfvm_push = nval2;
    bfvm_push = nval1;
}

#define _BFVM_SPR(name, op1, op2) \
    SIV asmbf_c ## name (int opr1, int opr2) { \
        _BFVM_TYPE o1, o2; mp += opr1; o1 = tape[mp]; mp += opr2; o2 = tape[mp]; \
        _BFVM_TYPE val = o1 op1 o2; tape[Q] = tape[Q] op2 val; \
    }

#define _BFVM_SPRALL(p, k) \
    _BFVM_SPR(p ## eq, ==, k) \
    _BFVM_SPR(p ## ne, !=, k) \
    _BFVM_SPR(p ## le, <=, k) \
    _BFVM_SPR(p ## lt, <, k) \
    _BFVM_SPR(p ## gt, >, k) \
    _BFVM_SPR(p ## ge, >=, k)

_BFVM_SPRALL(and, &&)
_BFVM_SPRALL(or, ||)
_BFVM_SPRALL(xor, !=)

SIV asmbf_ots(int addr, int src, int ram_off) {
    mp += addr;
    _BFVM_TYPE xaddr = tape[mp];
    mp += src;
    _BFVM_TYPE xsrc = tape[mp];
    mp += ram_off;
    tape[mp + 2 + scale_factor * xsrc] = xaddr;
}
_BFVM_CV3(ots);

SIV asmbf_dsc(int stack_off) { mp += stack_off; --sp; }

SIV asmbf_sgt(int dest, int srcidx, int stk_off) {
    mp += dest; _BFVM_TYPE * cell = tape + mp;
    mp += srcidx; _BFVM_TYPE idx = tape[mp];
    mp += stk_off; *cell = tape[mp + scale_factor * (sp - idx)];
}

SIV asmbf_spt(int dest, int srcidx, int stk_off) {
    mp += dest; _BFVM_TYPE idx = tape[mp];
    mp += srcidx; _BFVM_TYPE val = tape[mp];
    mp += stk_off; tape[mp + scale_factor * (sp - val)] = idx;
}

SIV asmbf_tps(int dest, int srcidx, int stk_off) {
    mp += dest; _BFVM_TYPE idx = tape[mp];
    mp += srcidx; _BFVM_TYPE val = tape[mp];
    mp += stk_off; tape[mp + scale_factor * (sp - idx)] = val;
}

SIV asmbf_sle(int dest, int stk_off) { mp += dest; tape[mp] = sp; mp += stk_off; }
SIV asmbf_fps(int stk_off) { mp += stk_off; bfvm_push = tape[Q]; }
SIV asmbf_fpo(int stk_off) { mp += stk_off; tape[Q] = bfvm_pop; }

SIV asmbf_sgn(int val) { mp += val; tape[mp] &= 1; }
SIV asmbf_abs(int val) { mp += val; tape[mp] >>= 1; tape[mp] <<= 1; }
SIV asmbf_sneg(int val) { mp += val; tape[mp] ^= 1; if(tape[mp] == 1) tape[mp] = 0; }

#define _BFVM_SK1(n, kind) \
    SIV asmbf_s ## n(int opr1, int opr2) { \
        _BFVM_TYPE * x = tape + (mp += opr1); \
        _BFVM_TYPE y = tape[mp += opr2]; \
        _BFVM_TYPE sgn = *x & 1 ^ y & 1; \
        *x = ((*x >> 1) kind (y >> 1)) << 1 | sgn; \
        if(*x == 1) *x = 0; \
    }

_BFVM_SK1(mul, *) _BFVM_SK1(div, /) _BFVM_SK1(mod, %)

#define _BFVM_SK2 \
    _BFVM_TYPE * x = tape + (mp += opr1); \
    _BFVM_TYPE y = tape[mp += opr2]; \
    _BFVM_TYPE sgx = *x & 1, sgy = y & 1; \
    _BFVM_TYPE rx = *x >> 1, ry = y >> 1; \

SIV asmbf_sadd(int opr1, int opr2) {
    _BFVM_SK2
    if(sgx != sgy) {
        _BFVM_TYPE n0 = sgx ? rx : ry, n1 = sgx ? ry : rx;
        *x = (n0 < n1) ? ((n1 - n0) << 1) : ((n0 - n1) << 1 | 1);
    } else
        *x = (rx + ry) << 1 | sgx;
    if(*x == 1) *x = 0;
}

SIV asmbf_ssub(int opr1, int opr2) {
    _BFVM_SK2
    sgy = !sgy;
    if(sgx != sgy) {
        _BFVM_TYPE n0 = sgx ? rx : ry, n1 = sgx ? ry : rx;
        *x = (n0 < n1) ? ((n1 - n0) << 1) : ((n0 - n1) << 1 | 1);
    } else
        *x = (rx + ry) << 1 | sgx;
    if(*x == 1) *x = 0;
}

SIV asmbf_dup2(int stk_off) {
    mp += stk_off;
    _BFVM_TYPE a, b; a = bfvm_pop; b = bfvm_pop;
    bfvm_push = b; bfvm_push = a;
    bfvm_push = b; bfvm_push = a;
}

SIV asmbf_axl(int stk_off) {
    mp += stk_off;
    _BFVM_TYPE n = bfvm_pop;
    _BFVM_TYPE d = bfvm_pop;
    n = (n * 100) / d;
    bfvm_push = n / 100;
    bfvm_push = n % 100;
}

SIV asmbf_xgt(int opr1, int opr2) { _BFVM_SK2 *x = sgx != sgy ? sgy == 1 : (sgy == 1 ? rx < ry : rx > ry); }
SIV asmbf_xge(int opr1, int opr2) { _BFVM_SK2 if(*x == y) *x = 1; else *x = sgx != sgy ? sgy == 1 : (sgy == 1 ? rx < ry : rx > ry); }
SIV asmbf_xlt(int opr1, int opr2) { _BFVM_SK2 *x = sgx != sgy ? sgy == 0 : (sgy == 0 ? rx < ry : rx > ry); }
SIV asmbf_xle(int opr1, int opr2) { _BFVM_SK2 if(*x == y) *x = 1; else *x = sgx != sgy ? sgy == 0 : (sgy == 0 ? rx < ry : rx > ry); }

SIV asmbf_lods(int dest, int addr, int ram_off) {
    mp += dest;
    _BFVM_TYPE * data = tape + mp;
    mp += addr;
    _BFVM_TYPE xaddr = tape[mp];
    tape[mp]++;
    mp += ram_off;
    *data = tape[mp + 2 + scale_factor * xaddr];
}

SIV asmbf_stos(int addr, int src, int ram_off) {
    mp += addr;
    _BFVM_TYPE xaddr = tape[mp];
    tape[mp]++;
    mp += src;
    _BFVM_TYPE xsrc = tape[mp];
    mp += ram_off;
    tape[mp + 2 + scale_factor * xaddr] = xsrc;
}

SIV asmbf_scas(int addr, int cmpv, int ram_off) {
    mp += addr;
    _BFVM_TYPE xaddr = tape[mp];
    tape[mp]++;
    mp += cmpv;
    _BFVM_TYPE cmpval = tape[mp];
    mp += ram_off;
    tape[Q] = tape[mp + 2 + scale_factor * xaddr] == cmpval;
}

#endif
