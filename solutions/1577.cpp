#include <bits/stdc++.h>
using namespace std;
vector<int> nextarr(string patt){
    vector<int> result(patt.size() + 1, 0);
    for (int i = 1; i < patt.size(); i++) {
        int j = result[i];
        while (j && patt[i] != patt[j]) j = result[j];
        result[i + 1] = patt[i] == patt[j] ? j + 1 : 0;
    }
    return result;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
    int n, m, j = 0; cin>>n>>m;
    string a, b; cin>>a>>b;
    for(int i=0;i<n;i++) a[i] = '1' - a[i] + '0';
    double cntall = double(n) * double(n + 1) / 2, ans = 0;
    vector<int> nxt = nextarr(b);
    for (int i=0;i<n;i++) {
        while (j && a[i] != b[j]) ans += double(j)*double(j+1)/2, ans += double(j) * (n - i), j = nxt[j];
        if (a[i] == b[j]) j++;
        //if (j == m) j = nxt[j];
    }
    while(j) ans += double(j)*double(j+1)/2, j = nxt[j];
    cout<<fixed<<setprecision(8)<<ans/cntall<<endl;
    return 0;
}
