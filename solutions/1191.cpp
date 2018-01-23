#include <iostream>
#include <set>
#include <cstring>
using namespace std;
#define d(p) dp[abs(p.first)+1][abs(p.second)+1]
typedef long long ll;
typedef pair<int,int> ps;
const int maxn = 105, mod = 1000000007;
ll dp[maxn][maxn];
int main(){
    //freopen("../input.txt","r",stdin);
    int m, n, i, j; memset(dp, 0, sizeof(dp));
    for(int a=1;a<maxn;a++)
        for(int b=1;b<maxn;b++){
            dp[a][b] = (a == 1 && b == 1 ? 1 : (a == 1 ? dp[a][b - 1] : (b == 1 ? dp[a - 1][b] : dp[a - 1][b] + dp[a][b - 1])));
            dp[a][b] %= mod;
        }
    while(cin>>n>>m>>i>>j){
        ll rs = 0;
        set<ps> rec;
        for(int a=1;a<=n;a++) rec.insert(ps(a-i, 1-j)), rec.insert(ps(a-i, m-j));
        for(int b=1;b<=m;b++) rec.insert(ps(1-i, b-j)), rec.insert(ps(n-i, b-j));
        for(auto r:rec) rs += d(r), rs %= mod;
        cout<<rs<<endl;
    }
    return 0;
}

