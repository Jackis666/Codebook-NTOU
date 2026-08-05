int sgn(double x) { return (x > -eps) - (x < eps); }
template<class T>
struct pt{
	T x,y;
	pt(T _x,T _y):x(_x),y(_y){}
	pt():x(0),y(0){}
	pt operator * (T  c){ return pt(x * c, y * c); }
	pt operator / (T  c){ return pt(x / c, y / c); }
	pt operator + (pt a){ return pt(x + a.x, y + a.y); }
	pt operator - (pt a){ return pt(x - a.x, y - a.y); }
	T  operator * (pt a){ return x * a.x + y * a.y; } // 內積
	T  operator ^ (pt a){ return x * a.y - y * a.x; } // 外積
    bool operator < (pt a) const { return x < a.x || (x == a.x && y < a.y); }//按照x排
    bool operator==(const pt<T>& a) const { return x == a.x && y == a.y; }
};
template<class T>
ld abs(pt<T> a) {//返回向量長度
    return sqrt((ld)(a.x * a.x + a.y * a.y));
}
template<class T>
struct Line {//直線
    pt<T> a, b;
    pt<T> dir()const{return b-a;}
};
template<class T>//線段
T ori(pt<T> a, pt<T> b, pt<T> c){ return (b - a) ^ (c - a); }
template<class T>//判斷點是否在線段上
bool PtOnSeg(pt<T> p, Line<T> L) {
    return sgn(ori(L.a, L.b, p)) == 0 and sgn((p - L.a) * (p - L.b)) <= 0;
}
