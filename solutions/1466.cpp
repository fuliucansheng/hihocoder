#include <iostream>
#include <cstring>
using namespace std;
const int maxn = (100000+50)*2;
struct SAM{
    int in[maxn][26],fa[maxn],mx[maxn],sg[maxn],vis[26];
    long long ct[maxn][26];
    int nn,last;
    void init(){
        memset(fa, 0, sizeof(fa));memset(mx, 0, sizeof(mx));
        memset(in, 0, sizeof(in));memset(ct, 0, sizeof(ct));
        memset(sg, 0, sizeof(sg));
        last = 1, nn = 1;
    }
    void build(int x){
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
                while(p&&in[p][x]==q) in[p][x]=nq, p=fa[p];
            }
        }
        last=np;
    }
    void gb(){
        int deg[maxn], topo[maxn], c = 1, f = 1;
        memset(deg, 0, sizeof(deg));memset(topo, 0, sizeof(topo));topo[c++] = 1;
        for(int i=1;i<=nn;i++) for(int j=0;j<26;j++) if(in[i][j]) deg[in[i][j]]++;
        while(c <= nn){
            for(int i=0;i<26;i++) if(in[topo[f]][i] && --deg[in[topo[f]][i]] == 0) topo[c++] = in[topo[f]][i];
            f++;
        }
        for(int k=nn;k>0;k--){
            int ne = topo[k];
            memset(vis, 0, sizeof(vis));
            for(int i=0;i<26;i++) if(in[ne][i]) vis[sg[in[ne][i]]] = 1;
            for(int i=0;i<26;i++) if(vis[i]==0) { sg[ne]=i;break;}
            ct[ne][sg[ne]] = 1;
            for(int i=0;i<26;i++) for(int j=0;j<26;j++) if(in[ne][j]) ct[ne][i] += ct[in[ne][j]][i];
        }
    }
} A,B;
long long count_now(int asg, int bs){
    long long sum = 0;
    for(int i=0;i<26;i++) if(i!=asg) sum += B.ct[bs][i];
    return sum;
}
long long count_pre(int as, int bs){
    long long sum = 0;
    for(int i=0;i<26;i++) sum += A.ct[as][i]*count_now(i, bs);
    return sum;
}
long long count_pnt(int as, int bs){
    return (A.sg[as] != B.sg[bs] && A.ct[as][A.sg[as]] && B.ct[bs][B.sg[bs]] ? 1 : 0);
}
int main(){
    //freopen("../input.txt","r",stdin);
    long long k;
    cin>>k;
    string a,b;
    cin>>a>>b;
    A.init();B.init();
    for(auto c:a) A.build(c-'a');
    for(auto c:b) B.build(c-'a');
    A.gb();B.gb();
    bool status = true;
    string ra = "", rb = "";
    int as = 1, bs = 1;
    if(count_pre(as,bs) >= 0 && count_pre(as,bs) < k) status = false;
    while(status && k > 0){
        long long rn = count_now(A.sg[as], bs);
        if(rn >= k) break; else k -= rn;
        for(int i=0;i<26;i++)
            if(A.in[as][i]){
                long long r = count_pre(A.in[as][i], bs);
                if(r >= 0 && r < k) k -= r;
                else { as = A.in[as][i], ra += (i+'a'); break; }
            }
    }
    while(status && k > 0){
        k -= count_pnt(as, bs);
        if(k == 0) break;
        for(int i=0;i<26;i++)
            if (B.in[bs][i]) {
                long long r = count_now(A.sg[as], B.in[bs][i]);
                if (r < k) k -= r;
                else { bs = B.in[bs][i], rb += (i + 'a');break;}
            }
    }
    if(status) cout<<ra<<endl<<rb<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
