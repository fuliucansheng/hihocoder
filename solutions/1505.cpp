#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
const int maxn = 1010;
int arr[maxn], n;
map<int,int> dict, rec;
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr, arr+n);
    for(int i=0;i<n;i++) dict[arr[i]]++;
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) rec[arr[i]+arr[j]]++;
    ll rs = 0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){
            int c = rec[arr[i]+arr[j]];
            if(arr[i] != arr[j]) c -= dict[arr[j]], c -= dict[arr[i]], c++;
            else c -= (dict[arr[i]] - 1)*2, c++;
            rs += ll(c);
        }
    cout<<rs<<endl;
    return 0;
}
