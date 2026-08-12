//回傳n的其中一個因數
ll f(ll x, ll c, ll mod){ return add(mul(x,x,mod),c,mod); }
ll pollard_rho(ll n) {
    ll c = 1, x = 0, y = 0, p = 2, q, t = 0;
    while (t++ % 128 or __gcd(p, n) == 1) {
        if (x == y) c++, y = f(x = 2, c, n);
        if (q = mul(p, abs(x-y), n)) p = q;
        x = f(x, c, n); y = f(f(y, c, n), c, n);
    }
    return __gcd(p, n);
}
/*function<void(int)> fact=[&](int x){
        if(x==1) return;
        if(miller_rabin(x)){
            f.push_back(x);return;}
        int tmp=pollard_rho(x);
        fact(tmp);fact(x/tmp);};
*/