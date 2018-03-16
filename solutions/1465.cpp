#include <bits/stdc++.h>
using namespace std;
const long long maxn = (100000+50)<<1;
int in[maxn][26], fa[maxn], mx[maxn], ct[maxn], rec[maxn];
int nn,last,srh,len;
void build(int x){
    int p=last,np=++nn;
    mx[np]=mx[p]+1, ct[np]=1;
    while(p&&!in[p][x]) in[p][x]=np,p=fa[p];
    if(!p) fa[np] = 1;
    else{
        int q=in[p][x];
        if(mx[q]==mx[p]+1) fa[np]=q;
        else{
            int nq=++nn;mx[nq]=mx[p]+1;
            fa[nq]=fa[q];
            fa[np]=fa[q]=nq;
            for(int i=0;i<26;i++) in[nq][i]=in[q][i];
            while(p&&in[p][x]==q) in[p][x]=nq, p=fa[p];
        }
    }
    last=np;
}
vector<int> graph[maxn];
void dfs(int g){
    for(auto gg:graph[g]){
        dfs(gg);
        ct[g] += ct[gg];
    }
}
int search(int x, int k){
    int p=srh;
    while(p&&!in[p][x]) p = fa[p], len = min(len, mx[p]);
    if(!p) p = 1;
    if(in[p][x]) len = min(len, mx[p]) + 1, p = in[p][x];
    while(mx[fa[p]]>=k) p = fa[p],len = min(len, mx[p]);
    srh = p;
    if(len >= k && rec[p] == 0) {
        rec[p] = 1;
        return ct[p];
    }
    else return 0;
}
int main(){
    //freopen("../input.txt","r",stdin);
    memset(fa, 0, sizeof(fa));memset(mx, 0, sizeof(mx));
    memset(in, 0, sizeof(in));memset(ct, 0, sizeof(ct));
    string s,ss;
    cin>>s;
    int n;
    cin>>n;
    last = 1, nn = 1;
    for(auto c:s) build(c-'a');
    for(int i=1;i<=nn;i++) graph[fa[i]].push_back(i);
    dfs(1);
    for(int i=0;i<n;i++){
        memset(rec, 0, sizeof(rec));
        cin>>ss;
        int k = ss.size(), res = 0;
        srh = 1, len = 0;
        ss += ss.substr(0, ss.size()-1);
        for(auto c:ss) res += search(c-'a', k);
        cout<<res<<endl;
    }
    return 0;
}
