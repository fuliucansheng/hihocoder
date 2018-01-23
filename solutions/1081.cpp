#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 1001;
int rec[MAXN],dis[MAXN][MAXN],status[MAXN];
int m,n,s,t,ms,mt,md;
void update(int node){
    for(int i=1;i<=n;i++){
        if(!status[i] && dis[node][i] != -1){
            rec[i] = (rec[i] != -1 ? min(rec[i], rec[node]+dis[node][i]) : rec[node]+dis[node][i]);
        }
    }
}
void step(){
    int node = -1;
    for(int i=1;i<=n;i++){
        if(!status[i] && rec[i] != -1){
            if(node == -1) node = i;
            else if(rec[i] < rec[node]) node = i;
        }
    }
    status[node] = 1;
    update(node);
}
int main(){
    //freopen("../input.txt","r",stdin);
    memset(dis, -1, sizeof(dis));memset(rec, -1, sizeof(rec));memset(status, 0, sizeof(status));
    cin>>n>>m>>s>>t;
    for(int i=0;i<m;i++) {
        cin>>ms>>mt>>md;
        md = (dis[ms][mt] != -1) ? min(dis[ms][mt], md) : md;
        md = (dis[mt][ms] != -1) ? min(dis[mt][ms], md) : md;
        dis[mt][ms] = dis[ms][mt] = md;
    }
    rec[s] = 0, status[s] = 1;update(s);
    while(!status[t]) step();
    cout<<rec[t]<<endl;
    return 0;
}

