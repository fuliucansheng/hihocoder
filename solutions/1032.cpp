#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int longest(string str) {
    if (str.size() == 0) {
        return 0;
    }
    vector<int> chrnum;
    vector<char> chr;
    for(int i=0;i<str.size();i++){
        if(i == 0 || str[i] != str[i-1]){
            chr.push_back(str[i]);
            chrnum.push_back(1);
        }else{
            chrnum[chrnum.size()-1]++;
        }
    }
    int maxlen = 1;
    for(int r=0;r<chr.size();r++){
        if(r ==0 || r == (chr.size()-1) || chr[r-1] != chr[r+1]){
            maxlen = max(maxlen,chrnum[r]);
        }else{
            int len = chrnum[r],l=1;
            while((r-l)>0 && (r+l)<(chr.size()-1) && (chr[r-l] == chr[r+l] && chrnum[r-l] == chrnum[r+l])){
                len += 2*chrnum[r-l];
                l++;
            }
            if(chr[r-l] == chr[r+l]){
                len += 2*min(chrnum[r-l],chrnum[r+l]);
            }
            if(len > maxlen){
                maxlen = len;
            }
        }
    }
    return maxlen;
}
int main() {
    vector<int> result;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string ss;
        cin>>ss;
        result.push_back(longest(ss));
    }
    for(int j=0;j<result.size();j++){
        cout<<result[j]<<endl;
    }
    return 0;
}

