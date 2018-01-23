#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<string> month = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
map<string,int> dict;
struct date{ int m,d,y; };
int count(date s){
    int res = 0, curr_year = s.y;
    if(s.m < 2 || (s.m == 2 && s.d < 29)) curr_year--;
    res = curr_year/400 + curr_year/4 - curr_year/100;
    return res;
}
int main(){
    //freopen("../input.txt","r",stdin);
    for(int i=0;i<month.size();i++) dict[month[i]] = i + 1;
    int t;
    cin>>t;
    string m;
    char dot;
    date start,stop;
    for(int i=0;i<t;i++){
        cin>>m>>start.d>>dot>>start.y, start.m = dict[m];
        cin>>m>>stop.d>>dot>>stop.y, stop.m = dict[m];
        int res = count(stop) - count(start);
        if(start.m == 2 && start.d == 29) res++;
        cout<<"Case #"<<i+1<<": "<<res<<endl;
    }
    return 0;
}
