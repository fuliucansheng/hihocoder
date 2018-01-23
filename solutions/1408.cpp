#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    //freopen("../input.txt","r",stdin);
    int arr[4], h = -1, m = -1;
    cin>>arr[0]>>arr[1]>>arr[2]>>arr[3];
    sort(arr, arr+4);
    do{
        int hp = arr[0]*10 + arr[1], mp = arr[2]*10 + arr[3];
        if(hp < 24 && mp < 60) if(hp > h || (hp == h && mp > m)) h = hp, m = mp;
    }while(next_permutation(arr,arr+4));
    if(h != -1) cout<<(h<10?"0":"")<<h<<":"<<(m<10?"0":"")<<m<<endl;
    else cout<<"NOT POSSIBLE"<<endl;
    return 0;
}
