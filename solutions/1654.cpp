#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
#define v(c) (c == 'O' ? 0 : (c == 'X' ? 1 : 2))
#define a(p) (arr[p.first * 4 + p.second])
#define vp(p) (p.first >= 0 && p.first < 4 && p.second >= 0 && p.second < 4 && a(p) != 0)
typedef pair<int,int> ps;
const int maxn = 43050000;
vector<ps> nbr = { ps(-1,0), ps(1,0), ps(0,-1), ps(0,1) };
bool vis[maxn];
int g(int arr[16]){
    int rs = 0;
    for(int i=0;i<16;i++) rs += pow(3, i) * arr[i];
    return rs;
}
vector<int> fnb(int arr[16]){
    vector<int> rs;
    for(int i=0;i<16;i++)
        if(arr[i] == 0){
            ps cc = ps(i/4, i%4);
            for(auto nb:nbr){
                ps nr = ps(nb.first + cc.first, nb.second + cc.second);
                if(vp(nr)) {
                    a(cc) = a(nr), a(nr) = 0;
                    int r = g(arr);
                    if(!vis[r]) rs.push_back(r), vis[r] = true;
                    a(nr) = a(cc), a(cc) = 0;
                }
            }
        }
    return rs;
}
bool is_valid(int arr[16]){
    //row
    for(int i=0;i<16;i+=4) if((arr[i] == 1 || arr[i] == 2) && arr[i+1] == arr[i] && arr[i+2] == arr[i] && arr[i+3] == arr[i]) return true;
    //col
    for(int i=0;i<4;i++) if((arr[i] == 1 || arr[i] == 2) && arr[i+4] == arr[i] && arr[i+8] == arr[i] && arr[i+12] == arr[i]) return true;
    //dig
    if((arr[0] == 1 || arr[0] == 2) && arr[5] == arr[0] && arr[10] == arr[0] && arr[15] == arr[0]) return true;
    if((arr[3] == 1 || arr[3] == 2) && arr[6] == arr[3] && arr[9] == arr[3] && arr[12] == arr[3]) return true;
    return false;
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(vis, 0, sizeof(vis));
    string s = "", ss = "";
    for(int i=0;i<4;i++) cin>>ss, s += ss;
    int hs = 0;
    for(int i=0;i<16;i++) hs += pow(3, i) * v(s[i]);
    queue<int> Q; Q.push(hs), vis[hs] = true;
    int rs = 0;
    bool rr = false;
    while(!Q.empty()){
        int qz = int(Q.size());
        for(int i=0;i<qz;i++){
            int f = Q.front(); Q.pop();
            int arr[16];
            for(int k=0;k<16;k++) arr[k] = f % 3, f /= 3;
            if(is_valid(arr)) { rr = true; break; }
            vector<int> nb = fnb(arr);
            for(auto nn:nb) Q.push(nn);
        }
        if(rr) break;
        rs++;
    }
    cout<<(rr ? rs : -1)<<endl;
    return 0;
}
