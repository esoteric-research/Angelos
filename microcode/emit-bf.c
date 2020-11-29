"a+b+[<[>-]>[>]<\0" /* 0 first */
"b]\0" /* 1 last (end, post, last) */
"a[c+a-]c[-a+\0" /* 2 pre */
"c]\0" /* 3 post */
"2\0" /* 4 immed */
"2[-]\0" /* 5 immed clear */
"2[1+e+2-]e[2+e-]\0" /* 6 add */
"1[e+1[-]]e[-2[1+2[e+2-]]e[2+e-]]\0" /* and */
"2-\0" /* dec */
"2[n+2-]1[m+>-[>>]<[[>+<-]<+>>>]<<1-]l[1+l-]m[2+m-]n[2+n-]\0" /* div */
"1[2-e+1-]+2[1-2[e+2-]]e[2+e-]\0" /* eq_, alternatively: 2[1-e+2-]e[2+e-]1[e+1[-]]+e[1-e-] */
"1[n+1-]+2[m+2-]m[2+m>[-<]>]<<[1-m-[2+m-]<<]>>n[-]\0" /* ge_ */
"1[m+1-]2[n+2-]m[2+m>[-<]>]<<[[-]1+2-m<<]>>n[2+n-]\0" /* gt_ */
"2,\0" /* in_ */
"2+\0" /* inc */
"a[-]b[-]2[b+c+2-]c[2+c-]\0" /* jmp addr */
"1[a[-]2[b+c+2-]c[2+c-]1[c+1-]]c[1+c-]\0" /* jnz val, addr */
"1[d-1[c+1-]]c[1+c-]d+[-a[-]2[b+c+2-]c[2+c-]d]\0" /* jz_ val, addr */
"a[e[-]c-a-]+c+[-b[c+e-b-]e[a-c[b+e+c-]e[-]]c[-]]\0" /* lbl */
"1[m+1-]+2[n+2-]m[2+m>[-<]>]<<[[-]1-2-m<<]>>n[2+n-]\0" /* le_ */
"1[n+1-]2[m+2-]m[2+m>[-<]>]<<[1-m-[2+m-]<<]>>n[-]\0" /* lt_ */
"2[n+2-]1[m+>-[<<]<[[>+<-]<<]>>1-]m[1+2+m-]n[2+n-]\0" /* mod */
"1[-]2[1+e+2-]e[2+e-]\0" /* 22 mov */
"1[d+1-]d[2[1+e+2-]e[2+e-]d-]\0" /* mul */
"1[2-c+1-]2[1+2[c+2-]]c[2+c-]\0" /* ne_, alternatively: 2[1-e+2-]e[2+e-]1[e+1[-]]e[1+e-] */
"2[e-2-]e[2+e-]\0" /* neg */
"2-[e-2-]e[2+e-]\0" /* not */
"1[e-1[-]]+e+[-1-2[1+[e+2-]]e[2+e-]]\0" /* or_ */
"2.\0" /* out */
"2[-]#>[>>]<<->[<<<[<<]>2+#>[>>]>-]<<<[<<]>\0" /* pop */
"2[p+#>[>>]>+<<<[<<]>2-]p[2+p-]#>[>>]+[<<]>\0" /* psh */
"1[-]2[p+*>[>>]+[<<]>2-]p[2+p-]*>[>>]>[<<<[<<]>1+*>[>>]>>+<-]>[<+>-]<<<<[-<<]>\0"  /* rcl */
"1[p+*>[>>]+[<<]>1-]p[1+p-]*>[>>]>[-]<<<[<<]>2[p+*>[>>]>+<<<[<<]>2-]p[2+p-]*>[>>]<<[-<<]>\0" /* sto */
"2[1-e+2-]e[2+e-]\0" /* sub */
"1[e+1-]2[1+2-]e[2+e-]\0" /* swp */
"2[-]\0" /* clr */
"a[-]b[-]#>[>>]<<->[<<<[<<]>b+#>[>>]>-]<<<[<<]>\0" /* ret */
"a[-]b[-]\0" /* end */
"2[e+2[-]]e[2+e-]\0" /* log */
"2[e+2-]e[2++e-]\0" /* asl */
"2[m+2-]k+m[-[-2+m>]<]<[>]>k-\0" /* asr */
"1[k+1-]+2[c+1[k[l+m+k-]l[k+l-]1-]m[1+m-]2-]c[2+c-]k[-]\0" /* pow */
"#>[>>]<[<+>-]<<[>>+<<-]>-[<+>-]+[<<]>\0" /* srv */
"1[e+*>[>>]+[<<]>1-]e[1+e-]2[e+*>[>>]>+<<<[<<]>2-]e[2+e-]*>[>>]<<[-<<]>\0" /* amp */
"1[e+*>[>>]+[<<]>1-]e[1+e-]2[e+*>[>>]>-<<<[<<]>2-]e[2+e-]*>[>>]<<[-<<]>\0" /* smp */
"2\0" /* nav */ 
"q[-]+2[1-e+2-]1[q-1[2-e+1-]]e[2+1+e-]\0" /* ceq v */
"q[-]1[2-e+1-]2[q+2[1-e+2-]]e[1+2+e-]\0" /* cne v */
"q[-]+1[m+1-]2[n+2-]m[1+2+m>[-<]>]<<[q-2-m-[1+m-]<<]>>n[2+n-]\0" /* cle v */
"q[-]1[n+1-]2[m+2-]m[1+2+m>[-<]>]<<[q+1-m-[2+m-]<<]>>n[1+n-]\0" /* clt */
"q[-]+1[n+1-]2[m+2-]m[1+2+m>[-<]>]<<[q-1-m-[2+m-]<<]>>n[1+n-]\0" /* cge v */
"q[-]1[m+1-]2[n+2-]m[1+2+m>[-<]>]<<[q+2-m-[1+m-]<<]>>n[2+n-]\0" /* cgt v */
"q[c+d+q-]c[q+c-]d[a[-]b[-]2[b+c+2-]c[2+c-]d[-]]\0" /* cjn v */
"p+>[<-]<[-a[-]b[-]2[b+c+2-]c[2+c-]p<]>\0" /* cjz v */
"q[2[1+e+2-]e[2+e-]p<+>]<[->]\0" /* cad v */
"q[2[1-e+2-]e[2+e-]p<+>]<[->]\0" /* csu v */
"q[1[d+1-]d[2[1+e+2-]e[2+e-]d-]p<+>]<[->]\0" /* cmu */
"q[2[n+2-]1[m+>-[>>]<[[>+<-]<+>>>]<<1-]l[1+l-]m[2+m-]n[2+n-]p<+>]<[->]\0" /* cdi */
"q[2[n+2-]1[m+>-[<<]<[[>+<-]<<]>>1-]m[1+2+m-]n[2+n-]p<+>]<[->]\0" /* cmd */
"q[2[e+2-]e[2++e-]p<+>]<[->]\0" /* csl v */
"q[2[m+2-]k+m[-[-2+m>]<]<[>]>k-p<+>]<[->]\0" /* csr v */
"q[1[k+1-]+2[c+1[k[l+m+k-]l[k+l-]1-]m[1+m-]2-]c[2+c-]k[-]p<+>]<[->]\0" /* cpw v */
"q[2[p+#>[>>]>+<<<[<<]>2-]p[2+p-]#>[>>]+[<<]>p<+>]<[->]\0" /* cps v */
"q[2[-]#>[>>]<<->[<<<[<<]>2+#>[>>]>-]<<<[<<]>p<+>]<[->]\0" /* cpo v */
"q[1[e+1-]2[1+2-]e[2+e-]p<+>]<[->]\0" /* csw v */
"q[#>[>>]<[<+>-]<<[>>+<<-]>-[<+>-]+[<<]>p<+>]<[->]\0" /* crv v */
"q[1[-]2[1+e+2-]e[2+e-]p<+>]<[->]\0" /* cmo v */
"q[1[-]2[p+*>[>>]+[<<]>2-]p[2+p-]*>[>>]>[<<<[<<]>1+*>[>>]>>+<-]>[<+>-]<<<<[-<<]>p<+>]<[->]\0" /* crc v */
"q[1[p+*>[>>]+[<<]>1-]p[1+p-]*>[>>]>[-]<<<[<<]>2[p+*>[>>]>+<<<[<<]>2-]p[2+p-]*>[>>]<<[-<<]>p<+>]<[->]\0" /* cst v */
"q[1[e+*>[>>]+[<<]>1-]e[1+e-]2[e+*>[>>]>+<<<[<<]>2-]e[2+e-]*>[>>]<<[-<<]>p<+>]<[->]\0" /* cam */
"q[1[e+*>[>>]+[<<]>1-]e[1+e-]2[e+*>[>>]>-<<<[<<]>2-]e[2+e-]*>[>>]<<[-<<]>p<+>]<[->]\0" /* csm */
"1[l+1-]2[1+n+2-]1[2+1-]e+l[>>[-[->>+<]<]<[>>>+<<]<[-[->>+<]<]>>[>-<<]>>[+[--<<<e[d+1+e-]o]]p[l+p-]e[<+>-]<[>++<-]>l]n[-]e[-]\0" /* x00 */
"1[l+1-]2[1+n+2-]1[2+1-]e+l[>>[-[->>+<]<]<[>>>+<<]<[-[->>+<]<]>>[>-<<]>>+[<<<e[d+1+e-]o[-]]p[l+p-]e[<+>-]<[>++<-]>l]n[e[d+1+e-]d[>+<-]n-]e[-]\0" /* x01 */
"1[l+1-]2[1+n+2-]1[2+1-]e+l[>>[-[->>+<]<]<[>>>-<<]<[-[->>+<]<]>>[>-<<]>>+[<<<e[d+1+e-]o+[-]]p[l+p-]e[<+>-]<[>++<-]>l]n[e[d+1+e-]d[>+<-]n-]e[-]\0" /* x02 */
"2[d+2-]-d[2-d-]\0" /* x03 */
"p+>-[++<-]<[-<]>\0" /* x04 */
"k+2[e+1[m+1-]m[-[-1+m>]<]<[>]>2-]e[2+e-]k-\0" /* shr */
"2[d+2-]d[2+1[e+1-]e[1++e-]d-]\0" /* shl */
"q[2.p<+>]<[->]\0" /* cou */
"q[2,p<+>]<[->]\0" /* cin */
"2[m+2-]k+q[-]m[-[-2++m>]<]<[>>2+q+m<]>k-\0" /* cpa */
"2[m+2-]k+1[-]m[-[-2++m>]<]<[>>2+1+m<]>k-\0" /* par */
"1[k+1-]2[l+m+2-]m[2+m-]l[<[>>+<-[>>]>[[<+>-]>>]<<<<-]>[<+>-]>[<<+>+>-]<]k[1+k-]\0" /* gcd */
"q[1[k+1-]2[l+m+2-]m[2+m-]l[<[>>+<-[>>]>[[<+>-]>>]<<<<-]>[<+>-]>[<<+>+>-]<]k[1+k-]p<+>]<[->]\0" /* cgc */
"q[a[-]b[-]#>[>>]<<->[<<<[<<]>b+#>[>>]>-]<<<[<<]>p<+>]<[->]\0" /* cre */
"#>[>>]<<[-<<<[<+>-]<-[>>>>>[<<<<+>>>+>-]<[>+<-]<<<<-]>>>>>[-]<<<]+<<+[<<]>\0" /* fmul */
"#>[>>]<<-<<-<<-<[>+<-]>>[>>[<<<<+>>>+>-]<[>+<-]<-]>>[-]>>[<<<<<[>+>+<<-]>>[<<+>>-]>>>-]<<<<<[-]+[<<]>\0" /* fdiv */
"#>[>>]<<-<[<+>>+<-]>>[<<+>>>+<-]>[<<[>+>-[>>]<[[>+<-]>>]<<<-]>>[<<+>>-]<[<+>>+<-]>]<<<[>[<->>>+<<-]>+>[<<+>>-]<<<]<-[>+>[<<->>>>+<<-]>>[<<+>>-]<<<<]+>>[-]+[<<]>\0" /* freduce */
"#>[>>]<<-<[<<<<->+>>>-]<-<<-<[>[<+>>>>+<<<-]>[<+>-]<[>>>[<<+>+>-]<[>+<-]<<-]<[>+<-]>>>>>>[<<<<<[<+>>+<-]<[>+<-]>>>>>>-]<<[<<<[<+>>>+<<-]>>[<<+>>-]>-]]<[>>[<+>-]>>>>>[<<<<+>>>>-]<<<]<<[-]+[<<]>\0" /* fadd */
"#>[>>]<<-<[<<<<->+>>>-]<-<<-<[>[<+>>>>+<<<-]>[<+>-]<[>>>[<<->+>-]<[>+<-]<<-]<[>+<-]>>>>>>[<<<<<[<+>>+<-]<[>+<-]>>>>>>-]<<[<<<[<+>>>+<<-]>>[<<+>>-]>-]]<[>>[<+>-]>[>>>>-<<<<-]>>>>[<<<<+>>>>-]<<<]<<[-]+[<<]>\0" /* fsub */
"#>[>>]<[->+>+<<]>[-<+>]+[<<]>\0" /* dup */
"q[#>[>>]<[->+>+<<]>[-<+>]+[<<]>p<+>]<[->]\0" /* cdup (cdp) */
"q[2[1-k+2-]1[q-k[1+2+k-]1[l+1-]]l[1+l-]k[1+2+k-]p<+>]<[->]\0" /* candeq x05 */
"q[-2[1-k+2-]1[q+k[1+2+k-]1[l+1-]]l[1+l-]k[1+2+k-]p<+>]<[->]\0" /* candne x06 */
"q[1[m+1-]2[n+2-]m[1+2+m>[-<]>]<<[q-2-m-[1+m-]<<]>>n[2+n-]p<+>]<[->]\0" /* candle x07 */
"q[1[n+1-]2[m+2-]m[1+2+m>[-<]>]<<[q-1-m-[2+m-]<<]>>n[1+n-]p<+>]<[->]\0" /* candge x08 */
"q[-1[n+1-]2[m+2-]m[1+2+m>[-<]>]<<[q+1-m-[2+m-]<<]>>n[1+n-]p<+>]<[->]\0" /* candlt x09 */
"q[-1[m+1-]2[n+2-]m[1+2+m>[-<]>]<<[q+2-m-[1+m-]<<]>>n[2+n-]p<+>]<[->]\0" /* candgt x0A */
"p+>[<-]<[-q+2[1-k+2-]1[q-k[1+2+k-]1[l+1-]]l[1+l-]k[1+2+k-]p<]>\0" /* coreq x0B */
"p+>[<-]<[-2[1-k+2-]1[q+k[1+2+k-]1[l+1-]]l[1+l-]k[1+2+k-]p<]>\0" /* corne x0C */
"p+>[<-]<[-q+1[m+1-]2[n+2-]m[1+2+m>[-<]>]<<[q-2-m-[1+m-]<<]>>n[2+n-]p<]>\0" /* corle x0D */
"p+>[<-]<[-q+1[n+1-]2[m+2-]m[1+2+m>[-<]>]<<[q-1-m-[2+m-]<<]>>n[1+n-]p<]>\0" /* corge x0E */
"p+>[<-]<[-1[n+1-]2[m+2-]m[1+2+m>[-<]>]<<[q+1-m-[2+m-]<<]>>n[1+n-]p<]>\0" /* corlt x0F */
"p+>[<-]<[-1[m+1-]2[n+2-]m[1+2+m>[-<]>]<<[q+2-m-[1+m-]<<]>>n[2+n-]p<]>\0" /* corgt x10 */
"2[1-k+2-]1[q+k[1+2+k-]1[l+1-]]l[1+l-]k[1+2+k-]q-[+[-]+<<+>]<[->]>\0" /* cxoreq x11 */
"2[1-k+2-]1[q-k[1+2+k-]1[l+1-]]l[1+l-]k[1+2+k-]q[+[-]+<<+>]<[->]>\0" /* cxorne x12 */
"1[m+1-]2[n+2-]m[1+2+m>[-<]>]<<[q+2-m-[1+m-]<<]>>n[2+n-]q-[+[-]+<<+>]<[->]>\0" /* cxorle x13 */
"1[n+1-]2[m+2-]m[1+2+m>[-<]>]<<[q+1-m-[2+m-]<<]>>n[1+n-]q-[+[-]+<<+>]<[->]>\0" /* cxorge x14 */
"1[n+1-]2[m+2-]m[1+2+m>[-<]>]<<[q-1-m-[2+m-]<<]>>n[1+n-]q[+[-]+<<+>]<[->]>\0" /* cxorlt x15 */
"1[m+1-]2[n+2-]m[1+2+m>[-<]>]<<[q-2-m-[1+m-]<<]>>n[2+n-]q[+[-]+<<+>]<[->]>\0" /* cxorgt x16 */
"2[p+*>[>>]+[<<]>2-]p[2+p-]*>[>>]>[-]<<<[<<]>1[p+*>[>>]>+<<<[<<]>1-]p[1+p-]*>[>>]<<[-<<]>\0" /* ots: sto with reversed parameters */
"q[2[p+*>[>>]+[<<]>2-]p[2+p-]*>[>>]>[-]<<<[<<]>1[p+*>[>>]>+<<<[<<]>1-]p[1+p-]*>[>>]<<[-<<]>p<+>]<[->]\0" /* cots => cot */
"#>[>>]<[-]<[-]<<[<<]>\0" /* dsc */
"1[-]2-[p+#>[>>]+<<-<<[<<]>2-]+p[2+p-]#>[>>]<[<+>-]<-[[<<]>1+#>[>>]<+<-]>>+[-<<+>>>>]<<<<[<<]>\0" /* sgt */
"2-[p+#>[>>]+<<-<<[<<]>2-]+p[2+p-]#>[>>]<[-]<[<<]>1[p+#>[>>]<+<[<<]>1-]p[1+p-]#>[>>]>>[-<<+>>>>]<<<<[<<]>\0" /* spt */
"2[-]#>[>>]<<<<[>>[<<+>>-]+<<<<]>>[<2+#>-]+<\0" /* sle */
"1-[p+#>[>>]+<<-<<[<<]>1-]+p[1+p-]#>[>>]<[-]<[<<]>2[p+#>[>>]<+<[<<]>2-]p[2+p-]#>[>>]>>[-<<+>>>>]<<<<[<<]>\0" /* tps */
"q[p+#>[>>]>+<<<[<<]>q-]p[q+p-]#>[>>]+[<<]>\0" /* fps */
"q[-]#>[>>]<<->[<<<[<<]>q+#>[>>]>-]<<<[<<]>\0" /* fpo */
"n++2[m+>-[<<]<[[>+<-]<<]>>2-]m[2+m-]n[-]\0" /* s00 - sgn */
"2[m+2-]k+m[-[-2+m>]<]<[>]>k-2[e+2-]e[2++e-]\0" /* s01 - abs */
"2[c+d+2-]c[n++d[m+>-[<<]<[[>+<-]<<]>>d-]m[d+m-]n[-]d-[e-d-]e[d+e-]d[e++d-]e[2+e-]2-c[2+c-]]\0" /* s02 - sneg */
"1[c+d+1-]d[1+d-]2[d+e+k+2-]k[2+k-]n++c[m+>-[<<]<[[>+<-]<<]>>c-]m[c+m-]n[-]n++d[m+>-[<<]<[[>+<-]<<]>>d-]m[d+m-]n[-]1[m+1-]k+m[-[-1+m>]<]<[>]>k-2[m+2-]k+m[-[-2+m>]<]<[>]>k-1[k+1-]k[2[1+l+2-]l[2+l-]k-]2[-]e[2+e-]1[e+1-]e[1++e-]d[c-d-]c[e+c[-]]e[c+e-]c[1+c-]1[c+d+1-]d[1+d-]d+c-[c>-]>[<1-c>->]<<c[-]\0" /* s03 - sgmul */
"1[c+d+1-]d[1+d-]2[d+e+k+2-]k[2+k-]n++c[m+>-[<<]<[[>+<-]<<]>>c-]m[c+m-]n[-]n++d[m+>-[<<]<[[>+<-]<<]>>d-]m[d+m-]n[-]1[m+1-]k+m[-[-1+m>]<]<[>]>k-2[m+2-]k+m[-[-2+m>]<]<[>]>k-2[n+2-]1[m+>-[>>]<[[>+<-]<+>>>]<<1-]l[1+l-]m[-]n[-]2[-]e[2+e-]1[e+1-]e[1++e-]d[c-d-]c[e+c[-]]e[c+e-]c[1+c-]1[c+d+1-]d[1+d-]d+c-[c>-]>[<1-c>->]<<c[-]\0" /* s04 - sgdiv */
"1[c+d+1-]d[1+d-]2[d+e+k+2-]k[2+k-]n++c[m+>-[<<]<[[>+<-]<<]>>c-]m[c+m-]n[-]n++d[m+>-[<<]<[[>+<-]<<]>>d-]m[d+m-]n[-]1[m+1-]k+m[-[-1+m>]<]<[>]>k-2[m+2-]k+m[-[-2+m>]<]<[>]>k-2[n+2-]1[m+>-[<<]<[[>+<-]<<]>>1-]m[1+2+m-]n[-]2[-]e[2+e-]1[e+1-]e[1++e-]d[c-d-]c[e+c[-]]e[c+e-]c[1+c-]1[c+d+1-]d[1+d-]d+c-[c>-]>[<1-c>->]<<c[-]\0" /* s05 - sgmod */
"q[\0" /* cbs */
"p<+>]<[->]\0" /* cbe */
"1[c+d+1-]d[1+d-]2[d+e+p+2-]e[2+e-]n++c[m+>-[<<]<[[>+<-]<<]>>c-]m[c+m-]n[-]n++d[m+>-[<<]<[[>+<-]<<]>>d-]m[d+m-]n[-]1[m+1-]k+m[-[-1+m>]<]<[>]>k-2[m+2-]k+m[-[-2+m>]<]<[>]>k-e+c[d[d-1[m+d+1-]m[1+m-]d[n+d-]+2[m+2-]m[2+m>[-<]>]<<[d-m-[2+m-]<<]>>n[-]d[d-2[1-d+2-]d[2+d-]1[d+1-]d[1++d-]1+e-d]e[e-1[e+1-]2[1+2-]e[2+e-]2[1-d+2-]d[2+d-]1[d+1-]d[1++d-]e]d]e[e-2[1+e+2-]e[2+e-]1[e+1-]e[1++e-]1+e]c-]e[d[d-2[1+d+2-]d[2+d-]1[d+1-]d[1++d-]e-d]e[1[m+d+1-]m[1+m-]d[n+d-]+2[m+2-]m[2+m>[-<]>]<<[d-m-[2+m-]<<]>>n[-]d[2[1-c+2-]c[2+c-]1[c+1-]c[1++c-]e-d-]e[e-1[e+1-]2[1+2-]e[2+e-]2[1-c+2-]c[2+c-]1[c+1-]c[1++c-]1+e]e]e]2[-]p[2+p-]\0" /* s06 */
"2[e+p+2-]e[2+e-]2[c+d+2-]c[n++d[m+>-[<<]<[[>+<-]<<]>>d-]m[d+m-]n[-]d-[e-d-]e[d+e-]d[e++d-]e[2+e-]2-c[2+c-]]1[c+d+1-]d[1+d-]2[d+e+2-]e[2+e-]n++c[m+>-[<<]<[[>+<-]<<]>>c-]m[c+m-]n[-]n++d[m+>-[<<]<[[>+<-]<<]>>d-]m[d+m-]n[-]1[m+1-]k+m[-[-1+m>]<]<[>]>k-2[m+2-]k+m[-[-2+m>]<]<[>]>k-e+c[d[d-1[m+d+1-]m[1+m-]d[n+d-]+2[m+2-]m[2+m>[-<]>]<<[d-m-[2+m-]<<]>>n[-]d[d-2[1-d+2-]d[2+d-]1[d+1-]d[1++d-]1+e-d]e[e-1[e+1-]2[1+2-]e[2+e-]2[1-d+2-]d[2+d-]1[d+1-]d[1++d-]e]d]e[e-2[1+e+2-]e[2+e-]1[e+1-]e[1++e-]1+e]c-]e[d[d-2[1+d+2-]d[2+d-]1[d+1-]d[1++d-]e-d]e[1[m+d+1-]m[1+m-]d[n+d-]+2[m+2-]m[2+m>[-<]>]<<[d-m-[2+m-]<<]>>n[-]d[2[1-c+2-]c[2+c-]1[c+1-]c[1++c-]e-d-]e[e-1[e+1-]2[1+2-]e[2+e-]2[1-c+2-]c[2+c-]1[c+1-]c[1++c-]1+e]e]e]2[-]p[2+p-]\0" /* s07 */
"#>[>>]<<<[->+>>>+<<<<]>-[-<+>]+>[->+>>>+<<<<]>[<->+]+>>+[<<]>\0" /* dp2 */
"#>[>>]<<-<<+++++++++[>>++++++++++<<-]>[<+>-]<[>>[<+>>>+<<-]>>[<<+>>-]<<<<-]>>[-<<+>>]<[->+>-[>+>>]>[+[-<+>]>+>>]<<<<<<]>[-]>[-]>[-]>[<<<<+>>>>-]<<<<<[>>>+<<<-]>[->+>-[>+>>]>[+[-<+>]>+>>]<<<<<<]>[-]>[-]>[<<<+>>>-]>[<<+>>-]<<<+<<+[<<]>\0" /* axl */
"1[-c+d+1]2[-e+1+2]1[-2+1]n++d[m+>-[<<]<[[>+<-]<<]>>d-]m[d+m-]n[-]n++e[m+>-[<<]<[[>+<-]<<]>>e-]m[e+m-]n[-]k+d[-k-e[-d-c[m+c-]k+m[-[-c+m>]<]<[>]>k-2[m+2-]k+m[-[-2+m>]<]<[>]>k-c[n+c-]2[m+2-]m[2+m>[-<]>]<<[c-m-[2+m-]<<]>>n[-]c[-1+c]2[e+2-]e[2++e-]2+e]d]k[-d+e[-d-1+e]d[-c[m+c-]k+m[-[-c+m>]<]<[>]>k-2[m+2-]k+m[-[-2+m>]<]<[>]>k-c[m+c-]2[n+2-]m[2+m>[-<]>]<<[[-]c+2-m<<]>>n[2+n-]c[-1+c]2[e+2-]e[2++e-]d]k]c[-]\0" /* xgt */
"1[-c+d+1]2[-e+1+2]1[-2+1]n++d[m+>-[<<]<[[>+<-]<<]>>d-]m[d+m-]n[-]n++e[m+>-[<<]<[[>+<-]<<]>>e-]m[e+m-]n[-]k+d[-k-e[-d-c[m+c-]k+m[-[-c+m>]<]<[>]>k-2[m+2-]k+m[-[-2+m>]<]<[>]>k-c[n+c-]2[m+2-]m[2+m>[-<]>]<<[c-m-[2+m-]<<]>>n[-]c[-1+c]2[e+2-]e[2++e-]2+e]d]k[-d+e[-d-1+e]d[-c[m+c-]k+m[-[-c+m>]<]<[>]>k-2[m+2-]k+m[-[-2+m>]<]<[>]>k-c[m+c-]2[n+2-]m[2+m>[-<]>]<<[[-]c+2-m<<]>>n[2+n-]c[-1+c]2[e+2-]e[2++e-]d]k]c[-]1-[e-1-]e[1+e-]\0" /* xle */
