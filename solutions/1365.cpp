#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 1e5+50;
typedef pair<int,int> image;
struct state{
    int his_height, curr_height, rest_width;
    state(){}
    state(int hh,int ch,int rw):his_height(hh),curr_height(ch),rest_width(rw){}
};
image img[maxn];
state pre[maxn];
int m, n, suf[maxn];
int height(int ft){
    int his_weight = (ft>0?pre[ft-1].his_height:0), curr_height = (ft>0?pre[ft-1].curr_height:0), rest_width = (ft>0?pre[ft-1].rest_width:m);
    if(rest_width == m) return his_weight + suf[ft+1];
    for(int i=ft+1;i<n;i++){
        if(img[i].first <= rest_width) curr_height = max(curr_height, img[i].second), rest_width -= img[i].first;
        else if(rest_width > 0) {
            int nh = int(ceil(1.0*img[i].second*rest_width/img[i].first));
            curr_height = max(curr_height, nh), rest_width = 0;
        }
        if(rest_width == 0) {
            his_weight += curr_height, curr_height = 0, rest_width = m;
            his_weight += suf[i+1];
            break;
        }
    }
    his_weight += curr_height;
    return his_weight;
}
void dict_init(){
    int his_height = 0, curr_height = 0, rest_width = m;
    for(int i=0;i<n;i++){
        if(img[i].first <= rest_width) curr_height = max(curr_height, img[i].second), rest_width -= img[i].first;
        else if(rest_width > 0) {
            int nh = int(ceil(1.0*img[i].second*rest_width/img[i].first));
            curr_height = max(curr_height, nh), rest_width = 0;
        }
        if(rest_width == 0) his_height += curr_height, curr_height = 0, rest_width = m;
        pre[i] = state(his_height,curr_height,rest_width);
    }
    for(int i=n-1;i>=0;i--){
        his_height = 0, curr_height = 0, rest_width = m;
        for(int j=i;j<n;j++){
            if(img[j].first <= rest_width) curr_height = max(curr_height, img[j].second), rest_width -= img[j].first;
            else if(rest_width > 0) {
                int nh = int(ceil(1.0*img[j].second*rest_width/img[j].first));
                curr_height = max(curr_height, nh), rest_width = 0;
            }
            if(rest_width == 0) {
                his_height += curr_height, curr_height = 0, rest_width = m;
                his_height += suf[j+1];
                break;
            }
        }
        suf[i] = his_height + curr_height;
    }
}
int main(){
    //freopen("../input.txt","r",stdin);
    memset(suf, 0, sizeof(suf));
    cin>>m>>n;
    for(int i=0;i<n;i++) cin>>img[i].first>>img[i].second;
    dict_init();
    int res = INT32_MAX;
    for(int i=0;i<n;i++) res = min(res, height(i));
    cout<<res<<endl;
    return 0;
}
