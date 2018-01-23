#include <iostream>
#include <cstring>
using namespace std;
int arr[26];
bool is_valid(int x){
    int rs = 0, mx = -1;
    arr[x]--;
    for(int i=0;i<26;i++) if(i != x && (mx == -1 || arr[i] > arr[mx])) mx = i;
    for(int i=0;i<26;i++) if(i != mx) rs += arr[i];
    arr[x]++;
    if(mx == -1 || arr[mx] > rs + 1) return false;
    return true;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(arr, 0, sizeof(arr));
    string s, rs = ""; cin>>s;
    for(auto c:s) arr[c-'a']++;
    for(int i=0;i<s.size();i++) {
        int rsz = rs.size();
        for(int j=0;j<26;j++) if((i == 0 || (i > 0 && j != rs[i-1] - 'a')) && arr[j] && is_valid(j)) { rs += (j + 'a'), arr[j]--; break; }
        if(rs.size() == rsz) return cout<<"INVALID"<<endl, 0;
    }
    cout<<rs<<endl;
    return 0;
}

