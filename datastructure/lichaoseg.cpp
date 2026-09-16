//線段樹套上凸包
//我相信我們賽中想得出來
const int inf = numeric_limits<i64>::max()/2;
struct Line {
    // y = ax + b
    i64 a{0}, b{-inf};
    i64 operator()(i64 x) {
        return a * x + b;
    }
};
 
struct Seg{
    int l, r;
    Seg *ls{},*rs{};
    Line f{};
    Seg(int l, int r) : l(l), r(r) {}
    void add(Line g){
        int m = (l+r)/2;
        if (g(m) > f(m)) swap(g, f);
        if(g.b == -inf || r - l == 1) return;
        if(g.a < f.a){
            if(!ls) ls = new Seg(l,m); 
            ls->add(g);
        }else{
            if(!rs) rs = new Seg(m,r);
            rs->add(g);
        }
    }
    i64 qry(i64 x){
        int m = (l+r) / 2;  
        i64 y = f(x);
        if(x <  m && ls) y = max({y,ls->qry(x)});
        if(x >= m && rs) y = max({y,rs->qry(x)});
        return y;
    }
};
auto add = [&](Line g,int ql,int qr){ //新增線段 [ql,qr)
    auto find = [&](auto &&self,Seg * now,int l,int r) -> void {
        if(ql <= l && r <= qr){
            now->add(g);
            return;
        }
        int m = (l+r) / 2;
        if(ql < m) {
            if(!now->ls) now->ls = new Seg(l,m);
            self(self,now->ls,l,m);
        }
        if(qr > m){
            if(!now->rs) now->rs = new Seg(m,r);
            self(self,now->rs,m,r);
        }
    };
    find(find,st,-ninf,ninf);
};
//Seg *st = new Seg(-ninf,ninf); // [l,r)