/* minimum enclosing circle */
int n;
pt p[ MAXN ];
const Cir circumcircle(pt a,pt b,pt c){
  Cir cir;
  double fa,fb,fc,fd,fe,ff,dx,dy,dd;
  if( iszero( ( b - a ) ^ ( c - a ) ) ){
    if( ( ( b - a ) * ( c - a ) ) <= 0 )
      return Cir((b+c)/2,norm(b-c)/2);
    if( ( ( c - b ) * ( a - b ) ) <= 0 )
      return Cir((c+a)/2,norm(c-a)/2);
    if( ( ( a - c ) * ( b - c ) ) <= 0 )
      return Cir((a+b)/2,norm(a-b)/2);
  }else{
    fa=2*(a.x-b.x);
    fb=2*(a.y-b.y);
    fc=norm2(a)-norm2(b);
    fd=2*(a.x-c.x);
    fe=2*(a.y-c.y);
    ff=norm2(a)-norm2(c);
    dx=fc*fe-ff*fb;
    dy=fa*ff-fd*fc;
    dd=fa*fe-fd*fb;
    cir.o=pt(dx/dd,dy/dd);
    cir.r=norm(a-cir.o);
    return cir;
  }
}
inline Cir mec(int fixed,int num){
  int i;
  Cir cir;
  if(fixed==3) return circumcircle(p[0],p[1],p[2]);
  cir=circumcircle(p[0],p[0],p[1]);
  for(i=fixed;i<num;i++) {
    if(cir.inside(p[i])) continue;
    swap(p[i],p[fixed]);
    cir=mec(fixed+1,i+1);
  }
  return cir;
}
inline double min_radius() {
  if(n<=1) return 0.0;
  if(n==2) return norm(p[0]-p[1])/2;
  random_device rd;
  mt19937_64 rng(rd());
  shuffle(p,p+n,rng);
  return mec(0,n).r;
}