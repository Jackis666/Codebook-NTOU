//歐拉函數 phi(n) 是指<=n中與n互質的數的個數
int _phi(int n) {  // O(sqrtN)
  int res = n, a = n;
  for (int i = 2; i * i <= a; i++) {
    if (a % i == 0) {
      res = res / i * (i - 1);
      while (a % i == 0) a /= i;
    }
  }
  if (a > 1) res = res / a * (a - 1);
  return res;
}

int phi[MXN];  // 建表 最大 1e7
void phi_table(int n) {
  phi[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (phi[i]) continue;
    for (int j = i; j <= n; j += i) {
      if (phi[j] == 0) phi[j] = j;
      phi[j] = phi[j] / i * (i - 1);
    }
  }
}

int prime[350000]; ll phi[5000005];
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