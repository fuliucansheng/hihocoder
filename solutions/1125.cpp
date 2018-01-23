#include <iostream>
using namespace std;
typedef pair<int,int> ps;
const int maxn = 1000010;
string s;
ps arr[maxn];
bool cmp(ps a, ps b){
    int r = min(a.second, b.second);
    for(int i=0;i<r;i++) if(s[a.first+i] != s[b.first+i]) return s[a.first+i] < s[b.first+i];
    return a.second < b.second;
}
int main(){
    //freopen("../input.txt","r",stdin);
    int t; cin>>t;
    while(t--){
        cin>>s;
        int n = int(s.size()), pc = -1;
        for(int i=0;i<n;i++) {
            arr[++pc] = make_pair(i,1);
            while(pc > 0){
                if(cmp(arr[pc-1], arr[pc])) arr[pc-1].second += arr[pc].second, pc--;
                else break;
            }
        }
        for(int i=0;i<=pc;i++) cout<<arr[i].second<<" "; cout<<endl;
    }
    return 0;
}
