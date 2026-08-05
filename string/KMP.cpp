int failure[MXN];
vector<int> KMP(vector<int>& t, vector<int>& p){
    vector<int> ret;
    if (p.size() > t.size()) return {};
    for (int i=1, j=failure[0]=-1; i<p.size(); ++i){
        while (j >= 0 && p[j+1] != p[i])
            j = failure[j];
        if (p[j+1] == p[i]) j++;
        failure[i] = j;
    }
    for (int i=0, j=-1; i<t.size(); ++i){
        while (j >= 0 && p[j+1] != t[i])
            j = failure[j];
        if (p[j+1] == t[i]) j++;
        if (j == p.size()-1){
            ret.push_back( i - p.size() + 1 );
            j = failure[j];
    }}
    return ret;
}
/*
vector<int> prefunc(const string& s){
	int n = s.size();
	vector<int> pi(n);
	for(int i=1,j=0;i<n;++i){
		j = pi[i-1];
		while(j && s[j] != s[i]) j = pi[j-1]; //往下找藍框
		if(s[j] == s[i]) ++j; //相等會多一格
		pi[i] = j;
	}
	return pi;
}*/