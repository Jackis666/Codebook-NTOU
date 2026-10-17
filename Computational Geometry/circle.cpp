struct Cir {
    pt o;
    ld r;
    Cir(pt _o=pt(),ld _r=-1):o(_o),r(_r){}
    bool inside(pt p) const{
        return r>=0 && norm(p-o)<=r+eps;
    }
};
bool disjunct(const Cir &a, const Cir &b) { //  分開 || 外切 -> 1
    return sgn(abs(a.o - b.o) - a.r - b.r) >= 0;
}
bool contain(const Cir &a, const Cir &b) {
    return sgn(a.r - b.r - abs(a.o - b.o)) >= 0;
}