#include <iostream>
using namespace std;
struct point{
    int rightvalue = 0;
    int downvalue = 0;
};
int main(){
    int m,n;
    cin>>n>>m;
    char maze[n][m];
    point rec[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>maze[i][j];
    }
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            int cost = 0,bn = 0;
            int rightmin = m*n, downmin = m*n;
            if(i==n-1 && j==m-1) rightmin=downmin=0;
            for(int r=j+1;r<m;r++){
                if(maze[i][r] == 'b') bn++;
                (r < (m-1) && maze[i][r+1] == '.') ? cost = 1 : cost = 0;
                if((cost + bn + rec[i][r].downvalue) < rightmin) rightmin = (cost + bn + rec[i][r].downvalue);
            }
            rec[i][j].rightvalue = rightmin;
            bn = 0;
            for(int c=i+1;c<n;c++){
                if(maze[c][j] == 'b') bn++;
                (c < (n-1) && maze[c+1][j] == '.') ? cost = 1 : cost = 0;
                if((cost + bn + rec[c][j].rightvalue) < downmin) downmin = (cost + bn + rec[c][j].rightvalue);
            }
            rec[i][j].downvalue = downmin;
        }

    }
    if(maze[0][1] == 'b'){
        cout<<(maze[0][0] =='b' ? 1+min(rec[0][0].rightvalue,rec[0][0].downvalue):min(rec[0][0].rightvalue,rec[0][0].downvalue))<<endl;
    }else{
        cout<<(maze[0][0] =='b' ? 1+min(rec[0][0].rightvalue,rec[0][0].downvalue+1):min(rec[0][0].rightvalue,rec[0][0].downvalue+1))<<endl;
    }
    return 0;
}
