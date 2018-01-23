#include <iostream>
#include <vector>
using namespace std;
#define c(s, m) ((m/2)*arr[s+m/2] - (sum[s+m/2-1] - sum[s-1]) + sum[s+m-1] - sum[s+m/2] - (m-1-m/2)*arr[s+m/2])
int m, n;
int main(){
    //freopen("../input.txt","r",stdin);
    cin>>n>>m;
    vector<int> arr, sum;
    for(int i=1;i<=n;i++){
        int s; cin>>s;
        if(!s) arr.push_back(i);
    }
    int az = arr.size();
    if(az < m) return cout<<-1<<endl, 0;
    for(int i=0;i<az;i++) arr.push_back(arr[i] + n);
    for(int i=0;i<arr.size();i++) sum.push_back((i > 0 ? sum[i-1] : 0) + arr[i]);
    int rs = INT32_MAX;
    for(int i=0;i<az;i++) rs = min(rs, c(i, m));
    cout<<rs<<endl;
    return 0;
}

