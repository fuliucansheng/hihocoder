#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("../input.txt", "r", stdin);
    int a, b; cin>>a>>b;
    int f = 1;
    if(a > b) swap(a, b), f = -1;
    if(b - a <= a + 360 - b) cout<<(b - a) * f<<endl;
    else cout<<-(a + 360 - b) * f<<endl;
    return 0;
}
