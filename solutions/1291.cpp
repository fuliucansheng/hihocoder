#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
struct point{
    int x,y,z;
    point(){}
    point(int xx,int yy,int zz){
        x = xx,y = yy,z = zz;
    }
    bool judge(){
        return x>=0&&x<102&&y>=0&&y<102&&z>0&&z<102;
    }
};
void floodfill(point x,int dict[102][102][102]){
    stack<point> list;
    list.push(x);
    while(!list.empty()){
        point cpt = list.top();
        list.pop();
        point cptf = point(cpt.x-1,cpt.y,cpt.z);
        if(cptf.judge() && dict[cptf.x][cptf.y][cptf.z] == 0) list.push(cptf),dict[cptf.x][cptf.y][cptf.z] = 2;
        cptf = point(cpt.x+1,cpt.y,cpt.z);
        if(cptf.judge() && dict[cptf.x][cptf.y][cptf.z] == 0) list.push(cptf),dict[cptf.x][cptf.y][cptf.z] = 2;
        cptf = point(cpt.x,cpt.y-1,cpt.z);
        if(cptf.judge() && dict[cptf.x][cptf.y][cptf.z] == 0) list.push(cptf),dict[cptf.x][cptf.y][cptf.z] = 2;
        cptf = point(cpt.x,cpt.y+1,cpt.z);
        if(cptf.judge() && dict[cptf.x][cptf.y][cptf.z] == 0) list.push(cptf),dict[cptf.x][cptf.y][cptf.z] = 2;
        cptf = point(cpt.x,cpt.y,cpt.z-1);
        if(cptf.judge() && dict[cptf.x][cptf.y][cptf.z] == 0) list.push(cptf),dict[cptf.x][cptf.y][cptf.z] = 2;
        cptf = point(cpt.x,cpt.y,cpt.z+1);
        if(cptf.judge() && dict[cptf.x][cptf.y][cptf.z] == 0) list.push(cptf),dict[cptf.x][cptf.y][cptf.z] = 2;
    }
}
int main() {
    //freopen("../input.txt","r",stdin);
    int m,n;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>n;
        int dict[102][102][102] = {0};
        stack<point> plist;
        bool status = true;
        for(int j=0;j<n;j++){
            int x,y,z;
            cin>>x>>y>>z;
            if(status && dict[x][y][z] == 0 && (z == 1 || dict[x][y][z-1] || dict[x][y][z+1] || dict[x-1][y][z]
               || dict[x+1][y][z] || dict[x][y-1][z] || dict[x][y+1][z])){
                dict[x][y][z] = 1;
            }else if(status){
                cout<<"No"<<endl;
                status = false;
            }
            plist.push(point(x,y,z));
        }
        if(!status) continue;
        dict[101][101][101] = 2;
        floodfill(point(101,101,101),dict);
        while(!plist.empty()){
            point cpt = plist.top();
            plist.pop();
            int x = cpt.x,y = cpt.y,z = cpt.z;
            if(dict[x][y][z-1] == 2 || dict[x][y][z+1] == 2 || dict[x-1][y][z] == 2
               || dict[x+1][y][z] == 2 || dict[x][y-1][z] == 2 || dict[x][y+1][z] == 2){
                dict[x][y][z] = 2;
                floodfill(cpt,dict);
            }else{
                cout<<"No"<<endl;
                status = false;
                break;
            }
        }
        if(status) cout<<"Yes"<<endl;
    }
    return 0;
}
