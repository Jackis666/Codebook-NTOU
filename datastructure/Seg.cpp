#define cl (i << 1)
#define cr (i << 1 | 1)
#define NO_TAG 0
struct SegmentTree {  // 1-base
  int n;
  vector<int> seg, tag;
  SegmentTree(int _n) : n(_n) {  // 空的 SegmentTree
    seg.resize(n * 4), tag.resize(n * 4);
  }
  void push(int i, int l, int r) {
    if (tag[i] != NO_TAG) {
      seg[i] += tag[i];  // update by tag
      if (l != r)
        tag[cl] += tag[i], tag[cr] += tag[i];  // push
      tag[i] = 0;
    }
  }
  void pull(int i, int l, int r) {
    int mid = (l + r) >> 1;
    push(cl, l, mid), push(cr, mid + 1, r);
    seg[i] = max(seg[cl], seg[cr]);  // pull (操作改這)
  }
  void build(int i, int l, int r) {
    if (l == r) {
      seg[i] = arr[l];  // 初始值
      return;
    }
    int mid = (l + r) >> 1;
    build(cl, l, mid), build(cr, mid + 1, r);
    pull(i, l, r);
  }
  void update(int i, int l, int r, int ql, int qr,
              int v) {
    push(i, l, r);
    if (ql <= l && r <= qr) {
      tag[i] += v;
      return;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid) update(cl, l, mid, ql, qr, v);
    if (qr > mid) update(cr, mid + 1, r, ql, qr, v);
    pull(i, l, r);
  }
  int query(int i, int l, int r, int ql, int qr) {
    push(i, l, r);
    if (ql <= l && r <= qr) return seg[i];
    int mid = (l + r) >> 1, ans = -INF;
    if (ql <= mid)  // (操作改這)
      ans = max(ans, query(cl, l, mid, ql, qr));
    if (qr > mid)  // (操作改這)
      ans = max(ans, query(cr, mid + 1, r, ql, qr));
    return ans;
  }
  // 區間 [ql, qr] 加值 v
  void update(int ql, int qr, int v) {
    update(1, 0, n-1, ql, qr, v);
  }
  // 查詢區間 [ql, qr]
  int query(int ql, int qr) {
    return query(1, 0, n-1, ql, qr);
  }
};