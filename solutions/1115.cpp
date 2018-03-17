#include <bits/stdc++.h>
using namespace std;
const int maxn = 7;
struct node{
    int hp, atk;
    bool d = false,w = false;
}arr[maxn];
int n;
bool dfs(int i, int &dmg, int rest, bool dd){
    if(i == n) return rest <= 0;
    bool ret = false;
    int cs = 2, mx = 0;
    if(arr[i].w) cs = 3;
    for(int c=0;c<cs;c++){
        int dg = 0;
        if(c == 0) {
            bool r = dd ? (arr[i].w && (arr[i].hp>8 || arr[i].d) ? dfs(i+1, dg, rest-arr[i].atk, false) : dfs(i+1, dg, rest, false))
                        : (arr[i].w && (arr[i].hp>8 || arr[i].d) ? dfs(i+1, dg, rest-2*arr[i].atk, false) : dfs(i+1, dg, rest-arr[i].atk, false));
            if(r) mx = max(mx, dg), ret = true;
        }
        if(c == 1 && dfs(i+1, dg, rest, dd)) mx = max(mx, dg+(arr[i].w ? 2*arr[i].atk : arr[i].atk)), ret = true;
        if(c == 2) {
            bool r = dd ? dfs(i+1, dg, rest, false) : dfs(i+1, dg, rest-arr[i].atk, false);
            if(r) mx = max(mx, dg+((arr[i].hp > 8 || arr[i].d) ? arr[i].atk : 0)), ret = true;
        }
    }
    dmg = mx;
    return ret;
}
int main(){
    //freopen("../input.txt","r",stdin);
    while(scanf("%d", &n) != EOF){
        for(int i=0;i<n;i++){
            scanf("%d%d", &arr[i].atk, &arr[i].hp);
            arr[i].d = false, arr[i].w = false;
            char chr;
            while(scanf("%c", &chr) != EOF)
                if(chr == '\n') break;
                else if(chr == 'D') arr[i].d = true;
                else if(chr == 'W') arr[i].w = true;
        }
        sort(arr, arr+n, [](node a, node b){ return a.atk <= b.atk;});
        int dmg = 0;
        dfs(0, dmg, 8, true);
        cout<<dmg<<endl;
    }
    return 0;
}