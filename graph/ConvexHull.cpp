struct node{
    int x,y;
    bool operator<(const node &other) const{
        return (x<other.x) || (x==other.x && y<other.y);
    };
};

struct ConvexHull{
    vector<node> vec;
    int n;
    void init(vector<node> &v){
        vec=v;
        n=v.size();
    }

    int cross(node a,node o,node b){
        return (a.x-o.x)*(b.y-o.y)-(b.x-o.x)*(a.y-o.y);
    }

    vector<int> point;
    vector<int> area;

    void build(){
        point=vector<int>(n+1);
        area=vector<int>(n+1);
        vector<node> up,down;
        int upsum=0;
        int downsum=0;
        for(int i=0;i<n;i++){
            while(up.size()>=2 && cross(up[up.size()-2],up[up.size()-1],vec[i])<=0){
                upsum-=cross(up[up.size()-2],{0,0},up[up.size()-1]);
                up.pop_back();

            }
            up.push_back(vec[i]);
            if(up.size()>1) upsum+=cross(up[up.size()-2],{0,0},up[up.size()-1]);

            while(down.size()>=2 && cross(down[down.size()-2],down[down.size()-1],vec[i])>=0){
                downsum-=cross(down[down.size()-2],{0,0},down[down.size()-1]);
                down.pop_back();
            }
            down.push_back(vec[i]);
            if(down.size()>1) downsum+=cross(down[down.size()-2],{0,0},down[down.size()-1]);

            area[i+1]=abs(upsum-downsum);

            if(i+1==1) point[i+1]=1;
            else point[i+1]=up.size()+down.size()-2;
        }
    }

    double getarea(int p){
        return area[p]/2.0;
    }

    int getnum(int p){
        return point[p];
    }
};