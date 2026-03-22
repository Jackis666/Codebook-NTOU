//歐拉路徑(無向圖)兩個奇數點或者全偶點
vector<int> anse;//邊
vector<int> ansp;//點
vector<bool> vis(m,false);
function<void(int)> dfs=[&](int u){
    while(!mp[u].empty()){
        auto [x,e]=mp[u].back();
        mp[u].pop_back();
        if(vis[e]){
             continue;
        }
        vis[e]=true;
         dfs(x);

        anse.pb(e);
    }
    ansp.pb(u);

};
//有向圖跟歐拉迴路還在找