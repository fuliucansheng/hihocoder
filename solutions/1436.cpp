#include <bits/stdc++.h>
using namespace std;
struct geohash{
    map<int,char> dict; map<char,int> idict;
    map<int,string> sdict; map<string,int> sidict;
    void init(){
        char s;
        int c = 0;
        set<char> rc = { 'a', 'i', 'l', 'o' };
        for(s='0';s<='9';s++) if(!rc.count(s)) dict[c] = s, idict[s] = c++;
        for(s='a';s<='z';s++) if(!rc.count(s)) dict[c] = s, idict[s] = c++;
        for(int i=0;i<32;i++){
            string str = "00000";
            for(int j=0;j<5;j++) if(i&(1<<j)) str[4-j] = '1';
            sdict[i] = str, sidict[str] = i;
        }
    }
    string encode(double lat, double lon){
        string lon_s = "", lat_s = "";
        double lon_l = -180, lon_r = 180, lat_l = -90, lat_r = 90;
        for(int i=0;i<25;i++){
            double m = (lon_l + lon_r) / 2;
            if(lon < m) lon_s += '0', lon_r = m; else lon_s += '1', lon_l = m;
        }
        for(int i=0;i<25;i++){
            double m = (lat_l + lat_r) / 2;
            if(lat < m) lat_s += '0', lat_r = m; else lat_s += '1', lat_l = m;
        }
        string b_s = "", rs = "";
        for(int i=0;i<25;i++) b_s += lon_s[i], b_s += lat_s[i];
        for(int i=0;i<50;i+=5) rs += dict[sidict[b_s.substr(i, 5)]];
        return rs;
    }
    pair<double, double> decode(string p){
        string b_s = "";
        for(auto c:p) b_s += sdict[idict[c]];
        string lon_s = "", lat_s = "";
        for(int i=0;i<int(b_s.size());i++) if(i%2 == 0) lon_s += b_s[i]; else lat_s += b_s[i];
        double lon_l = -180, lon_r = 180, lat_l = -90, lat_r = 90;
        for(int i=0;i<int(lon_s.size());i++){
            double m = (lon_l + lon_r) / 2;
            if(lon_s[i] == '0') lon_r = m; else lon_l = m;
        }
        for(int i=0;i<int(lat_s.size());i++){
            double m = (lat_l + lat_r) / 2;
            if(lat_s[i] == '0') lat_r = m; else lat_l = m;
        }
        return make_pair((lat_l + lat_r) / 2, (lon_l + lon_r) / 2);
    };
} gh;
int main() {
    //freopen("../input.txt", "r", stdin);
    gh.init();
    int n, m; cin>>n>>m;
    for(int i=0;i<n;i++){
        double x, y; cin>>x>>y;
        cout<<gh.encode(x, y)<<endl;
    }
    for(int i=0;i<m;i++){
        string s; cin>>s;
        pair<double,double> r = gh.decode(s);
        cout<<fixed<<setprecision(6)<<r.first<<" "<<r.second<<endl;
    }
    return 0;
}
