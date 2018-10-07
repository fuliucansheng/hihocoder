#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("../input.txt", "r", stdin);
    string s; cin>>s;
    int c0 = 0, c1 = 0;
    for(auto ch : s) ch == '0' ? c0++ : c1++;
    cout<<min(c0, c1)<<endl;
    return 0;
}
