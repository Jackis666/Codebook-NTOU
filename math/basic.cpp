[a,b] 有包含
(a,b) 沒包含
ll mul(ll x,ll y,ll mod){
	ll ret=x*y-(ll)((long double)x/mod*y)*mod;
	// LL ret=x*y-(LL)((long double)x*y/mod+0.5)*mod;
	return ret<0?ret+mod:ret;
}
ll add(int x,int y,int mod){
    return (x+y)%mod;
}