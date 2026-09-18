	// gcd(a, n) = 1, 算 a^x == b (mod n)
ll BSGS(ll a, ll b, ll n) {
    a %= n, b %= n;
    if (b == 1) return 0;    // a^0 = 1
    ll m = (ll)sqrt(n) + 1;  // 保險一點
    map<ll, ll> mp;
 
    // 拆成 a^{i * m} == b * a^j (mod n)
    ll baby = b;
    for (ll j = 0; j <= m; j++) {
        mp[baby] = j;
        baby = baby * a % n;
    }
 
    ll step = fpow(a, m, n);
    ll giant = step;
    for (ll i = 1; i <= m; i++) {  // 計算 (a^m)^i
        if (mp.count(giant)) {
            ll j = mp[giant], res = i * m - j;
            if (res >= 0) return res;
        }
        giant = giant * step % n;
    }
 
    return -1;
}