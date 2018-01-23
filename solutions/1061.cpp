#include <iostream>
using namespace std;
int main(){
    //freopen("../input.txt","r",stdin);
    int n;
    scanf("%d", &n);
    while(n--){
        long long s;scanf("%lld", &s);
        char chr[s+1];scanf("%s", chr);
        long long l = 0, m = 0, r = 1;
        char lc = 'z', mc = 'z', rc = chr[0];
        bool status = false;
        for(long long i=1;i<s;i++){
            if(chr[i] == chr[i-1]) r++;
            else{
                if(l >= m && m <= r && (mc - lc == 1) && (rc - mc == 1)) { status = true; break; }
                lc = mc, mc = rc, rc = chr[i];
                l = m, m = r, r = 1;
            }
        }
        if(l >= m && m <= r && (mc - lc == 1) && (rc - mc == 1)) status = true;
        if(status) printf("%s\n","YES"); else printf("%s\n","NO");
    }
    return 0;
}
