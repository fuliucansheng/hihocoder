#include <iostream>
using namespace std;

string solve(string pre,string mid){
    if(pre.size() == 0) return "";
    char first = pre[0];
    int pos = mid.find(first);
    string nfpre = pre.substr(1,pos),nlpre = pre.substr(pos+1);
    string nfmid = mid.substr(0,pos),nlmid = mid.substr(pos+1);
    return solve(nfpre,nfmid) + solve(nlpre,nlmid) + first;
}

int main() {
    //freopen("../input.txt","r",stdin);
    string preorder,midorder;
    cin>>preorder>>midorder;
    string res = solve(preorder,midorder);
    cout<<res<<endl;
    return 0;
}
