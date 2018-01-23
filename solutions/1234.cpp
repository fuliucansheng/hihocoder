#include <iostream>
#include <vector>
using namespace std;
typedef pair<double,double> pp;
const int it = 500;
vector<int> cnt;
vector<pp> reg;
int main(){
    //freopen("../input.txt", "r", stdin);
    double l = 0, r = 1;
    for(int i=1;i<it;i++){
        double nl = l + (r-l)/4, nr = r - (r-l)/4;
        reg.push_back(pp(l, nl)); cnt.push_back(4*i);
        l = nl, r = nr;
    }
    int t; cin>>t;
    while(t--){
        double k; cin>>k;
        if(reg[reg.size()-1].second < k) cout<<cnt[cnt.size()-1]<<endl;
        else{
            for(int i=0;i<reg.size();i++){
                if(reg[i].first == k || reg[i].second == k) { cout<<-1<<endl; break; }
                if(reg[i].first < k && reg[i].second > k) { cout<<cnt[i]<<endl; break; }
            }
        }
    }
    return 0;
}
