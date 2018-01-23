#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = (1000000+50)<<1;
int in[maxn][26],fa[maxn],mx[maxn],ct[maxn],rs[maxn];
int nn,last;
void build(int x){
    int p=last,np=++nn;
    mx[np]=mx[p]+1;ct[np]=1;
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
vector<int> tree[maxn];
void dfs(int s){
    for(auto c:tree[s]) { dfs(c);ct[s] += ct[c]; }
}
int main(){
    //freopen("../input.txt","r",stdin);
    string s;
    cin>>s;
    memset(fa, 0, sizeof(fa));memset(mx, 0, sizeof(mx));
    memset(in, 0, sizeof(in));memset(ct, 0, sizeof(ct));
    memset(rs, 0, sizeof(rs));
    last = 1, nn = 1;
    for(int i=0;i<s.size();i++) build(s[i]-'a');
    for(int i=1;i<=nn;i++) tree[fa[i]].push_back(i);
    dfs(1);
    for(int i=1;i<=nn;i++) rs[mx[i]] = max(ct[i], rs[mx[i]]);
    for(int i=s.size()-1;i>0;i--)  rs[i] = max(rs[i], rs[i+1]);
    for(int i=1;i<=s.size();i++) cout<<rs[i]<<endl;
    return 0;
}
