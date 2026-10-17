int sgn(double x) { return (x > -eps) - (x < eps); }
template<class T>
struct pt{
	T x,y;
	pt(T _x,T _y):x(_x),y(_y){}
	pt():x(0),y(0){}
	pt operator*(T c) const { return pt(x*c,y*c); }
    pt operator/(T c) const { return pt(x/c,y/c); }
    pt operator+(const pt& a) const { return pt(x+a.x,y+a.y); }
    pt operator-(const pt& a) const { return pt(x-a.x,y-a.y); }
	T  operator * (const pt& a)const{ return x * a.x + y * a.y; } // 內積
	T  operator ^ (const pt& a)const{ return x * a.y - y * a.x; } // 外積
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
ld norm2(const Pt &a) {
  return a*a; }
ld norm(const Pt &a) {
  return sqrt(norm2(a)); }
Pt perp(const Pt &a) {
  return Pt(-a.y, a.x); }
Pt rotate(const Pt &a, ld ang) {
  return Pt(a.x*cos(ang)-a.y*sin(ang), a.x*sin(ang)+a.y*cos(ang)); }
