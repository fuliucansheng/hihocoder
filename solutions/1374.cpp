#include <bits/stdc++.h>
using namespace std;

int cal_res(int num_left, int num_right, char op){
    if(op == '+') return num_left + num_right;
    else if(op == '-') return num_left - num_right;
    else if(op == '*') return num_left * num_right;
    else return num_left / num_right;
}

int slove(string s){
    int currnum = 0;
    stack<int> stack_num;
    stack<char> stack_char;
    for(int i=0;i < s.size();i++){
        if((s[i]-'0')>=0 && (s[i]-'0')<=9) currnum *= 10, currnum += s[i]-'0';
        else if(s[i] == '(') stack_char.push(s[i]);
        else {
            if(s[i] == ')'){
                while(stack_char.top() != '('){
                    char op = stack_char.top();
                    int num_left = stack_num.top();
                    currnum = cal_res(num_left, currnum, op);
                    stack_char.pop(),stack_num.pop();
                }
                stack_char.pop();
            }
            if(!stack_char.empty() && (stack_char.top() == '*' || stack_char.top() == '/')){
                char op = stack_char.top();
                int num_left = stack_num.top();
                stack_num.pop(),stack_char.pop();
                currnum = cal_res(num_left, currnum, op);
            }
            if(!stack_char.empty() && (stack_char.top() == '-')) stack_char.pop(),stack_char.push('+'),currnum *= -1;
            if(s[i] != ')') stack_char.push(s[i]),stack_num.push(currnum),currnum = 0;
        }
    }
    while(!stack_num.empty()){
        char op = stack_char.top();
        int num_left = stack_num.top();
        currnum = cal_res(num_left, currnum, op);
        stack_char.pop(),stack_num.pop();
    }
    return currnum;
}

int main() {
    //freopen("../input.txt","r",stdin);
    string s;
    while(cin>>s){
        if(s == "END") return 0;
        cout<<slove(s)<<endl;
    }
    return 0;
}

