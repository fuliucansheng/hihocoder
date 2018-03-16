#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int m, n, L, l, r, t, b;
pii solve(int aa, int bb){
    if(aa <= t) return pii(2*(aa+bb),aa*bb);
    else if(aa <= b){
        if(bb <= l) return pii(2*(aa+bb),aa*bb);
        else if(bb <= r) return pii(2*(aa+bb),aa*bb-(aa-t)*(bb-l));
        else return pii(2*(aa+bb+aa-t),aa*bb-(aa-t)*(r-l));
    }else{
        if(bb <= l) return pii(2*(aa+bb),aa*bb);
        else if(bb <= r) return pii(2*(aa+bb+bb-l),aa*bb-(bb-l)*(b-t));
        else return pii(2*(aa+bb),aa*bb-(r-l)*(b-t));
    }
}
int main(){
    //freopen("../input.txt","r",stdin);
    cin>>n>>m>>L>>l>>r>>t>>b;
    int swap;
    if(m - r > l) swap = l, l = m - r, r = l + r - swap;
    if(n - b > t) swap = t, t = n - b, b = t + b - swap;
    int ans = 0;
    for(int aa=1;aa<=n;aa++){
        for(int bb=1;bb<=m;bb++){
            pii rs = solve(aa,bb);
            if(rs.first <= L) ans = max(ans, rs.second);
        }
    }
    cout<<ans<<endl;
    return 0;
}