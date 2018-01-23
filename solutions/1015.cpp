#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int kmp(string patt,string str){
    vector<int>arr(patt.size(),0);
    for(int i = 1;i < patt.size();i++){
        int curr = 0;
        int p = arr[i-1];
        if(p <= i-1){
            while(true){
                if(patt[p] == patt[i]){
                    curr = p + 1;
                    break;
                }else{
                    if(p == 0){
                        break;
                    }
                    p = arr[p-1];
                }
            }
        }
        arr[i] = curr;
    }
    int pt = 0,count = 0,strp = 0;
    while(strp < str.size()){
        if(patt[pt] == str[strp]){
            if(pt == patt.size()-1){
                count++;
                pt = arr[pt];
            }else{
                pt++;
            }
            strp++;
        }else{
            if(pt == 0){
                strp++;
            }else{
                pt = arr[pt-1];
            }
        }
    }
    return count;
}
int main() {
    int n;
    cin>>n;
    string patt,str;
    vector<int> result;
    for(int i=0;i<n;i++){
        cin>>patt>>str;
        result.push_back(kmp(patt,str));
    }
    for(auto r:result){
        cout<<r<<endl;
    }
    return 0;
}
