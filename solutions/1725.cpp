#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 20010;
string arr[maxn];
int main() {
    //freopen("../input.txt", "r", stdin);
    int n; cin>>n;
    unordered_map<string,int> cnt;
    for(int i = 0; i < n; i++) cin>>arr[i], cnt[arr[i]]++;
    ll ret = 0;
    for(int i = 0; i < n; i++) {
        string s = arr[i];
        int sz = int(s.length());
        for(int a = 0; a < sz; a++) for(int b = a + 1; b < sz; b++) if(s[a] != s[b]){
            swap(s[a], s[b]);
            ret += cnt[s];
            swap(s[a], s[b]);
        }
    }
    cout<<ret / 2<<endl;
    return 0;
}
