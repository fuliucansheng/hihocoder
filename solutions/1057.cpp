#include <iostream>
#include <stack>
#include <map>
#include <vector>
using namespace std;
struct op{
    op(){}
    op(string n,int h,int m,int s,bool t):name(n),hour(h),minute(m),second(s),type(t){}
    string name;
    int hour,minute,second;
    bool type;
};
string time(int hour,int minute,int second){
    string res = "";
    res += (hour/10) + '0';res += (hour%10) + '0';res += ":";
    res += (minute/10) + '0';res += (minute%10) + '0';res += ":";
    res += (second/10) + '0';res += (second%10) + '0';
    return res;
}
int main(){
    //freopen("../input.txt","r",stdin);
    int n;
    cin>>n;
    vector<string> funcs;
    map<string,string> periods;
    stack<op> in;
    op t,nt,lt("",0,0,-1,true);
    string type;
    char dot;
    bool status = true;
    for(int i=0;i<n;i++){
        cin>>t.name>>t.hour>>dot>>t.minute>>dot>>t.second>>type;
        if(t.hour < 0 || t.minute < 0 || t.second < 0) status = false;
        if(t.hour*3600+t.minute*60+t.second < lt.hour*3600+lt.minute*60+lt.second) status = false;
        lt = t;
        if(status && type != "START" && type != "END") status = false;
        if(status) t.type = (type == "START");
        if(status && t.type) in.push(t),funcs.push_back(t.name);
        else if(status){
            if(in.empty()) { status = false; continue; }
            op top = in.top();
            if(top.name != t.name || top.type == t.type) status = false;
            else{
                nt.name = t.name;
                int sec = (t.hour - top.hour)*3600 + (t.minute - top.minute)*60 + t.second - top.second;
                nt.second = sec%60;nt.minute = (sec/60)%60;nt.hour = (sec/3600);
                periods[nt.name] = time(nt.hour,nt.minute,nt.second);
                in.pop();
            }
        }
    }
    if(!in.empty()) status = false;
    if(!status) cout<<"Incorrect performance log"<<endl;
    else for(int i=0;i<funcs.size();i++) cout<<funcs[i]<<" "<<periods[funcs[i]]<<endl;
    return 0;
}
