#include <iostream>
#include <set>

using namespace std;
bool is_valid(int n, set<char> dt){
    char low_bit = n%10 + '0';
    char high_bit = n/10 + '0';
    return (dt.find(low_bit) != dt.end() && dt.find(high_bit) != dt.end());
}
int main() {
    //freopen("../input.txt","r",stdin);
    int T,h,m,s,hh,mm,ss;
    char time[20];
    cin>>T;
    while(T--){
        cin>>time;
        set<char> dt;
        sscanf(time,"%d:%d:%d",&h,&m,&s);
        hh = h,mm = m,ss = s;
        for(int i=0;time[i] != '\0';i++) if(time[i] != ':') dt.insert(time[i]);
        bool status = false;
        while(!status) { ss++,ss%=60;if(is_valid(ss,dt)) if(ss < s) break; else status = true; }
        while(!status) { mm++,mm%=60;if(is_valid(mm,dt)) if(mm < m) break; else status = true; }
        while(!status) { hh++,hh%=24;if(is_valid(hh,dt)) if(hh < h) break; else status = true; }
        if(hh < 10) cout<<"0";cout<<hh<<":";
        if(mm < 10) cout<<"0";cout<<mm<<":";
        if(ss < 10) cout<<"0";cout<<ss;
        cout<<endl;
    }
    return 0;
}
