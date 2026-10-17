string K;
int D;
cin >> K >> D;
reverse(all(K)); //從高到低
dp[K.size()][1][0] = 1;
for(int i = K.size() - 1; i >= 0; --i){
    auto &prv = dp[i+1];
    auto &cur = dp[i];
    int x = K[i] - '0';
    for(int a = 0; a <= 9; ++a){ //窮舉這位放什麼
        for(int d = 0; d < D;++d){
            cur[0][(d + a) % D] += prv[0][d]; 
            if(a < x){
                cur[0][(d + a) % D] += prv[1][d];
            }
            if(a == x){
                cur[1][(d + a) % D] += prv[1][d];
            }
        }
    }
}