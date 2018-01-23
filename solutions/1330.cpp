#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int g(int a,int b){
    int mx = max(a,b),mn = min(a,b);
    if(mx%mn == 0) return mn;
    else return g(mx-mn,mn);
}

int main() {
    //freopen("../input.txt","r",stdin);
    int N,res = 1,count=0;
    cin>>N;
    int arr[N];
    set<int> rec,vrec;
    for(int i = 0;i < N;i++) cin>>arr[i];
    for(int i = 0;i < N;i++){
        if(rec.find(i) == rec.end()){
            int pos = i;
            while(rec.find(pos) == rec.end()){
                rec.insert(pos);
                count++;
                pos = arr[pos] - 1;
            }
            vrec.insert(count);
            count = 0;
        }
    }
    for(auto v:vrec){
        int r = g(res,v);
        res = res/r*v;
    }
    cout<<res<<endl;
    return 0;
}
