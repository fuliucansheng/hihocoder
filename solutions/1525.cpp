#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
char get(int x,int y){
    long long maxxy = max(abs(x),abs(y));
    long long circum = 8 * maxxy;
    long long countinner = (2 * maxxy + 1) * (2 * maxxy + 1);
    long long count = 0;
    if(abs(x) == maxxy){
        if(x > 0) count = 3 * maxxy  - y;
        else count = 7 * maxxy + y;
    }else{
        if(y > 0) count = maxxy + x;
        else count = 5 * maxxy - x;
    }
    count--;
    long long total = countinner + count - circum;
    return (total % 26) + 'A';
}
int main(){
    //freopen("../input.txt","r",stdin);
    set<char> dict = {'B','D','F','H'},dict2 = {'K','C','O','E','S','G','W','I'};
    int m,x,y;
    cin>>m;
    while(m--){
        cin>>x>>y;
        char c = get(x,y),t = get(x,y+1),b = get(x,y-1),l = get(x-1,y),r = get(x+1,y);
        char t2 = get(x,y+2),b2 = get(x,y-2),l2 = get(x-2,y),r2 = get(x+2,y),lt = get(x-1,y+1),
                rt = get(x+1,y+1),lb = get(x-1,y-1),rb = get(x+1,y-1);
        set<char> rec = {t,b,l,r},record = rec,rec2 = {t2,b2,l2,r2,lt,rt,lb,rb};
        record.insert(dict.begin(),dict.end());
        if(x == 0 && y == 0) cout<<0<<endl;
        else if(c == 'A' || abs(abs(x)+abs(y)) == 1) cout<<1<<endl;
        else if(rec.find('A') != rec.end() || dict.find(c) != dict.end() || abs(abs(x)+abs(y)) == 2) cout<<2<<endl;
        else if(record.size() < (rec.size() + dict.size()) || (c-'A')%2 == 1
                || dict2.find(c) != dict2.end() || rec2.find('A') != rec2.end()) cout<<3<<endl;
        else cout<<4<<endl;
    }
    return 0;
}
