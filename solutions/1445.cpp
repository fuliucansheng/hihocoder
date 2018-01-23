#include <iostream>
#include <cstring>
using namespace std;
const int maxn = (1000000+50)<<1;
int in[maxn][26],fa[maxn],mx[maxn];
int nn,last;
int build(int x){
    int p=last,np=++nn;
    mx[np]=mx[p]+1;
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
            while(p&&in[p][x]==q) in[p][x]=nq,p=fa[p];
        }
    }
    last=np;
    return mx[np]-mx[fa[np]];
}
int main(){
    //freopen("../input.txt","r",stdin);
    string s;
    cin>>s;
    memset(fa, 0, sizeof(fa));memset(mx, 0, sizeof(mx));memset(in, 0, sizeof(in));
    last = 1, nn = 1;
    long long res = 0;
    for(int i=0;i<s.size();i++) res += build(s[i]-'a');
    cout<<res<<endl;
    return 0;
}
