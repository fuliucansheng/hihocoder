#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxnode = 100010, maxchild = 26;
string arr[1010];
bool res[maxnode];
struct acmotion {
    int graph[maxnode][maxchild], next[maxnode], val[maxnode], last[maxnode];
    int sz;
    int idx(char s) { return s - 'a'; }
    acmotion() {
        sz = 1;
        memset(graph, 0, sizeof(graph));memset(next, 0, sizeof(next));
        memset(val, 0, sizeof(val));memset(last, 0, sizeof(last));
    }
    void insert(string str, int v) {
        int u = 0;
        for(int i = 0; i < str.size(); i++) {
            int c = idx(str[i]);
            if (!graph[u][c]) graph[u][c] = sz++;
            u = graph[u][c];
        }
        val[u] = v;
    }
    void nextarr() {
        queue<int> q;
        for(int i = 0; i < maxchild; i++) if (graph[0][i]) q.push(graph[0][i]);
        while (!q.empty()) {
            int r = q.front(); q.pop();
            for (int i = 0; i < maxchild; i++) {
                int u = graph[r][i], j = next[r];
                if (!u) continue;
                q.push(u);
                while (j && !graph[j][i]) j = next[j];
                next[u] = graph[j][i], last[u] = val[next[u]] ? next[u] : last[next[u]];
            }
        }
    }
    set<pii> solve(string str) {
        int count = 0, j = 0;
        set<pii> ans;
        for (int i = 0; i < str.size(); i++) {
            int c = idx(str[i]);
            while (j && !graph[j][c]) j = next[j];
            j = graph[j][c];
            int rs = 0;
            if(val[j]) rs = max(rs, get_maxlen(j));
            else if (last[j]) rs = max(rs, get_maxlen(j));
            if(rs) ans.insert(pii(i-rs+1, i));
        }
        return ans;
    }
    int get_maxlen(int j) {
        int res = 0;
        while (j) {
            if (val[j]) res = max(res, int(arr[val[j]].size()));
            j = last[j];
        }
        return res;
    }
};
int main() {
    //freopen("../input.txt", "r", stdin);
    acmotion act = acmotion();
    int n; cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        act.insert(arr[i], i);
    }
    cin>>s;
    act.nextarr();
    set<pii> ans = act.solve(s);
    memset(res, 0, sizeof(res));
    int r = -1;
    for(auto p:ans){
        if(p.first > r) r = p.first;
        for(int i=max(0,r);i<=p.second;i++) res[i] = true;
        r = max(r, p.second);
    }
    for(int i=0;i<int(s.size());i++) cout<<(res[i] ? '*' : s[i]); cout<<endl;
    return 0;
}
