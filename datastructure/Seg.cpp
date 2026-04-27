struct Seg{
    #define cl(x) (x<<1)
    #define cr(x) (x<<1)+1
    int _n;
    vector<int> f;
    vector<int> arr;
    int base;
    Seg(int n):_n(n),f(4*n){}
    Seg(vector<int> a,int b){//
        _n=a.size();
        f.resize(4*_n+1,0);
        arr.resize(_n);
        for(int i=0;i<_n;i++){
            arr[i]=a[i];
        }
        base=b;
        build(1,base,_n-1+base);

    }
    void build(int id,int l,int r){
        if(l==r){
            f[id]=arr[l];
            return ;
        }
        int mid=(l+r)>>1;
        build(cl(id),l,mid);
        build(cr(id),mid+1,r);
        pull(id);
    }
    void pull(int id){
        f[id]=min(f[cl(id)],f[cr(id)]);
    }
    void update(int id,int l,int r,int x,int v){
        if(l==r){
            f[id]=v;
            return;
        }
        int mid=(l+r)>>1;
        if(x<=mid) update(cl(id),l,mid,x,v);
        if(mid<x) update(cr(id),mid+1,r,x,v);
        pull(id);
    }
    int query(int id,int l,int r,int sl,int sr){
        if(sl<=l and sr>=r){
            return f[id];
        }
        int mid=(l+r)>>1;
        int res=1e18;
        int ll=1e18;int rr=1e18;
        if(sl<=mid){
            ll=query(cl(id),l,mid,sl,sr);
        }
        if(sr>mid){
            rr=query(cr(id),mid+1,r,sl,sr);
        }
        res=min(ll,rr);
        return res;
    }
};