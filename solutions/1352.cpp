#include <iostream>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
#define g(p) (p.first*1000+p.second)
#define vp(p) (p.first >= 0 && p.first < 1000 && p.second >= 0 && p.second < 1000)
typedef pair<int,int> ps;
const int maxn = 1002000;
vector<ps> nbr = { ps(0,1), ps(0,-1), ps(1,0), ps(-1,0) };
int group[maxn], graph[maxn];
int find_group(int x){
    return x == group[x] ? x : group[x] = find_group(group[x]);
}
int main(){
    //freopen("../input.txt", "r", stdin);
    memset(graph, 0, sizeof(graph));
    for(int i=0;i<maxn;i++) group[i] = i;
    int n; cin>>n;
    int rs = 0;
    for(int i=0;i<n;i++){
        ps p; cin>>p.first>>p.second;
        graph[g(p)] = 1, rs++;
        set<int> gc;
        for(auto nb:nbr){
            ps nr = ps(p.first + nb.first, p.second + nb.second);
            if(vp(nr) && graph[g(nr)]) gc.insert(find_group(g(nr)));
        }
        int px = find_group(g(p));
        for(auto gg:gc) group[gg] = px;
        rs -= gc.size();
        cout<<rs<<endl;
    }
    return 0;
}
