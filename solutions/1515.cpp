#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int group[maxn], score[maxn], diff[maxn];
int find_group(int x){
    if(x == group[x]) return x;
    int dx = group[x];
    group[x] = find_group(dx);
    score[x] = score[dx] + diff[x];
    diff[x] = score[x] - score[group[x]];
    return group[x];
}
void union_group(int x, int y, int s){
    int dx = find_group(x), dy = find_group(y);
    if(dx < dy){
        diff[dy] = score[dy] = score[x] - score[y] - s;
        group[dx] = group[dy] = dx;
    }else if(dx > dy){
        diff[dx] = score[dx] = s - score[x] + score[y];
        group[dx] = group[dy] = dy;
    }

}
int main(){
    //freopen("../input.txt","r",stdin);
    for(int i=0;i<maxn;i++) group[i] = i, score[i] = 0, diff[i] = 0;
    int n, m, q; cin>>n>>m>>q;
    for(int i=0;i<m;i++){
        int u, v, s; cin>>u>>v>>s;
        union_group(u, v, s);
    }
    for(int i=0;i<q;i++){
        int u, v; cin>>u>>v;
        int du = find_group(u), dv = find_group(v);
        if(du != dv) cout<<-1<<endl;
        else cout<<score[u] - score[v]<<endl;
    }
    return 0;
}
