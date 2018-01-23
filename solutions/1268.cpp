#include <iostream>
#include <cstring>
using namespace std;
int arr[3][3];
int cross(int a,int b){
    if(min(a, b) == 1 && max(a, b) == 3) return 8;
    if(min(a, b) == 1 && max(a, b) == 7) return 6;
    if(min(a, b) == 3 && max(a, b) == 9) return 4;
    if(min(a, b) == 7 && max(a, b) == 9) return 2;
    return -1;
}
int search(int i,int j){
    if(arr[2-i][2-j] != 0) return 10-arr[2-i][2-j];
    int c = 0,s = 0;
    for(int a=0;a<3;a++) if(arr[a][j] != 0) c++, s+=arr[a][j];
    if(c == 2) return 15-s;
    c = 0,s = 0;
    for(int b=0;b<3;b++) if(arr[i][b] != 0) c++, s+=arr[i][b];
    if(c == 2) return 15-s;
    if(i == 0 && j == 0) return cross(arr[i+1][j], arr[i][j+1]);
    if(i == 0 && j == 3) return cross(arr[i+1][j], arr[i][j-1]);
    if(i == 3 && j == 0) return cross(arr[i-1][j], arr[i][j+1]);
    if(i == 3 && j == 3) return cross(arr[i-1][j], arr[i][j-1]);
    return -1;
}
int main(){
    //freopen("../input.txt","r",stdin);
    memset(arr, 0, sizeof(arr));
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) cin>>arr[i][j];
    bool status = true, res = true;
    while(status){
        status = false;
        for(int i=0;i<3;i++) for(int j=0;j<3;j++) if(arr[i][j] == 0 && search(i,j) != -1) arr[i][j] = search(i,j), status = true;
    }
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) if(arr[i][j] == 0) res = false;
    if(!res) cout<<"Too Many"<<endl;
    else{
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++) cout<<arr[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
