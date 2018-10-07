#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("../input.txt", "r", stdin);
    int n, m; cin>>n>>m;
    if(2 * m + 2 < n || 2 * n + 2 < m) return cout<<-1<<endl, 0;
    while(n > 0 || m > 0) {
        if(n > m) {
            if(n > m + 1) cout<<"A", n--;
            if(n) cout<<"A", n--;
            if(m) cout<<"B", m--;
        } else {
            if(m > n + 1) cout<<"B", m--;
            if(m) cout<<"B", m--;
            if(n) cout<<"A", n--;
        }
    }
    return 0;
}
