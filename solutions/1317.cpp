#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
vector<int> r[maxn], c[maxn];
bool vr[maxn], vc[maxn];
int m, n;
bool dfs(int col){
    if(col == m + 1) return true;
    for(auto rr:c[col]) if(!vr[rr]) {
            stack<int> sr, sc;
            for(auto cc:r[rr]) {
                if(!vc[cc]) sc.push(cc), vc[cc] = true;
                for(auto rd:c[cc]) if(!vr[rd]) sr.push(rd), vr[rd] = true;
            }
            int nc = col + 1;
            while(vc[nc]) nc++;
            bool rs = dfs(nc);
            if(rs) return true;
            while(!sr.empty()) vr[sr.top()] = false, sr.pop();
            while(!sc.empty()) vc[sc.top()] = false, sc.pop();
        }
    return false;
}
int main(){
    //freopen("../input.txt","r",stdin);
    int t; cin>>t;
    while(t--){
        memset(vr, 0, sizeof(vr)); memset(vc, 0, sizeof(vc));
        for(int i=0;i<maxn;i++) r[i].clear(), c[i].clear();
        cin>>n>>m;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
                int num; cin>>num;
                if(num) r[i].push_back(j), c[j].push_back(i);
            }
        bool rs = dfs(1);
        cout<<(rs ? "Yes" : "No")<<endl;
    }
    return 0;
}


// DLX
#include <bits/stdc++.h>
using namespace std;
const int maxn = 101, maxnode = 10010, maxm = 101;
struct DLX{
    int S[maxm], row[maxnode], col[maxnode], n, sz;
    int L[maxnode], R[maxnode], U[maxnode], D[maxnode];
    int ansd, ans[maxn];
    void init(int nn){
        n = nn;
        for(int i=0;i<=n;i++) U[i] = D[i] = i, L[i] = i - 1, R[i] = i + 1;
        R[n] = 0, L[0] = n, sz = n + 1; memset(S, 0, sizeof(S));
    }
    void addRow(int r, vector<int> columns){
        int first = sz;
        for(auto c:columns){
            L[sz] = sz - 1, R[sz] = sz + 1, D[sz] = c, U[sz] = U[c];
            D[U[c]] = sz; U[c] = sz;
            row[sz] = r, col[sz] = c;
            S[c]++, sz++;
        }
        R[sz-1] = first, L[first] = sz - 1;
    }
    void remove(int c){
        L[R[c]] = L[c], R[L[c]] = R[c];
        for(int i=D[c];i!=c;i=D[i]) for(int j=R[i];j!=i;j=R[j]) {
                U[D[j]] = U[j], D[U[j]] = D[j], --S[col[j]];
            }
    }
    void restore(int c){
        for(int i=U[c];i!=c;i=U[i]) for(int j=L[i];j!=i;j=L[j]){
                ++S[col[j]], U[D[j]] = j, D[U[j]] = j;
            }
        R[L[c]] = L[R[c]] = c;
    }
    bool dfs(int d){
        if(R[0] == 0) return ansd = d, true;
        int c = R[0];
        for(int i=R[0];i!=0;i=R[i]) if(S[i] < S[c]) c = i;
        remove(c);
        for(int i=D[c];i!=c;i=D[i]){
            ans[d] = row[i];
            for(int j=R[i];j!=i;j=R[j]) remove(col[j]);
            if(dfs(d+1)) return true;
            for(int j=L[i];j!=i;j=L[j]) restore(col[j]);
        }
        restore(c);
        return false;
    }
} dlx;
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        int n, m; cin>>n>>m;
        dlx.init(m);
        for(int i=0;i<n;i++){
            vector<int> rr;
            for(int j=0, a;j<m;j++){
                cin>>a;
                if(a) rr.push_back(j + 1);
            }
            dlx.addRow(i, rr);
        }
        cout<<(dlx.dfs(0) ? "Yes" : "No")<<endl;
    }
    return 0;
}
