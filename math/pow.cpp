int ksm(int x, int y) {
    int ans = 1;              
    while (y) {             
        if (y & 1)
            ans = ans * x;   
        x = x * x;           
        y >>= 1;            
    }
    return ans;
}

// 矩陣乘法
vector<vector<int>> mul(const vector<vector<int>> &A,
                        const vector<vector<int>> &B) {
    if (A.empty() || B.empty() || A[0].empty() || B[0].empty()) { return {};}
    int m = A.size();
    int k = A[0].size();
    int n = B[0].size();
    vector<vector<int>> C(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
    for (int p = 0; p < k; p++) if (A[i][p]) {
    for (int j = 0; j < n; j++) {
    C[i][j] = (C[i][j] + 1LL * A[i][p] * B[p][j])%MOD;
}}}
    return C;
}

// 矩陣快速冪
vector<vector<int>> ksm(vector<vector<int>> base, int exp) {
    int n = base.size();
    vector<vector<int>> res(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) res[i][i] = 1;

    while (exp > 0) {
        if (exp & 1) res = mul(res, base);
        base = mul(base, base);
        exp >>= 1;
    }
    return res;
}
