#include <bits/stdc++.h>
using namespace std;
#define MAXN 300

struct point{
	int x, y;
	point(int _x = 0, int _y = 0) : x(_x), y(_y){}
};

struct quadnode{
	const int NODE_CAPACITY;
	int boundary[4];
	//vector<point> points;
	point points[MAXN];
	int nextfree;
	quadnode *childnode[4];
	bool isdivided;
	int xmid, ymid;
	quadnode() : NODE_CAPACITY(200) , isdivided(false){
		for(int i = 0; i < 4; i++) childnode[i] = NULL;
		nextfree = 0;
	}
	quadnode(int x1, int y1, int x2, int y2) : NODE_CAPACITY(200), isdivided(false){
		boundary[0] = x1; boundary[1] = x2;
		boundary[2] = y1; boundary[3] = y2;
		for(int i = 0; i < 4; i++) childnode[i] = NULL;
		nextfree = 0;
	}
	bool inboundary(point p){
		return p.x >= boundary[0] && p.x < boundary[1] && p.y >= boundary[2] && p.y < boundary[3];
	}
	void divide(){
		if(isdivided) return ;
		xmid = (boundary[0] + boundary[1]) >> 1;
		ymid = (boundary[2] + boundary[3]) >> 1;
		childnode[0] = new quadnode(boundary[0], ymid, xmid, boundary[3]);
		childnode[1] = new quadnode(xmid, ymid, boundary[1], boundary[3]);
		childnode[2] = new quadnode(boundary[0], boundary[2], xmid, ymid);
		childnode[3] = new quadnode(xmid, boundary[2], boundary[1], ymid);
		isdivided = true;
	}
};

int dis2(point a, point b){
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool check(point p, point c, int r){
	return dis2(p, c) <= r * r;
}

void insert(quadnode *nownode, const point &p){
	if(!nownode->inboundary(p)) return ;
	if(nownode->nextfree < nownode->NODE_CAPACITY){
		//nownode->points.push_back(p);
		nownode->points[(nownode->nextfree)++] = p;
		return ;
	}else{
		nownode->divide();
		int i = ((p.y < nownode->ymid) << 1) | (p.x >= nownode->xmid);
		insert(nownode->childnode[i], p);

	}
}



void querry(quadnode *nownode, point a, int r, int &cnt){
	if(a.x + r < nownode->boundary[0] || a.y + r < nownode->boundary[2] ||
	   a.x - r > nownode->boundary[1] || a.y - r > nownode->boundary[3])
		return ;
	//int nums = nownode->points.size();
	int nums = nownode->nextfree;
	for(int i = 0; i < nums; i++){
        if(check(nownode->points[i], a, r))
            cnt++;	
	}
	if(nownode->isdivided){
		for(int i = 0; i < 4; i++){
			querry(nownode->childnode[i], a, r, cnt);
		}
	}
}

int n, m;

int main(){
	scanf("%d %d", &n, &m);
	int x, y;
	vector<point> points(n);
	int xmax = INT_MIN, xmin = INT_MAX, ymax = INT_MIN, ymin = INT_MAX;
	for(int i = 0; i < n; i++){
		scanf("%d %d", &points[i].x, &points[i].y);
		xmin = min(xmin, points[i].x); xmax = max(xmax, points[i].x);
		ymin = min(ymin, points[i].y); ymax = max(ymax, points[i].y);
	}
	xmin -= 1; xmax += 1; ymin -= 1; ymax += 1;
	quadnode *root = new quadnode(xmin, ymin, xmax, ymax);
	for(int i = 0; i < n; i++){
		insert(root, points[i]);
	}
	while(m--){
		int a, b, r, cnt = 0;
		scanf("%d %d %d", &a, &b, &r);
		point center(a, b);
		querry(root, center, r, cnt);
		printf("%d\n", cnt);
	}
	return 0;
}
