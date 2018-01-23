#include <iostream>
#include <algorithm>
using namespace std;
int t,arr[4];
//t: 0~+ 1~- 2~x 3~/ 4~r- 5~r/
double cal(int t, double p, double n){
    if(t == 0) return p+n;
    if(t == 1) return p-n;
    if(t == 2) return p*n;
    if(t == 3) return p/n;
    if(t == 4) return n-p;
    return n/p;
}
bool is_valid(int idx[], int i, int j, int k){
    double ab = cal(i, arr[idx[0]], arr[idx[1]]);
    double abc = cal(j, ab, arr[idx[2]]);
    double abcd = cal(k, abc, arr[idx[3]]);
    if(abs(abcd-24.0)<1e-2) return true;
    ab = cal(i, arr[idx[0]], arr[idx[1]]);
    double cd = cal(k, arr[idx[2]], arr[idx[3]]);
    abcd = cal(j, ab, cd);
    if(abs(abcd-24.0)<1e-2) return true;
    return false;
}
int main(){
    //freopen("../input.txt","r",stdin);
    cin>>t;
    while(t--){
        cin>>arr[0]>>arr[1]>>arr[2]>>arr[3];
        int idx[4] = {0,1,2,3};
        bool status = false;
        do{
            for(int i=0;i<6;i++) for(int j=0;j<6;j++) for(int k=0;k<6;k++) if(is_valid(idx,i,j,k)) status = true;
        }while(next_permutation(idx,idx+4));
        if(status) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
