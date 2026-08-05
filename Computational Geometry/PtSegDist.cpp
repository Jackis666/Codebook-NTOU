template<class T>//計算點到線段的距離
ld PtSegDist(pt<T> p, Line<T> l) {
    ld ans = min(abs(p - l.a), abs(p - l.b));
    if (sgn(abs(l.a - l.b)) == 0)  return ans;
    if (sgn((l.a - l.b) * (p - l.b)) < 0) return ans; // case1
    if (sgn((l.b - l.a) * (p - l.a)) < 0) return ans; // case1
    return min(ans, abs(ori(p, l.a, l.b)) / abs(l.a - l.b)); // case2
}