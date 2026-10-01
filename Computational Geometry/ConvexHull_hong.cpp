struct ConvexHull{
    vector<Pt> vec;
    int n;
    void init(vector<Pt> &v){
        vec=v;
        n=v.size();
    }
    int cross(Pt o,Pt a,Pt b){return (a-o)^(b-o);}
    vector<int> point;
    vector<int> area;
    vector<Pt> up,down;
    void build(){
        up.clear();down.clear();
        point=vector<int>(n+1);
        area=vector<int>(n+1);
        int upsum=0;
        int downsum=0;
        for(int i=0;i<n;i++){
            while(up.size()>=2 && 
                  cross(up[up.size()-1],
                        up[up.size()-2],vec[i])<=0){
                upsum-=cross({0,0},up[up.size()-2],
                             up[up.size()-1]);
                up.pop_back();
            }
            up.push_back(vec[i]);
            if(up.size()>1) 
                upsum+=cross({0,0},up[up.size()-2],
                             up[up.size()-1]);

            while(down.size()>=2 && 
                  cross(down[down.size()-1],
                        down[down.size()-2],vec[i])>=0){
                downsum-=cross({0,0},down[down.size()-2],
                               down[down.size()-1]);
                down.pop_back();
            }
            down.push_back(vec[i]);
            if(down.size()>1)
                downsum+=cross({0,0},down[down.size()-2],
                               down[down.size()-1]);

            area[i+1]=abs(upsum-downsum);

            if(i+1==1) point[i+1]=1;
            else point[i+1]=up.size()+down.size()-2;
    }}
    double getarea(int p){
        return area[p]/2.0;
    }
    int getnum(int p){
        return point[p];
    }
    vector<Pt> getall(){
        vector<Pt> ans;
        for(int i=0;i<down.size();i++)
            ans.push_back(down[i]);
        for(int i=up.size()-2;i>=1;i--)
            ans.push_back(up[i]);
        return ans;
    }
};