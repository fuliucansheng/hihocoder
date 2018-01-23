#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string nums = "123456789";
vector<string> dt = {"132","312","174","714","195","915","285","825","375","735","396","936","465","645","798","978"};
vector<string> collect;
bool is_valid(string s){
    for(auto c:collect) if(s.find(c) == -1 && s.find(c.assign(c.rbegin(),c.rend())) == -1) return false;
    for(auto d:dt){
        int p = s.find(d.substr(0,2));
        if(p != -1 && s.substr(0,p).find(d[2]) == -1) return false;
    }
    return true;
}
int solve(){
    string lastnums = "000000000";
    int count = 0;
    do{
        int start = 0;
        for(start=0;start<9;start++) if(lastnums[start] != nums[start]) break;
        for(int i=max(start+1,4);i<=9;i++){
            string currstr = nums.substr(0,i);
            if(is_valid(currstr)) count++;
        }
        lastnums = nums;
    }while(next_permutation(nums.begin(),nums.end()));
    return count;
}
int main(){
    freopen("../input.txt","r",stdin);
    int t,n;
    string l,r;
    cin>>t;
    while(t--){
        cin>>n;
        collect.clear();
        for(int i=0;i<n;i++) cin>>l>>r,collect.push_back(l+r);
        cout<<solve()<<endl;
    }
    return 0;
}
