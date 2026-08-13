int prime[350000]; ULL phi[5000005];
bool v[5000005];
#define N 5000000
void quick_euler() {
    int cnt = 0;
    for(int i = 2; i <= N; ++i) {
        if(!v[i])	prime[++cnt] = i, phi[i] = i - 1; // 若 i 是質數，φ(i) = i - 1
        for(int j = 1; i * prime[j] <= N && j <= cnt; ++j) {
            v[i * prime[j]] = 1; // 不是質數就篩掉
            if(i % prime[j] == 0){
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else phi[i * prime[j]] = phi[i] * (prime[j] - 1); // 積性函數性質用在這裡
        }
    }
}