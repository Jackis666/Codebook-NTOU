// n < 4,759,123,141        3 :  2, 7, 61
// n < 1,122,004,669,633    4 :  2, 13, 23, 1662803
// n < 3,474,749,660,383          6 :  pirmes <= 13
// n < 2^64                       7 :
// 2, 325, 9375, 28178, 450775, 9780504, 1795265022
// Make sure testing integer is in range [2, n−2] if
// you want to use magic.
ll magic[]={};
bool witness(ll a,ll n,ll u,int t){
	if(!a) return 0;
	ll x=mypow(a,u,n);
	for(int i=0;i<t;i++) {
		ll nx=mul(x,x,n);
		if(nx==1&&x!=1&&x!=n-1) return 1;
		x=nx;
	}
	return x!=1;
}
bool miller_rabin(ll n) {
	int s=(7);
	// iterate s times of witness on n
	if(n<2) return 0;
	if(!(n&1)) return n == 2;
	ll u=n-1; int t=0;
	// n-1 = u*2^t
	while(!(u&1)) u>>=1, t++;
	while(s--){
		ll a=magic[s]%n;
		if(witness(a,n,u,t)) return 0;
	}
	return 1;
}