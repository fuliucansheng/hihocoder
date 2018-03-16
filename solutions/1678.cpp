#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
struct node{
    string s;
    vector<int> r;
} arr[maxn];
bool cmp(node a, node b){
    int i = 0, sz = min(int(a.r.size()), int(b.r.size()));
    while(i < sz && a.r[i] == b.r[i]) i++;
    if(i == sz) return a.r.size() < b.r.size();
    return a.r[i] < b.r[i];
}
int main(){
    //freopen("../input.txt","r",stdin);
    int n; cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i].s;
        int s = 0;
        for(auto chr:arr[i].s) if(chr == '.') arr[i].r.push_back(s), s = 0; else s *= 10, s += chr - '0';
        arr[i].r.push_back(s);
    }
    sort(arr, arr+n, cmp);
    for(int i=0;i<n;i++) cout<<arr[i].s<<endl;
    return 0;
}
