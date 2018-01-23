#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++){
        cin>>arr[i+1];
    }
    int maxlen = 1;
    set<int> dict;
    for(int j=1;j<=n;j++){
        if(dict.find(arr[j])==dict.end()){
            vector<int> q = {arr[j]};
            while(arr[q[q.size()-1]] != q[0]){
                dict.insert(arr[q[q.size()-1]]);
                q.push_back(arr[q[q.size()-1]]);
            }
            if(q.size() > maxlen){
                maxlen = q.size();
            }
        }
    }
    cout<<maxlen<<endl;
    return 0;
}

