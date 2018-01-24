#include <iostream>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;
typedef pair<long long,long long> cvalue;
static map<int,cvalue> dp[20][10];
const long long modnum = 1000000007;
void init(){
    dp[0][0].insert(make_pair(0,cvalue(1,0)));
    for(int i=0;i<20;i++){
        for(int j=0;j<10;j++){
            if(j > 0){
                for(auto it = dp[i][j-1].begin();it != dp[i][j-1].end();it++){
                    cvalue nsec = it->second;
                    nsec.second += (static_cast<long long>(pow(10,double(i)))%modnum)*(nsec.first%modnum);
                    nsec.second %= modnum;
                    dp[i][j].insert(make_pair((it->first+1),nsec));
                }
            }else if(i > 0){
                for(int k=0;k<10;k++){
                    for(auto it = dp[i-1][k].begin();it != dp[i-1][k].end();it++){
                        if(dp[i][j].find(it->first*-1) == dp[i][j].end()){
                            dp[i][j].insert(make_pair(it->first*-1,it->second));
                        }else{
                            dp[i][j][it->first*-1].first += (it->second.first%modnum);
                            dp[i][j][it->first*-1].first %= modnum;
                            dp[i][j][it->first*-1].second += (it->second.second%modnum);
                            dp[i][j][it->first*-1].second %= modnum;
                        }
                    }
                }
            }
        }
    }
}
cvalue getlower(int i,int j,int t){
    cvalue res = cvalue(0,0);
    for(int n=j-1;n>=0;n--){
        if(n > 0){
            res.first += dp[i][n][t].first % modnum;
            res.first %= modnum;
            res.second += dp[i][n][t].second % modnum;
            res.second %= modnum;
        }else if(i > 0){
            cvalue tmp = getlower(i-1,10,t);
            res.first += tmp.first % modnum;
            res.first %= modnum;
            res.second += tmp.second % modnum;
            res.second %= modnum;
        }
    }
    return res;
}
long long findsum(long long num,int target){
    long long res = 0;
    if(num == 0) return 0;
    stack<int> arr;
    while(num>0){
        arr.push(num%10);
        num /= 10;
    }
    long long prefix = arr.top();
    res = getlower(arr.size()-1,arr.top(),target).second % modnum;
    target -= prefix,target *= -1;
    arr.pop();
    while(arr.size() > 0){
        int topi = arr.size()-1;
        int topv = arr.top();
        long long count = 0,sum = 0;
        for(int i=0;i<topv;i++){
            count += dp[topi][i][target].first % modnum;
            count %= modnum;
            sum += dp[topi][i][target].second % modnum;
            sum %= modnum;
        }
        res += sum + ((count*prefix%modnum)*(static_cast<long long>(pow(10,double(topi+1)))%modnum))%modnum;
        res %= modnum;
        prefix *= 10,prefix += topv;
        target -= arr.top(),target *= -1;
        arr.pop();
    }
    return res;
}
int main() {
    //freopen("../input.txt","r",stdin);
    long long l,r;
    int t;
    cin>>l>>r>>t;
    init();
    long long right = findsum(r+1,t)%modnum;
    long long left = findsum(l,t)%modnum;
    cout<<((right-left)<0?((right-left)+modnum):(right-left))<<endl;
    return 0;
}
