#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
const int maxn = 200;
int n = 0;
struct tim{
    int y,m,d,h,i,s;
    void init(string ss){
        char s[maxn];
        int i = 0;
        for(auto cs: ss) s[i++] = cs;
        s[i] = '\0';
        sscanf(s,"%d-%d-%d %d:%d:%d", &y, &m, &d, &h, &i, &s);
    }
} start, stop, dt[maxn];
bool cmp(tim a, tim b){
    if(a.y != b.y) return a.y > b.y;
    if(a.m != b.m) return a.m > b.m;
    if(a.d != b.d) return a.d > b.d;
    if(a.h != b.h) return a.h > b.h;
    if(a.i != b.i) return a.i > b.i;
    if(a.s != b.s) return a.s > b.s;
    return true;
}
long long sec_unix(string s){
    char b[maxn];
    int i=0;
    for(auto c:s) b[i++] = c;
    b[i] = '\0';
    tm tm_;
    tm_.tm_isdst = 0;
    strptime(b, "%Y-%m-%d %H:%M:%S", &tm_);
    return mktime(&tm_);
}
int main(){
    //freopen("../input.txt","r",stdin);
    string suff_s = "-06-30 23:59:60", suff_t = "-12-31 23:59:60", s1,s2, e1,e2;
    vector<int> sx = {1972, 1981, 1982, 1983, 1985, 1992, 1993, 1994, 1997, 2012, 2015},
            tv = {1972, 1973, 1974, 1975, 1976, 1977, 1978, 1979, 1987, 1989, 1990, 1995, 1998, 2005, 2008, 2016};
    for(auto y:sx) dt[n++].init(to_string(y)+suff_s);
    for(auto y:tv) dt[n++].init(to_string(y)+suff_t);
    cin>>s1>>s2>>e1>>e2;
    string s = s1+" "+s2, e = e1+" "+e2;
    start.init(s);stop.init(e);
    long long sec = sec_unix(e) - sec_unix(s);
    for(int i=0;i<n;i++) if(cmp(dt[i], start) && cmp(stop, dt[i]) && !cmp(dt[i], stop)) sec++;
    cout<<sec<<endl;
    return 0;
}
