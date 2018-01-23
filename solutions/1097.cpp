#include <iostream>
using namespace std;
const int maxn = 1e3+10;
int arr[maxn][maxn], dis[maxn];
int main(){
    //freopen("../input.txt","r",stdin);
    for(int i=0;i<maxn;i++) dis[i] = INT32_MAX;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>arr[i][j];
    int cost = 0, node = -1, nodecost = INT32_MAX;
    for(int i=0;i<n;i++) dis[i] = arr[0][i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) if(dis[j] >= 0 && (node == -1 || dis[j] < nodecost)) node = j, nodecost = dis[node];
        cost += nodecost;
        dis[node] = -1, nodecost = INT32_MAX;
        for(int j=0;j<n;j++) dis[j] = min(dis[j], arr[node][j]);
    }
    cout<<cost<<endl;
    return 0;
}
