#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 1e5+10;
int n, num, res[maxn];
typedef pair<int,int> node;
int main(){
    //freopen("../input.txt","r",stdin);
    cin>>n;
    priority_queue<node,vector<node>,greater<node>> rec;
    memset(res, 0, sizeof(res));
    for(int i=0;i<n;i++) {
        cin>>num;
        rec.push(node(num, i));
        while(rec.top().first < num) {
            if(res[rec.top().second] == 0) res[rec.top().second] = i;
            rec.pop();
        }
    }
    for(int i=0;i<n;i++) cout<<(res[i]==0?-1:res[i]-i)<<endl;
    return 0;
}
