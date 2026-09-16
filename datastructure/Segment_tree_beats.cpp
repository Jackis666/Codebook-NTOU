//阿傑不知道這是啥
struct SegTreeBeat{
    struct node{int mx,smx,cntmx,sum;};   
    #define cl(x) (x<<1)+1
    #define cr(x) (x<<1)+2    
    #define mid ((l+r)>>1)
    vector<node> seg;
    vector<int> tag;
    vector<int> *a;
    int n;
    void pull(int id){
        seg[id].sum=seg[cl(id)].sum+seg[cr(id)].sum;

    if(seg[cl(id)].mx==seg[cr(id)].mx){
        seg[id].mx=seg[cl(id)].mx;
        seg[id].smx=max(seg[cl(id)].smx,seg[cr(id)].smx);
        seg[id].cntmx=seg[cl(id)].cntmx+seg[cr(id)].cntmx;
    }else if(seg[cl(id)].mx>seg[cr(id)].mx){
        seg[id].mx=seg[cl(id)].mx;
        seg[id].smx=max(seg[cl(id)].smx,seg[cr(id)].mx);
        seg[id].cntmx=seg[cl(id)].cntmx;
    }else{
        seg[id].mx=seg[cr(id)].mx;
        seg[id].smx=max(seg[cr(id)].smx,seg[cl(id)].mx);
        seg[id].cntmx=seg[cr(id)].cntmx;
    }}

    void init(vector<int> &v){
        n=v.size();
        seg.resize(n*4+5);
        tag=vector<int>(n*4+5,0);
        a=&v;
    }
    void build(int l,int r,int id=0){
        if(l==r){
            seg[id]={(*a)[l],LLONG_MIN,1,(*a)[l]};
            return;
        }
        build(l,mid,cl(id));
        build(mid+1,r,cr(id));
        pull(id);
    }
    void apply_chmin(int id,int v){
        if(seg[id].mx<=v) return;
        seg[id].sum-=(seg[id].mx-v)*seg[id].cntmx;
        seg[id].mx=v;
    }
    void apply_add(int id,int l,int r,int v){
        seg[id].sum+=v*(r-l+1);
        if(seg[id].smx!=LLONG_MIN) seg[id].smx+=v;
        seg[id].mx+=v;
        tag[id]+=v;
    }
    void push(int id,int l,int r){
        if(l==r) return;
        if(tag[id]){
            apply_add(cl(id),l,mid,tag[id]);
            apply_add(cr(id),mid+1,r,tag[id]);
            tag[id]=0;
        }
        apply_chmin(cl(id),seg[id].mx);
        apply_chmin(cr(id),seg[id].mx);
    }
    void add(int l,int r,int sl,int sr,int v,int id=0){
        if(sl<=l && r<=sr){
            apply_add(id,l,r,v);
            return;
        }
        push(id,l,r);
        if(sl<=mid) add(l,mid,sl,sr,v,cl(id));
        if(mid<sr) add(mid+1,r,sl,sr,v,cr(id));
        pull(id);
    }
    void chmin(int l,int r,int sl,int sr,int v,int id=0){
        if(seg[id].mx<=v) return;
        if(sl<=l && r<=sr && seg[id].smx<v){
            apply_chmin(id,v);
            return;
        }
        push(id,l,r);
        if(sl<=mid) chmin(l,mid,sl,sr,v,cl(id));
        if(mid<sr) chmin(mid+1,r,sl,sr,v,cr(id));
        pull(id);
    }
    int qry(int l,int r,int sl,int sr,int id=0){
        if(sl<=l && r<=sr) return seg[id].sum;
        push(id,l,r);
        int ans=0;
        if(sl<=mid) ans+=qry(l,mid,sl,sr,cl(id));
        if(mid<sr) ans+=qry(mid+1,r,sl,sr,cr(id));
        return ans;
}};