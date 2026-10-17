// 求子集和 或超集和 -> !(mask & (1 << i))
for(int i = 0; i<(1<<N); ++i)	F[i] = A[i]; //預處理 狀態權重

for(int i = 0;i < N; ++i)//O(N*2^N)
for (int s = 0; s < (1<<N) ; ++s)
	if (s & (1 << i))//0的部分是0
		F[s] += F[s ^ (1 << i)];
	if (!(s & (1 << i)))//1的部分是1
		F[s] += F[s ^ (1 << i)];

//窮舉子集合
for(int s = mask; s ; s = (s-1)&mask;)
//放這個做啥我不會用QAQ

for(int s = 0; s < (1LL<<n); ++s){//O(3^n)
    for(int mask = s; mask; mask = (mask-1) & s){
        F[s] += A[mask];
    }
    F[s] += A[0]; //空集額外處理
}