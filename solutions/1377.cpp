#include <iostream>
#include <vector>
using namespace std;
typedef pair<string,string> ps;
int main(){
    //freopen("../input.txt", "r", stdin);
    int n, k;
    while(cin>>n){
        if(n == -1) break;
        cin>>k;
        string key, val;
        vector<ps> arr(n, ps("",""));
        for(int _=0;_<k;_++){
            string op; cin>>op;
            if(op == "SET") {
                cin>>key>>val;
                int rc = 0;
                for(int i=0;i<arr.size();i++) if(++rc && arr[i].first == key) break;
                for(int i=rc-1;i>0;i--) arr[i].first = arr[i-1].first, arr[i].second = arr[i-1].second;
                arr[0].first = key, arr[0].second = val;
            } else {
                cin>>key;
                int rc = 0;
                for(int i=0;i<arr.size();i++) if(++rc && arr[i].first == key) break;
                if(rc == n && arr[rc-1].first != key) cout<<"null"<<endl;
                else {
                    cout<<arr[rc-1].second<<endl;
                    string store = arr[rc-1].second;
                    for(int i=rc-1;i>0;i--) arr[i].first = arr[i-1].first, arr[i].second = arr[i-1].second;
                    arr[0].first = key, arr[0].second = store;
                }
            }
        }
    }
    return 0;
}
