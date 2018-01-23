#include <iostream>
#include <map>
#include <set>
#include <cstring>
using namespace std;
const int N = 101;
map<int,set<int>> dict;
int values[N],n,m,l,r;;
int dp[N][N];
void dict2tree(int currnode, int fathernode = 0){
    for(auto ch:dict[currnode]){
        if(ch == fathernode) dict[currnode].erase(ch);
        else dict2tree(ch, currnode);
    }
}
void solve(int currnode){
    for(auto ch:dict[currnode]) solve(ch);
    for(int i=1;i<=m;i++) dp[currnode][i] = values[currnode];
    for(auto ch:dict[currnode])
        for(int i=m;i>0;i--){
            for(int k=1;k<i;k++) dp[currnode][i] = max(dp[currnode][i],dp[currnode][i-k]+dp[ch][k]);
        }
}
int main(){
    //freopen("../input.txt","r",stdin);
    cin>>n>>m;
    memset(values, 0, sizeof(values));
    memset(dp, 0, sizeof(dp));
    for(int i=1;i<=n;i++) cin>>values[i];
    for(int i=0;i<n-1;i++) cin>>l>>r,dict[l].insert(r),dict[r].insert(l);
    dict2tree(1);
    solve(1);
    cout<<dp[1][m]<<endl;
    return 0;
}
