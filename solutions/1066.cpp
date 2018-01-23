#include <iostream>
#include <map>
using namespace std;
const int MAXN = 1e5 + 10;
int group[MAXN];
map<string,int> dict;
int find_group(int x){
    return (x == group[x] ? x : find_group(group[x]));
}
void union_group(int x, int y){
    int dx = find_group(x), dy = find_group(y);
    group[dy] = group[dx] = min(dx,dy);
}

int main(){
    //freopen("../input.txt", "r", stdin);
    int N, op, count = 0;
    cin>>N;
    string name1,name2;
    while(N--){
        cin>>op>>name1>>name2;
        if(dict.find(name1) == dict.end()) group[count] = count,dict[name1] = count++;
        if(dict.find(name2) == dict.end()) group[count] = count,dict[name2] = count++;
        int n1 = dict[name1],n2 = dict[name2];
        if(op == 0) union_group(n1,n2);
        else cout<<(find_group(n1)==find_group(n2) ? "yes" : "no")<<endl;
    }
    return 0;
}
