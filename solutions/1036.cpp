#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxnode = 1e6,maxchild = 26;
struct acmotion{
    int graph[maxnode][maxchild],next[maxnode],val[maxnode],last[maxnode];
    int sz;
    int idx(char s){return s-'a';}
    acmotion(){sz=1;memset(graph, 0, sizeof(graph));memset(next, 0, sizeof(next));memset(val, 0, sizeof(val));memset(last, 0, sizeof(last));}
    void insert(string str,int v){
        int u = 0;
        for(int i=0;i<str.size();i++){
            int c = idx(str[i]);
            if(!graph[u][c]){
                graph[u][c] = sz++;
            }
            u = graph[u][c];
        }
        val[u] = v;
    }
    void nextarr(){
        queue<int> q;
        for(int i=0;i<maxchild;i++) if(graph[0][i]) q.push(graph[0][i]);
        while(!q.empty()){
            int r = q.front();q.pop();
            for(int i=0;i<maxchild;i++){
                int u = graph[r][i];
                int j = next[r];
                if(!u) continue;
                q.push(u);
                while(j && !graph[j][i]) j = next[j];
                next[u] = graph[j][i];
                last[u] = val[next[u]] ? next[u] : last[next[u]];
            }
        }
    }
    bool search(string str){
        int count = 0,j = 0;
        for(int i=0;i<str.size();i++){
            int c = idx(str[i]);
            while(j && !graph[j][c]) j = next[j];
            j = graph[j][c];
            if(val[j] || last[j]) return true;
        }
        return false;
    }
};
int main(){
    //freopen("../input.txt","r",stdin);
    acmotion act = acmotion();
    int n;
    cin>>n;
    string patt,str;
    for(int i=1;i<=n;i++){
        cin>>patt;
        act.insert(patt,i);
    }
    act.nextarr();
    cin>>str;
    cout<<(act.search(str)?"YES":"NO")<<endl;
    return 0;
}
