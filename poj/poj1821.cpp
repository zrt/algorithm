#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int dp[105][16005];
int n,k;
struct Man{
	int l,p,s;
}man[105];
bool cmp(Man a,Man b){
	return a.s<b.s;
}
struct N{
	int x,w;
	N(int pos=0,int val=0){
		x=pos,w=val;
	}
};
struct dddl{
	N q[16005];
	int h,t;
	void clear(){
		h=t=0;
	}
	void insert(N a){
		while(h!=t&&q[t-1].w<=a.w) t--;
		q[t++]=a;
	}
	void pop(int pos){
		if(h!=t&&q[h].x<=pos) h++;
	}
	int ask(){
		return q[h].x;
	}
}q;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(~scanf("%d%d",&n,&k)){
		for(int i=1;i<=k;i++){
			scanf("%d%d%d",&man[i].l,&man[i].p,&man[i].s);
		}
		q.clear();
		
		sort(man+1,man+k+1,cmp);
		for(int i=1;i<=k;i++){
			for(int j=0;j<man[i].s&&j<=n;j++){
				dp[i][j]=dp[i-1][j];
			}
			q.clear();
			for(int j=max(man[i].s-man[i].l,0);j<man[i].s&&j<=n;j++){
				q.insert(N(j,dp[i-1][j]-j*man[i].p));
			}
			for(int j=man[i].s;j<man[i].s+man[i].l&&j<=n;j++){
				q.pop(j-man[i].l-1);
				dp[i][j]=max(dp[i][j-1],max(dp[i-1][j],dp[i-1][q.ask()]+(j-q.ask())*man[i].p));
			}
			for(int j=man[i].s+man[i].l;j<=n;j++){
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++) ans=max(ans,dp[k][i]);
		printf("%d\n",ans);
	}
	return 0;
}
