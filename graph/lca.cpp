//圖要是1-based的 而且要是樹 
 int lg=20;
vector<vector<int>> father(n+1,vector<int>(lg+1,0));
vector<vector<int>> dis(n+1,vector<int>(lg+1,0));
vector<int> dep(n+1,0);
vector<int> in(n+1,0),out(n+1,1e18);
int tim=1;
function<void(int,int,int)> dfs=[&](int x,int f,int len){
    father[x][0]=f;
    in[x]=tim++;
    dep[x]=len;
    for(auto [y,w]:mp[x]){
        if(y==f) continue;
        dis[y][0]=w;
        dfs(y,x,len+1);
    }
    out[x]=tim++;
};
auto isfather=[&](int x,int y){// x是否是y的祖先
    return in[x]<=in[y] and out[x]>=out[y];
};
auto getlca=[&](int x,int y){//找x和y的最近祖先
    if(isfather(x,y)) return x;
    if(isfather(y,x)) return y;
    for(int i=lg;i>=0;i--){
        if(!isfather(father[x][i],y)){
            x=father[x][i];
        }
    }
    return father[x][0];
};
auto gtwlca=[&](int x,int y or k){// 取x到y的路徑上的最大值(也可以改成找x的第y的祖先)
    int k=dep[x]-dep[y];
    int ans=0;
    int cc=lg;
    while(k){
        if((1<<cc)<=k){
            ans=max(ans,dis[x][cc]);
            x=father[x][cc];
            k-=(1<<cc);
        }
        cc--;
    }
    return ans;
};
dfs(1,0,0);