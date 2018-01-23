#include <iostream>
using namespace std;
//0 < //1 <= //2 = //3 >//4 >=
struct node{
    int c;
    int type;
};
bool is_valid(double x, node d){
    if(d.type == 0) return x < d.c;
    else if(d.type == 1) return x <= d.c;
    else if(d.type == 2) return x == d.c;
    else if(d.type == 3) return x > d.c;
    else if(d.type == 4) return x >= d.c;
}
int main(){
    //freopen("../input.txt","r",stdin);
    int n, cc, res = 0;
    cin>>n;
    node rec[n];
    string xx,op;
    for(int i=0;i<n;i++){
        cin>>xx>>op>>cc;
        if(op == "<") rec[i].type = 0;
        else if(op == "<=") rec[i].type = 1;
        else if(op == "=") rec[i].type = 2;
        else if(op == ">") rec[i].type = 3;
        else if(op == ">=") rec[i].type = 4;
        rec[i].c = cc;
    }
    for(double x=-0.5;x<1002;x+=0.5){
        int c = 0;
        for(int i=0;i<n;i++) if(is_valid(x, rec[i])) c++;
        res = max(res, c);
    }
    cout<<res<<endl;
    return 0;
}
