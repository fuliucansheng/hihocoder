#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class trienode{
public:
    char value;
    int count = 0;
    vector<trienode*> arr;
};
int main() {
    int n,m;
    vector<string> chr,search;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        chr.push_back(s);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        search.push_back(s);
    }
    trienode  *root = new trienode();
    for(string ch:chr){
        trienode *point = root;
        for(char s:ch){
            auto res = find_if(point->arr.begin(),point->arr.end(),[s](trienode *it){ return it->value == s;});
            if(res != point->arr.end()){
                point = *res;
            }else{
                trienode *newnode = new trienode();
                newnode->value = s;
                point->arr.push_back(newnode);
                point = point->arr.back();
            }
            point->count++;
        }
    }
    for(string sh:search){
        int result = 0;
        trienode *pt = root;
        for(char ss:sh){
            auto res = find_if(pt->arr.begin(),pt->arr.end(),[ss](trienode *it){ return it->value == ss;});
            if(res != pt->arr.end()){
                pt = *res;
                result = pt->count;
            }else{
                result = 0;
                break;
            }
        }
        cout<<result<<endl;
    }
    return 0;
}
