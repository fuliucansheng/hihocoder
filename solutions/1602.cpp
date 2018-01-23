#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 800010, maxc = 26;
struct ptree{
    int ch[maxn][maxc], fail[maxn], cnt[maxn], num[maxn], len[maxn], str[maxn], last, nn, p;
    ptree(){ init(); }
    int newnode(int l){
        for(int i=0;i<maxc;i++) ch[p][i] = 0;
        cnt[p] = 0, num[p] = 0, len[p] = l;
        return p++;
    }
    void init(){
        last = nn = p = 0, newnode(0), newnode(-1), str[nn] = -1, fail[0] = 1;
    }
    int get_fail(int x){
        while(str[nn-len[x]-1] != str[nn]) x = fail[x];
        return x;
    }
    void build(int c){
        str[++nn] = c;
        int curr = get_fail(last);
        if(!ch[curr][c]){
            int now = newnode(len[curr] + 2);
            fail[now] = ch[get_fail(fail[curr])][c];
            ch[curr][c] = now, num[now] = num[fail[now]] + 1;
        }
        last = ch[curr][c], cnt[last]++;
    }
    void count(){
        for(int i=p-1;i>=0;i--) cnt[fail[i]] += cnt[i];
    }
} pe;
int main(){
    //freopen("../input.txt", "r", stdin);
    string s; cin>>s;
    for(auto c:s) pe.build(c - 'a');
    cout<<pe.p-2<<endl;
    return 0;
}
