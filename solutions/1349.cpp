#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;
int main(){
    //freopen("../input.txt", "r", stdin);
    ll n; cin>>n;
    if(n == 0) return cout<<0<<endl, 0;
    ll s, num, rs, i;
    s = 0, num = 9, i = 1;
    while(n >= s + num*i) s += num*i, i++, num *= 10;
    n -= s;
    num = num/9 - 1, num += n/i, n %= i;
    if(n == 0) return cout<<num%10<<endl, 0;
    num++;
    stack<int> stk;
    while(num) stk.push(num%10), num /= 10;
    while(n) rs = stk.top(), stk.pop(), n--;
    cout<<rs<<endl;
    return 0;
}

