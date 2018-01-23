#include <iostream>
#include <queue>
#include <set>
#include <fstream>
using namespace std;
int main(){
    streambuf * inbuf = cin.rdbuf((new ifstream("input.txt"))->rdbuf());//重定向，OJ时将它注释掉
    typedef pair<int,int> point;
    int m,n;
    cin>>n>>m;
    point startpoint,stoppoint;
    char board[n][m];
    for(int b=0;b<n;b++){
        for(int c=0;c<m;c++){
            cin>>board[b][c];
            if(board[b][c] == 'S')
                startpoint = point(b,c);
            else if(board[b][c] == 'T')
                stoppoint = point(b,c);
        }
    }
    cout<<startpoint.first<<" "<<startpoint.second<<endl;
    cout<<stoppoint.first<<" "<<stoppoint.second<<endl;
    queue<point> list;
    list.push(startpoint);
    set<point> dict;
    dict.insert(startpoint);
    int res = 0;
    while(list.size() > 0){
        for(int i=list.size()-1;i>=0;i--){
            point p = list.front();
            int up = p.first,down = p.first,left = p.second,right = p.second;
            while(board[up][p.second] != '#' && board[up][p.second] != 'T' && up > -1) up--;
            if(up != p.first && (dict.find(make_pair(up+1,p.second)) == dict.end()) || make_pair(up,p.second) == stoppoint){
                if(make_pair(up+1,p.second) == stoppoint || make_pair(up,p.second) == stoppoint){
                    cout<<res<<endl;
                    return 0;
                }
                dict.insert(make_pair(up+1,p.second));
                list.push(make_pair(up+1,p.second));
            }
            while(board[down][p.second] != '#' && board[down][p.second] != 'T' && down < n) down++;
            if(down != p.first && (dict.find(make_pair(down-1,p.second)) == dict.end()) || make_pair(down,p.second) == stoppoint){
                if(make_pair(down-1,p.second) == stoppoint || make_pair(down,p.second) == stoppoint){
                    cout<<res<<endl;
                    return 0;
                }
                dict.insert(make_pair(down-1,p.second));
                list.push(make_pair(down-1,p.second));
            }
            while(board[p.first][left] != '#' && board[p.first][left] != 'T' && left > -1) left--;
            if(left != p.second && (dict.find(make_pair(p.first,left+1)) == dict.end()) || make_pair(p.first,left) == stoppoint){
                if(make_pair(p.first,left+1) == stoppoint || make_pair(p.first,left) == stoppoint){
                    cout<<res<<endl;
                    return 0;
                }
                dict.insert(make_pair(p.first,left+1));
                list.push(make_pair(p.first,left+1));
            }
            while(board[p.first][right] != '#' && board[p.first][right] != 'T' && right < m) right++;
            if(right != p.second && (dict.find(make_pair(p.first,right-1)) == dict.end()) || make_pair(p.first,right) == stoppoint){
                if(make_pair(p.first,right-1) == stoppoint || make_pair(p.first,right) == stoppoint){
                    cout<<res<<endl;
                    return 0;
                }
                dict.insert(make_pair(p.first,right-1));
                list.push(make_pair(p.first,right-1));
            }
            list.pop();
        }
        res++;
    }
    cout<<-1<<endl;
    return 0;
}
