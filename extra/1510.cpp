#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define inf 0x3f3f3f3f
#define clr(a,x) memset(a,x,sizeof(a))
using namespace std;

const int N=55,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

int m,dig[N];
ll n,dp[N][N][2][3][2],ans;
ll sum[N][N][2][3][2];

int fun(int b,int x,int y){
	if(x==y) return b;
	if(x<y) return 2;
	return 0;
}
inline void solve(){
	memset(dp,0,sizeof(dp));
	memset(sum,0,sizeof(sum));
//	debug(m);
	if(m==1){
		ans++;return;
	}
	dp[1][1][0][fun(1,0,dig[1])][0]=1;
	dp[1][0][0][fun(1,1,dig[1])][1]=1;
	sum[1][1][0][fun(1,0,dig[1])][0]=2;
	sum[1][0][0][fun(1,1,dig[1])][1]=2;
	for(int i=2;i<=m/2;i++){
		for(int j=0;j<=m;j++)
			for(int a=0;a<2;a++)
				for(int b=0;b<3;b++)
					for(int c=0;c<2;c++){
						ll k=dp[i-1][j][a][b][c],l=sum[i-1][j][a][b][c];
						if(!k) continue;
						//0,0
						dp[i][0][a|(dig[m-i+1]==1)][fun(b,0,dig[i])][0]+=k;
						sum[i][0][a|(dig[m-i+1]==1)][fun(b,0,dig[i])][0]+=l;
						//0,1
						dp[i][j+1][a|(dig[m-i+1]==1)][fun(b,1,dig[i])][c]+=k;
						sum[i][j+1][a|(dig[m-i+1]==1)][fun(b,1,dig[i])][c]+=l+k*(2-c);
						//1,0
						if(a||dig[m-i+1]==1){
							dp[i][j+1][a][fun(b,0,dig[i])][c]+=k;
							sum[i][j+1][a][fun(b,0,dig[i])][c]+=l+k*(2-c);
						}
						//1,1
						if(a||dig[m-i+1]==1){
							dp[i][0][a][fun(b,1,dig[i])][1]+=k;
							sum[i][0][a][fun(b,1,dig[i])][1]+=l+k*(2-j);
						}
					}
	}
	if(m&1){
		int i=m/2+1;
		for(int j=0;j<=m;j++)
			for(int a=0;a<2;a++)
				for(int b=0;b<3;b++)
					for(int c=0;c<2;c++){
						ll k=dp[i-1][j][a][b][c],l=sum[i-1][j][a][b][c];
						if(!k) continue;
						//0
						dp[i][0][a|(dig[m-i+1]==1)][b][0]+=k;
						sum[i][0][a|(dig[m-i+1]==1)][b][0]+=l;
						//1
						if(a||dig[m-i+1]==1){
							dp[i][0][a][b][0]+=k;
							sum[i][0][a][b][0]+=l+k*(1-j);
						}
					}
	}
	int i=(m+1)/2;
	for(int j=0;j<=m;j++)
		for(int a=0;a<2;a++)
			for(int b=0;b<3;b++)
				for(int c=0;c<2;c++){
					if(!a&&!b) continue;
					ll k=dp[i][j][a][b][c],l=sum[i][j][a][b][c];
					if(!k) continue;
//					printf("%d %d %d %d %d:%lld\n",i,j,a,b,c,k);
					ans+=l;
					if(c) ans-=k*j;
				}
}
int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
	time_tester(0);
#endif
	cin>>n;
#ifdef rqgao2014
/*	for(ll i=1;i<=n;i++){
		ll t=i,g=i;int a[20],m=0;
		while(t) a[m++]=t&1,t>>=1;
		m--;
		for(int j=0;j<=m;j++)
			g+=(a[j]<<m-j);
		ans+=__builtin_popcountll(g);
		debug(g);
	}debug(ans);ans=0;*/
#endif
	ll t=n;
	while(t) dig[++m]=t%2,t>>=1;
	solve();
	while(--m){
		for(int i=1;i<=m;i++) dig[i]=1;
		solve();
	}
	printf("%lld\n",ans);
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}



