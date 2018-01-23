#include <iostream>
#include <set>
#include <cstring>
using namespace std;
string solve(string n){
    set<string> dict;
    string res = "0.";
    int arr[n.size()-1];
    memset(arr,0,sizeof(arr));
    for(int i=2;i<n.size();i++){
        arr[i-1] = n[i]-'0';
    }
    for(int t=0;t<n.size();t++){
        for(int i=0;i<n.size()-1;i++) arr[i] *= 2;
        for(int i=n.size()-2;i>0;i--){
            arr[i-1] += arr[i]/10;
            arr[i] = arr[i]%10;
        }
        if(arr[0] >= 1) res += "1",arr[0] -= 1;
        else res += "0";
    }
    for(int i=0;i<n.size()-1;i++){
        if(arr[i] != 0) return "NO";
    }
    int pos = n.size()-2;
    for(int i=res.size()-1;i>0;i--) {
        if(res[i] != '0'){
            pos = i;
            break;
        }
    }
    return res.substr(0,pos+1);
}
int main() {
    //freopen("../input.txt","r",stdin);
    int m;
    string n;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}
