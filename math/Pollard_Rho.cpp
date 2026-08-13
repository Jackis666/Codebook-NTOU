//回傳n的其中一個因數
// does not work when n is prime  O(n^(1/4))
#define LL __int128
LL f(LL x, LL c, LL mod){ return add(mul(x,x,mod),c,mod); }
LL pollard_rho(LL n) {
    LL c = 1, x = 0, y = 0, p = 2, q, t = 0;
    while (t++ % 128 or gcd(p, n) == 1) {
        if (x == y) c++, y = f(x = 2, c, n);
        if (q = mul(p, abs(x-y), n)) p = q;
        x = f(x, c, n); y = f(f(y, c, n), c, n);
    }
    return gcd(p, n);
}
/*function<void(int)> fact=[&](int x){
        if(x==1) return;
        if(miller_rabin(x)){
            f.push_back(x);return;}
        int tmp=pollard_rho(x);
        fact(tmp);fact(x/tmp);};
*/