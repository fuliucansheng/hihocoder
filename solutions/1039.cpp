#include <iostream>
#include <algorithm>
using namespace std;
int reststr(string str){
    string restr = "";
    while(str.size() > 0){
        char chr = str[0];
        int count = 1;
        for(int i=1;i<str.size();i++){
            if(str[i] == chr) count++;
            else{
                if(count == 1) restr += chr;
                else count = 1;
                chr = str[i];
            }
        }
        if(count == 1) restr += chr;
        if(str.size() == restr.size()) break;
        else str = restr,restr = "";
    }
    return restr.size();
}
int solve(string str){
    int maxres = 0;
    string A("A"),B("B"),C("C");
    for(int i=0;i<=str.size();i++){
        string pre = str.substr(0,i);
        string rst = str.substr(i);
        string newstrA = pre + A + rst,newstrB = pre + B + rst,newstrC = pre + C + rst;
        int sizeA = reststr(newstrA),sizeB = reststr(newstrB),sizeC = reststr(newstrC);
        //cout<<newstrA<<" "<<sizeA<<" "<<newstrB<<" "<<sizeB<<" "<<newstrC<<" "<<sizeC<<endl;
        int minrest = min(sizeA,min(sizeB,sizeC));
        if((str.size()+1-minrest) > maxres) maxres = (str.size()+1-minrest);
    }
    return maxres;
}
int main(){
    //freopen("../input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int res = solve(str);
        cout<<res<<endl;
    }
    return 0;
}
