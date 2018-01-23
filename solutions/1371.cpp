#include <iostream>
using namespace std;
class node{
public:
    int value;
    node* next;
};
int main(){
    //freopen("../input.txt", "r", stdin);
    int n;
    while(cin>>n){
        if(n == -1) break;
        node r;
        node *p = &r, *rp = new node();
        for(int i=0;i<n;i++) {
            p->next = new node();
            cin>>p->value, p = p->next;
        }
        p = &r;
        while(p->next){
            node *tp = new node();
            tp->value = p->value;
            tp->next = rp->next;
            rp->next = tp;
            p = p->next;
        }
        rp = rp->next;
        while(rp) cout<<rp->value<<" ", rp = rp->next;
        cout<<endl;
    }
    return 0;
}

