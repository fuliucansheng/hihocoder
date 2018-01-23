#include <iostream>
using namespace std;
void print(char s, int n){
    for(int i=0;i<n;i++) cout<<s;
}
int main(){
    //freopen("../input.txt","r",stdin);
    int n;
    cin>>n;
    print(' ', n);print('_', n);print(' ', 3*n);print('_', n);print('\n',1);
    for(int i=1;i<=n;i++) {
        print(' ', n-i);print('/', 1);print(' ', 2*(i-1)+n);print('\\', 1);
        if(i == n) print('_', n); else print(' ', 3*n-2*i);
        print('/', 1);print(' ', 2*(i-1)+n);print('\\', 1);print('\n',1);
    }
    for(int i=1;i<=n;i++) {
        print('|',1);print(' ',7*n-2);print('|',1);print('\n',1);
    }
    for(int i=1;i<=(3*n);i++){
        print(' ',i-1);print('\\',1);
        if(i == (3*n)) print('_', n); else print(' ',7*n-2*i);
        print('/',1);print('\n',1);
    }
    return 0;
}
