struct Info {
    int sum;
    Info(int v = 0) : sum(v) {}
    /*
    int mx;
    Info(int v = LLONG_MIN) : mx(v) {}*/ 
};
Info merge(const Info &a, const Info &b) {
    return Info(a.sum + b.sum);
    //return Info(max(a.mx, b.mx));
}
template<class Info>
struct SegmentTree {
    inline int cl(int x) { return x << 1; }
    inline int cr(int x) { return (x << 1) | 1; }
    int n;
    vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) { init(n_, v_); }
    template<class T>
    SegmentTree(vector<T> init_) { init(init_); }

    void init(int n_, Info v_ = Info()) { init(vector<Info>(n_, v_)); }
    template<class T>
    void init(vector<T> init_) {
        n = init_.size();
        info.assign(4 << __lg(n), Info());
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) >> 1;
            build(cl(p), l, m);
            build(cr(p), m, r);
            pull(p);
        };
        build(1, 0, n);
    }

    void pull(int p) { info[p] = merge(info[cl(p)], info[cr(p)]); }

    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) >> 1;
        if (x < m) modify(cl(p), l, m, x, v);
        else modify(cr(p), m, r, x, v);
        pull(p);
    }
    void modify(int p, const Info &v) { modify(1, 0, n, p, v); }//單點更新

    Info rangeQuery(int p, int l, int r, int x, int y) {//區間查詢[l,r)
        if (l >= y || r <= x) return Info();
        if (l >= x && r <= y) return info[p];
        int m = (l + r) >> 1;
        return merge(rangeQuery(cl(p), l, m, x, y), rangeQuery(cr(p), m, r, x, y));
    }
    Info rangeQuery(int l, int r) { return rangeQuery(1, 0, n, l, r); }

    template<class F>//找符合條件的最左邊或最右邊
    int findFirst(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) return -1;
        if (l >= x && r <= y && !pred(info[p])) return -1;
        if (r - l == 1) return l;
        int m = (l + r) >> 1;
        int res = findFirst(cl(p), l, m, x, y, pred);
        if (res == -1) res = findFirst(cr(p), m, r, x, y, pred);
        return res;
    }
    template<class F>
    int findFirst(int l, int r, F &&pred) { return findFirst(1, 0, n, l, r, pred); }

    template<class F>
    int findLast(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) return -1;
        if (l >= x && r <= y && !pred(info[p])) return -1;
        if (r - l == 1) return l;
        int m = (l + r) >> 1;
        int res = findLast(cr(p), m, r, x, y, pred);
        if (res == -1) res = findLast(cl(p), l, m, x, y, pred);
        return res;
    }
    template<class F>
    int findLast(int l, int r, F &&pred) { return findLast(1, 0, n, l, r, pred); }
};
vector<int> a={1,2,3,4,5};
SegmentTree<Info> st(a);
st.modify(1,12);
cout<<st.rangeQuery(1,2).sum;
//cout<<st.rangeQuery(0,5).mx;
int pos = st.findLast(0, 5, [&](const Info &x) {return x.sum > 0;});//找sum大於0的最右邊
