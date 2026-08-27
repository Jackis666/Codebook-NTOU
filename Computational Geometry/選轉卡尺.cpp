double RotatingCalipers(vector<Pt> &v){ //逆時針
    int n=v.size();
    double dist=0;
    if(n==1) return 0;
    if(n==2) return dis(v[0]-v[1]);
    for(int i=0,j=2;i<n;i++){
        Pt a=v[i],b=v[(i+1)%n];
        while(cross(v[j],a,b)<cross(v[(j+1)%n],a,b))
            j=(j+1)%n;
        dist=max(dist,dis(v[j]-a));
        dist=max(dist,dis(v[j]-b));
    }
    return dist;
}