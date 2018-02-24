#include <bits/stdc++.h>
using namespace std;
const int maxb = 1050, maxn = 105;
struct node{
    int v,s;
    char g;
};
int n, x, y, b, mv[maxn][maxn][maxb], fv[maxn][maxn][maxb];
bool ms[maxn][maxn][maxb], fs[maxn][maxn][maxb];
node pp[maxn];
vector<int> mp,fp;
int main(){
    //freopen("../input.txt","r",stdin);
    memset(mv, 0, sizeof(mv));memset(fv, 0, sizeof(fv));
    memset(ms, 0, sizeof(ms));memset(fs, 0, sizeof(fs));
    cin>>n>>x>>y>>b;
    for(int i=0;i<n;i++) {
        cin>>pp[i].g>>pp[i].v>>pp[i].s;
        if(pp[i].g == 'F') fp.push_back(i);
        else mp.push_back(i);
    }
    int mps = mp.size(), fps = fp.size();
    for(int i=0;i<mps;i++){
        int ib = pp[mp[i]].s, iv = pp[mp[i]].v;
        for(int j=0;j<=x;j++) {
            for(int k=0;k<=b;k++) {
                int no_chosev = (i > 0 ? mv[i-1][j][k] : 0);
                int chosev = 0;
                if(j == 1 && k >= ib) chosev = iv;
                if(j > 1 && k >= ib && i > 0 && mv[i-1][j-1][k-ib] > 0) chosev = mv[i-1][j-1][k-ib] + iv;
                if(chosev > no_chosev) ms[i][j][k] = 1, mv[i][j][k] = chosev;
                else ms[i][j][k] = 0, mv[i][j][k] = no_chosev;
            }
        }
    }
    for(int i=0;i<fps;i++){
        int ib = pp[fp[i]].s, iv = pp[fp[i]].v;
        for(int j=0;j<=y;j++) {
            for(int k=0;k<=b;k++) {
                int no_chosev = (i > 0 ? fv[i-1][j][k] : 0);
                int chosev = 0;
                if(j == 1 && k >= ib) chosev = iv;
                if(j > 1 && k >= ib && i > 0 && fv[i-1][j-1][k-ib] > 0) chosev = fv[i-1][j-1][k-ib] + iv;
                if(chosev > no_chosev) fs[i][j][k] = 1, fv[i][j][k] = chosev;
                else fs[i][j][k] = 0, fv[i][j][k] = no_chosev;
            }
        }
    }
    int res_maxv = 0, res_mb = 0, res_fb = 0;
    for(int i=0;i<=b;i++){
        int curr_mv = mv[mps-1][x][i];
        if(curr_mv == 0 && x > 0) continue;
        for(int j=0;j<=b-i;j++){
            int curr_fv = fv[fps-1][y][j];
            if(curr_fv == 0 && y > 0) continue;
            if(res_maxv < (curr_fv + curr_mv)) res_maxv = curr_fv + curr_mv, res_mb = i, res_fb = j;
        }
    }
    set<int> res;
    int rmb = res_mb, rmx = x, rfb = res_fb, rfy = y;
    for(int i=mps-1;i>=0;i--) if(ms[i][rmx][rmb] == 1) res.insert(mp[i]),rmx--,rmb-=pp[mp[i]].s;
    for(int i=fps-1;i>=0;i--) if(fs[i][rfy][rfb] == 1) res.insert(fp[i]),rfy--,rfb-=pp[fp[i]].s;
    int res_v = 0, res_b = 0;
    for(auto r:res) res_v += pp[r].v, res_b += pp[r].s;
    cout<<res_v<<" "<<res_b<<endl;
    for(auto r:res) cout<<r+1<<" ";
    cout<<endl;
    return 0;
}
