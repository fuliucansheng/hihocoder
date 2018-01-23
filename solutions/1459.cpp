#include <iostream>
#include <cstring>
using namespace std;
int arr[26], rec[26], k;
string s;
bool is_valid(int n){
    memset(rec, 0, sizeof(rec));
    for(int i=0;i<n;i++) rec[s[i]-'a']++;
    for(int i=0;i<26;i++) if(arr[i] >=n && (n - rec[i]) <= k) return true;
    for(int i=n;i<s.size();i++){
        rec[s[i]-'a']++, rec[s[i-n]-'a']--;
        for(int j=0;j<26;j++) if(arr[j] >=n && (n - rec[j]) <= k) return true;
    }
    return false;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(arr, 0, sizeof(arr));
    cin>>k>>s;
    for(auto c:s) arr[c-'a']++;
    int l = 1, r = s.size();
    while(r - l > 1){
        int m = (l + r)/2;
        if(is_valid(m)) l = m; else r = m;
    }
    cout<<(is_valid(r) ? r : l)<<endl;
    return 0;
}
