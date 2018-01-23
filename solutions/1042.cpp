#include <iostream>
#include <algorithm>

using namespace std;
int m,n,L,l,r,t,b;
typedef pair<int,int> result;
result solve(int aa,int bb){
    if(aa <= t) return result(2*(aa+bb),aa*bb);
    else if(aa <= b){
        if(bb <= l) return result(2*(aa+bb),aa*bb);
        else if(bb <= r) return result(2*(aa+bb),aa*bb-(aa-t)*(bb-l));
        else return result(2*(aa+bb+aa-t),aa*bb-(aa-t)*(r-l));
    }else{
        if(bb <= l) return result(2*(aa+bb),aa*bb);
        else if(bb <= r) return result(2*(aa+bb+bb-l),aa*bb-(bb-l)*(b-t));
        else return result(2*(aa+bb),aa*bb-(r-l)*(b-t));
    }
}
int main(){
    //freopen("../input.txt","r",stdin);
    cin>>n>>m>>L>>l>>r>>t>>b;
    int swap;
    if(m-r > l) swap=l,l=m-r,r=l+r-swap;
    if(n-b > t) swap=t,t=n-b,b=t+b-swap;
    int maxarea = 0;
    for(int aa=1;aa<=n;aa++){
        for(int bb=1;bb<=m;bb++){
            result res = solve(aa,bb);
            if(res.first <= L) maxarea = max(maxarea,res.second);
        }
    }
    cout<<maxarea<<endl;
    return 0;
}
