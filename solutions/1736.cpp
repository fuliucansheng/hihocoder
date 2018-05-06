#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
int a[maxn], vs[maxn], n, k;
bool is_valid(int j, int i) {
    if(abs(j - i) > k) return false;
    int b = 1;
    for(int a = i + 1; a <= n; a++) {
        while(vs[b] || b == j) b++;
        if(abs(b - a) > k) return false;
        b++;
    }
    return true;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    cin>>n>>k;
    for(int i = 1; i <= n; i++) {
        for(int j = n; j > 0; j--) if(!vs[j] && is_valid(j, i)) {
            a[i] = j, vs[j] = true;
            break;
        }
    }
    for(int i = 1; i <= n; i++) cout<<a[i]<<" "; cout<<endl;
    return 0;
}
