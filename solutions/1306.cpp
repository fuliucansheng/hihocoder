#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
int main(){
    //freopen("../input.txt","r",stdin);
    int n,time,price;
    char op;
    cin>>n;
    set<int> pset;
    map<int,int> dict;
    map<int,int> prec;
    while(n--){
        cin>>op;
        if(op == 'P'){
            cin>>time>>price;
            dict[time] = price;
            if(prec.find(price) == prec.end()) prec[price] = 1,pset.insert(price);
            else prec[price]++;
        }else if(op == 'Q'){
            cout<<*(pset.rbegin())<<" "<<*(pset.begin())<<" "<<dict.rbegin()->second<<endl;
        }else if(op == 'R'){
            cin>>time;
            while(dict.begin()->first <= time){
                int prce = dict.begin()->second;
                if(prec[prce] == 1) prec.erase(prce),pset.erase(prce);
                else prec[prce]--;
                dict.erase(dict.begin());
            }
        }
    }
    return 0;
}
