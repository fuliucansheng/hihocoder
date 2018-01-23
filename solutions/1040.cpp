#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int,int> point;
typedef pair<point,point> oppoint;
long long distance(point x,point y){
    long long xx = y.first - x.first,yy = y.second - x.second;
    return xx*xx+yy*yy;
}
int main(){
    //freopen("../input.txt","r",stdin);
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        map<point,oppoint> dict;
        for(int j=0;j<4;j++){
            oppoint tmp;
            point start,stop;
            cin>>start.first>>start.second>>stop.first>>stop.second;
            if(dict.find(start) == dict.end()) dict[start] = tmp,dict[start].first = stop;
            else dict[start].second = stop;
            if(dict.find(stop) == dict.end()) dict[stop] = tmp,dict[stop].first = start;
            else dict[stop].second = start;
        }
        int res = true;
        for(auto dt:dict){
            point curr = dt.first,oppot1 = dt.second.first,oppot2 = dt.second.second;
            if(distance(curr,oppot1)+distance(curr,oppot2) != distance(oppot1,oppot2)){
                res = false;
                break;
            }
        }
        cout<<(res?"YES":"NO")<<endl;
    }
    return 0;
}
