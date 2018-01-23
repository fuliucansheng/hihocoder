#include <iostream>
using namespace std;
int n;
void dfs(int r[], int rz, string pre){
    if(rz == 1) {
        if(pre[pre.size()-1] == '-' || r[0] > (pre[pre.size()-1] - '0')) cout<<pre<<r[0]<<endl;
        return;
    }
    for(int i=0;i<rz;i++){
        int nr[rz-1], nrz = 0;
        for(int j=0;j<rz;j++) if(i!=j) nr[nrz++] = r[j];
        bool s = true;
        for(int j=pre.size()-1;j>=0;j--) {
            if(pre[j] == '-') break;
            if((pre[j]-'0') > r[i]) s = false;
        }
        if(s) {
            dfs(nr, rz-1, pre+to_string(r[i])+"-");
            dfs(nr, rz-1, pre+to_string(r[i]));
        }
    }
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) arr[i] = i+1;
    dfs(arr, n, "");
    return 0;
}
