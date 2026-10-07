#include <bits/stdc++.h>
using namespace std;
#define int long long
#define idonthavegirlfriend ios::sync_with_stdio(0),cin.tie(0);
#define pb push_back
#define yn(a) (a?"Yes\n":"No\n")
struct cmp{
        bool operator()(pair<int,int> a,pair<int,int> b){
        if(a.first==b.first) return a.second>b.second;
        return a.first<b.first;
    }
};
signed main(){
    idonthavegirlfriend
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &c:a)cin>>c;
    vector<pair<pair<int,int>,pair<int,int>>> b;//many val pre nxt
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> q;// many idx
    int cnt=1;
    int idx=0;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            cnt++;
        }
        else{
            b.pb({{cnt,a[i-1]},{idx-1,idx+1}});
            q.push({cnt,idx});
            cnt=1;
            idx++;
        }
    }
    b.pb({{cnt,a.back()},{idx-1,idx+1}});
    q.push({cnt,idx});
    cnt=1;
    idx++;
    int ans=0;
    vector<bool> vis(b.size(),false);
    while(!q.empty()){
        auto [x,id]=q.top();
        q.pop();
        if(vis[id]) continue;
        ans++;
        vis[id]=true;
        auto [pp,pn]=b[id].second;
        if(pp==-1 and pn==b.size()) continue;
        if (pp!=-1) b[pp].second.second=pn;
        if (pn!=b.size()) b[pn].second.first=pp;
        if(pn==b.size() and pp==-1) continue;
        if(pn!=b.size() and pp!=-1){
            if(b[pn].first.second==b[pp].first.second){
                int cnt=b[pn].first.first+b[pp].first.first;
                vis[pn]=true;
                b[pp].first.first=cnt;
                b[pp].second.second=b[pn].second.second;
                if(pn!=b.size()){
                    int pnn=b[pn].second.second;
                    if(pnn!=b.size()){
                        b[pnn].second.first=pp;
                    }
                }
                q.push({cnt,pp});
            }
        }


    }
    cout<<ans;
}
