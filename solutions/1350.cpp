#include <iostream>
#include <map>
using namespace std;
int lowerbit(int x){
    return x&-x;
}
int main(){
    //freopen("../input.txt","r",stdin);
    map<int,int> dict;
    for(int i=0;i<60;i++){
        int c = 0, n = i;
        while(n) n-=lowerbit(n),c++;
        dict[i] = c;
    }
    int x;
    cin>>x;
    for(int h=0;h<24;h++) for(int m=0;m<60;m++) if(dict[h]+dict[m] == x) cout<<(h<10?"0":"")<<h<<":"<<(m<10?"0":"")<<m<<endl;
    return 0;
}
