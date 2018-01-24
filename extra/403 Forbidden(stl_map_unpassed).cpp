#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
typedef pair<int,bool> rule;
typedef pair<int,int> rkey;
int getpre(int a,int b,int c, int d , int num){
    int res = 0;
    if(num == 0) return 0;
    res |= a,res<<=8;
    res |= b,res<<=8;
    res |= c,res<<=8;
    res |= d;
    int k = 32 - num;
    res >>= k;
    res <<= k;
    return res;
}
int main(){
    int m,n,a,b,c,d;
    char dot;
    cin>>n>>m;
    map<rkey,rule> dict;
    for(int p=0;p<n;p++){
        string s;
        cin>>s;
        cin>>a>>dot>>b>>dot>>c>>dot>>d;
        char t;
        cin.get(t);
        int mask = 32;
        if(t == '/'){
            cin>>mask;
        }
        int r = getpre(a,b,c,d,mask);
        rkey rk = rkey(r,mask);
        if(dict.find(rk) == dict.end()){
            dict[rk] = rule(p,s=="allow");
        }
    }
    for(int q=0;q<m;q++){
        cin>>a>>dot>>b>>dot>>c>>dot>>d;
        bool res = true;
        int seq = n;
        for(int i=0;i<=32;i++){
            int ip = getpre(a,b,c,d,i);
            rkey rk = rkey(ip,i);
            if(dict.find(rk) != dict.end()){
                rule rtp = dict[rk];
                if(rtp.first < seq){
                    seq = rtp.first;
                    res = rtp.second;
                }
            }
        }
        cout<<(res?"YES":"NO")<<endl;
    }
    return 0;
}
