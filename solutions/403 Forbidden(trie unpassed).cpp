#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
typedef pair<string,bool> rule;
struct Treenode{
    bool value = true;
    int seq;
    Treenode *left = NULL;
    Treenode *right = NULL;
};
vector<string>* split(string s,string str){
    string::size_type last = 0;
    vector<string> *container = new vector<string>;
    string::size_type index = s.find_first_of(str,0);
    while(index != string::npos){
        container->push_back(s.substr(last,index-last));
        last = index + 1;
        index = s.find_first_of(str,last);
    }
    if(index - last > 0){
        container->push_back(s.substr(last,index - last));
    }
    return container;
}
void ruleconvert(rule &r){
    vector<string> *ipmask = split(r.first,"/");
    string ip = (*ipmask)[0];
    int mask = (*ipmask).size()>1 ? stoi((*ipmask)[1]) : 32;
    delete(ipmask);
    vector<string> *ipsplit = split(ip,".");
    string ns = "";
    for(int i=0;i<4;i++){
        int num = stoi((*ipsplit)[i]);
        string ts = "";
        for(int j=0;j<8;j++){
            string rest = to_string(num%2);
            num /= 2;
            ts = rest + ts;
        }
        ns += ts;
    }
    delete(ipsplit);
    r.first = ns.substr(0,mask);
}
void treebuild(Treenode *&root,vector<rule> rs){
    root->seq = rs.size();
    for(int i=0;i<rs.size();i++){
        Treenode *point = root;
        string rulepre = rs[i].first;
        bool ruleval = rs[i].second;
        for(int k=0;k<rulepre.size();k++){
            if(rulepre[k] == '0'){
                if(point->left == NULL){
                    Treenode *nl = new Treenode();
                    nl->seq = rs.size();
                    point->left = nl;
                }
                point = point->left;
            }else{
                if(point->right == NULL){
                    Treenode *nr = new Treenode();
                    nr->seq = rs.size();
                    point->right = nr;
                }
                point = point->right;
            }
        }
        if(point->seq > i){
            point->value = ruleval;
            point->seq = i;
        }
    }
}
bool treesearch(Treenode *root,string filterip,int maxseq){
    Treenode *point = root;
    int minseq = maxseq;
    int res = true;
    for(int i=0;i<filterip.size();i++){
        if(point->seq < minseq){
            minseq = point->seq;
            res = point->value;
        }
        if(filterip[i] == '0'){
            if(point->left == NULL){
                break;
            }
            point = point->left;
        }else{
            if(point->right == NULL){
                break;
            }
            point = point->right;
        }
    }
    return res;
}
int main(){
    streambuf * inbuf = cin.rdbuf((new ifstream("input.txt"))->rdbuf());//重定向，OJ时将它注释掉
    int m,n;
    cin>>n>>m;
    vector<rule> rules,fips;
    for(int p=0;p<n;p++){
        string d,r;
        cin>>d>>r;
        if(d == "allow"){
            rules.push_back(rule(r,true));
        }else{
            rules.push_back(rule(r,false));
        }
    }
    for(int q=0;q<m;q++){
        string ip;
        cin>>ip;
        fips.push_back(rule(ip,true));
    }
    for(int i=0;i<rules.size();i++){
        ruleconvert(rules[i]);
    }
    Treenode *root = new Treenode();
    treebuild(root,rules);
    for(int t=0;t<fips.size();t++){
        ruleconvert(fips[t]);
        bool res = treesearch(root,fips[t].first,rules.size());
        if(res){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    delete(root);
    return 0;
}
