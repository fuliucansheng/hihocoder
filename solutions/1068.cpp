#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
struct SparseTableRMQ{
    int arr[maxn][20], n;
    void build(){
        int l = int(log2(n));
        for(int j=1;j<=l;j++)
            for(int i=1;(i+(1<<(j-1))-1)<=n;i++)
                arr[i][j] = min(arr[i][j-1],arr[i+(1<<(j-1))][j-1]);
    }
    int query(int l, int r){
        int k=int(log2(r-l+1));
        return min(arr[l][k],arr[r-(1<<k)+1][k]);
    }
} ST;

int main(){
    //freopen("../input.txt","r",stdin);
    scanf("%d", &ST.n);
    for(int i=1;i<=ST.n;i++) scanf("%d", &ST.arr[i][0]);
    ST.build();
    int Q,l,r;
    scanf("%d", &Q);
    for(int i=0;i<Q;i++) scanf("%d%d", &l, &r),printf("%d\n", ST.query(l,r));
    return 0;
}