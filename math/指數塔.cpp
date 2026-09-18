ll mod(ll x, ll m) {
    return x >= m ? (x % m) + m : x;
}
ll solve(int idx, ll m) {
    if (m == 1) return 1;                // 模數降為 1
    if (idx == n) return mod(a[idx], m); // 已經到達塔頂
    ll nxt = solve(idx + 1, phi[m]);
    return fpow(a[idx], nxt, m); // 快速冪計算當前層
}