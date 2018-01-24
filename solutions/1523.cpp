#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    //freopen("../input.txt","r",stdin);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int max = 0,count = 0,dictmax = 0;
    set<int> dict;
    while(true){
        int ds = dict.size();
        max = dictmax;
        for(int i=0;i<n;i++){
            if(dict.find(arr[i]) == dict.end()){
                if(arr[i] > max){
                    max = arr[i];
                }else{
                    count++;
                    if(arr[i] > dictmax) dictmax = arr[i];
                    dict.insert(arr[i]);
                }
            }
        }
        if(ds == dict.size()) break;
    }
    cout<<count<<endl;
    return 0;
}
