#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 0x3f3f3f3f;
int a[16], r[16], m, n, t, s;
int main(){
    //freopen("../input.txt", "r", stdin);
    int q; cin>>q;
    while(q--){
        cin>>n>>m>>t>>s;
        int nm = n*m;
        for(int i=0;i<nm;i++) cin>>a[i], r[i] = i;
        sort(r, r+nm, [a](int x, int y){ return a[x] > a[y];});
        vector<int> air, ship;
        for(int i=1;i<=t;i++){
            int x; cin>>x;
            if(x) air.push_back(x);
        }
        for(int i=1;i<=t;i++){
            int x; cin>>x;
            if(x) ship.push_back(x);
        }
        sort(air.begin(), air.end(), greater<int>());
        sort(ship.begin(), ship.end(), greater<int>());
        int maxatk = -inf, status = 0;
        for(int ms=0;ms<(1<<nm);ms++){
            int f, g, e, d, atk;
            f = g = e = d = atk = 0;
            for(int i=0;i<nm;i++){
                if(ms >> i & 1){
                    if(f < air.size()) d += a[r[i]] * air[f++];
                }else{
                    if(g < ship.size()){
                        atk += a[r[i]] * ship[g++];
                        e |= (1 << (r[i] / m));
                    }
                }
            }
            e = e == (1 << n) - 1;
            if(d >= s){
                if(atk > maxatk) maxatk = atk, status = e;
                else if(atk == maxatk) status |= e;
            }
        }
        if(maxatk != -inf){
            cout<<maxatk<<endl<<(status ? "Yes" : "No")<<endl;
        }else cout<<"Not Exist"<<endl;
    }
    return 0;
}

