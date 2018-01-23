#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e5+10;
int arr[maxn],n,k;
bool judge(int t){
    int hi_score = 0, ho_score = 0, ho_water = 0;
    for(int i=0;i<n;i++){
        ho_water += t;
        if(ho_water <= arr[i]) hi_score++, ho_water = 0;
        else ho_score++, ho_water -= arr[i];
    }
    return ho_score > hi_score;
}
int search(){
    int l = 0, r = k+1;
    while(r - l > 1){
        if(judge((l+r)/2)) r = (l+r)/2;
        else l = (l+r)/2;
    }
    if(l == r) return l;
    else return judge(l) ? l : r;
}
int main(){
    //freopen("../input.txt","r",stdin);
    memset(arr, 0, sizeof(arr));
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<search()<<endl;
    return 0;
}
