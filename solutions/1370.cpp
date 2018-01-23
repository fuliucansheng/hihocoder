#include <iostream>
#include <set>
using namespace std;
set<int> rec;
bool is_valid(int n){
    if(n == 1) return true;
    if(rec.find(n) != rec.end()) return false;
    rec.insert(n);
    int nn = 0;
    while(n) nn += (n%10)*(n%10), n /= 10;
    return is_valid(nn);
}
int main(){
    //freopen("../input.txt", "r", stdin);
    int n;
    while(cin>>n){
        if(n == -1) break;
        rec.clear();
        cout<<(is_valid(n) ? "true" : "false")<<endl;
    }
    return 0;
}

