#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    //freopen("../input.txt", "r", stdin);
    ll n; cin>>n;
    string ans;
    while(n > 1) {
        bool status = false;
        for(int i = 9; i > 1; i--) if(n % i == 0) {
            ans.push_back(char(i + '0'));
            status = true, n /= i;
            break;
        }
        if(!status) return cout<<-1<<endl, 0;
    }
    if(ans.empty()) ans.push_back('1');
    sort(ans.begin(), ans.end());
    cout<<ans<<endl;
    return 0;
}
