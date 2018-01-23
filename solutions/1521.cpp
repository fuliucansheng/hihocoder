#include <iostream>
#include <stack>
using namespace std;
struct op{
    op(){}
    op(int i){
        index = i,tp = false;
    }
    op(int f,int t,int m){
        from = f,to = t,mul = m,tp = true;
    }
    bool tp;
    int from;
    int to;
    int mul;
    int index;
};
int main() {
    freopen("../input.txt","r",stdin);
    int n;cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) arr[i][j] = 0;
    for(int i=0;i<n;i++){
        cin>>arr[0][i];
        if(i > 0) arr[i][i] = 1;
    }
    if(n == 1){
        if(arr[0][0] == 1) cout<<arr[0][0]<<endl;
        else cout<<"No"<<endl;
        return 0;
    }
    int flag = 0;
    stack<op> opseq;
    if(arr[0][0] < 0) arr[0][0] *= -1,opseq.push(op(0)),flag++;
    for(int i=1;i<n;i++){
        if(arr[0][i] < 0) arr[0][i] *= -1,opseq.push(op(i)),flag++;
        while(arr[0][i] != 0){
            if(arr[0][i] >= arr[0][0] && arr[0][0] != 0){
                int mul = arr[0][i]/arr[0][0];
                arr[0][i] -= arr[0][0]*mul;
                opseq.push(op(0,i,mul));
            }else if(arr[0][0] == 0){
                arr[0][0] += arr[0][i];
                opseq.push(op(i,0,-1));
            }else{
                int mul = arr[0][0]/arr[0][i];
                arr[0][0] -= arr[0][i]*mul;
                opseq.push(op(i,0,mul));
            }
        }
    }
    if(flag % 2 == 1) arr[1][1] *= -1;
    if(arr[0][0] != 1) cout<<"No"<<endl;
    else{
        while(opseq.size() > 0){
            op curr = opseq.top();
            if(curr.tp){
                for(int i=0;i<n;i++) arr[i][curr.to] += arr[i][curr.from]*curr.mul;
            }else{
                for(int i=0;i<n;i++) arr[i][curr.index] *= -1;
            }
            opseq.pop();
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cout<<arr[i][j]<<(j!=n-1?" ":"");
            cout<<endl;
        }
    }
    return 0;
}
