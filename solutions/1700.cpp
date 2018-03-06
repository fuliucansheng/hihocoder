#include <bits/stdc++.h>
using namespace std;
struct node{
    int a, b, c;
    node(){};
    node(int aa, int bb, int cc):a(aa), b(bb), c(cc){};
    bool plusone(){
        if(c < 16) c++;
        else if(b < 16) b++, c = 0;
        else if(a < 16) a++, b = c = 0;
        else return false;
        return true;
    }
    int get_dis(node aa){
        return (aa.a - a*17)*(aa.a - a*17) + (aa.b - b*17)*(aa.b - b*17) + (aa.c - c*17)*(aa.c - c*17);
    }
};
int get_num(char a, char b){
    int aa = a >= 'a' ? a - 'a' + 10 : a - '0';
    int bb = b >= 'a' ? b - 'a' + 10 : b - '0';
    return aa * 16 + bb;
}
char get_char(int b){
    if(b > 9) return b - 10 + 'a';
    return b + '0';
}
int main(){
    //freopen("../input.txt", "r", stdin);
    string s; cin>>s;
    node a(get_num(s[1],s[2]), get_num(s[3], s[4]), get_num(s[5], s[6])), b(0,0,0), rs;
    int ds = INT32_MAX;
    do{
        int d = b.get_dis(a);
        if(d < ds) ds = d, rs = b;
    }while(b.plusone());
    cout<<"#"<<get_char(rs.a)<<get_char(rs.b)<<get_char(rs.c)<<endl;
    return 0;
}
