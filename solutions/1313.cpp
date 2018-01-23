#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 101;
string arr[maxn];
int cnt[maxn], pos[maxn];
int main(){
    //freopen("../input.txt","r",stdin);
    memset(cnt, 0, sizeof(cnt)); memset(pos, -1, sizeof(pos));
    int k; cin>>k;
    for(int i=0;i<k;i++) cin>>arr[i];
    for(int i=0;i<k;i++) {
        for(int j=0;j<int(arr[i].size());j++) if(arr[i][j] == 'o'){
                cnt[i]++;
                if(pos[i] == -1) pos[i] = j;
            }
        if(pos[i] == -1) pos[i] = int(arr[i].size());
    }
    int rs = 0, ch = 0, chcc;
    for(int i=0;i<k;i++) {
        int curr = int(arr[i].size()) - pos[i] - cnt[i];
        chcc = int(arr[ch].size()) - pos[ch] - cnt[ch];
        if(curr < chcc) ch = i, chcc = curr;
    }
    for(int i=0;i<k;i++){
        if(i != ch) rs += int(arr[i].size()) - pos[i];
        else rs += cnt[i], rs += 2 * chcc;
    }
    cout<<rs<<endl;
    return 0;
}
