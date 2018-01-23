#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;
struct rule{
    rule(){}
    rule(int a,bool b){
        this->first = a;
        this->second = b;
    }
    int first;
    bool second;
    bool operator<(const rule &b){
        return this->first < b.first;
    }
};
struct rkey{
    rkey(int a,int b){
        this->first = a;
        this->second = b;
    }
    int first;
    int second;
    bool operator<(const rkey &b)const{
        return (this->first != b.first) ? (this->first < b.first) : (this->second < b.second);
    }
};

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
    //freopen("input.txt","r",stdin);
    int m,n,a,b,c,d;
    char s[110];
    char sc[20];
    cin>>n>>m;
    map<rkey,rule> dict;
    cin.get();
    for(int p=0;p<n;p++){
        bool f = false;
        cin.getline(s,110);
        int len = strlen(s),mask = 32;
        for(int i=len-1;i>=0;i--){
            if(s[i] == '/'){
                f = true;
                break;
            }
        }
        f ? sscanf(s,"%s %d.%d.%d.%d/%d",sc,&a,&b,&c,&d,&mask) : sscanf(s,"%s %d.%d.%d.%d",sc,&a,&b,&c,&d);
        int r = getpre(a,b,c,d,mask);
        rkey rt = rkey(r,mask);
        if(dict.find(rt) == dict.end()){
            dict[rt] = rule(p,strcmp(sc,"allow")==0);
        }
    }
    for(int q=0;q<m;q++){
        scanf("%d.%d.%d.%d",&a,&b,&c,&d);
        bool res = true;
        int seq = n;
        for(int i=0;i<=32;i++){
            int ip = getpre(a,b,c,d,i);
            rkey rp = rkey(ip,i);
            if(dict.find(rp) != dict.end()){
                rule rtp = dict[rp];
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
