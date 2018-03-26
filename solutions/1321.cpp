#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000, maxnode = 3000, maxm = 500;
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
    bool solve(vector<int>& v){
        v.clear();
        if(!dfs(0)) return false;
        for(int i=0;i<ansd;i++) v.push_back(ans[i]);
        return true;
    }
} dlx;
int arr[9][9];
int encode(int a, int b, int c){
    return a * 81 + b * 9 + c + 1;
}
void decode(int code, int& a, int& b, int& c){
    code--;
    c = code % 9; code /= 9;
    b = code % 9; code /= 9;
    a = code;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        dlx.init(324);
        for(int i=0;i<9;i++) for(int j=0;j<9;j++) cin>>arr[i][j];
        for(int i=0;i<9;i++) for(int j=0;j<9;j++) for(int v=0;v<9;v++) if(arr[i][j] == 0 || arr[i][j] - 1 == v){
                        vector<int> rr = {encode(0, i, j), encode(1, i, v), encode(2, j, v), encode(3, i / 3 * 3 + j / 3, v)};
                        dlx.addRow(encode(i,j,v), rr);
                    }
        vector<int> ans;
        dlx.solve(ans);
        for(auto aa:ans){
            int i, j, v; decode(aa, i, j, v);
            arr[i][j] = v + 1;
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++) cout<<arr[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
