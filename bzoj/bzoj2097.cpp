#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
int H[100005],X[200005],P[200005],tot;
int n,m;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int lim;
int cnt;
int dp[100005];
/*
void dfs(int x,int fa){
	dp[x]=0;
	int tmp=-1;
	for(int i=H[x];i;i=X[i]){
		if(P[i]!=fa){
			dfs(P[i],x);
			if(dp[P[i]]+1>lim){
				cnt++;continue;
			}
			if(tmp!=-1&&dp[P[i]]+tmp+2>lim){
				cnt++;continue;
			}
			tmp=max(tmp,dp[P[i]]);
		}
	}
	dp[x]=tmp+1;
}
*/
bool cmp(int a,int b){
	return a>b;
}
void dfs(int x,int fa){
	vector<int> a;
	dp[x]=0;
	for(int i=H[x];i;i=X[i]) if(P[i]!=fa) dfs(P[i],x),a.push_back(dp[P[i]]);
	sort(a.begin(),a.end(),cmp);
	if(a.size()){
		int i=0;
		for(;i<a.size();i++){
			if(a[i]+1>lim){
				cnt++;
			}else if(i+1<a.size()&&a[i]+a[i+1]+2>lim){
				cnt++;
			}else break;
		}
		if(i<a.size()) dp[x]=max(dp[x],a[i]+1);
	}
	return;
}
bool check(int M){
	lim=M;cnt=0;
	dfs(1,0);
	return cnt<=m;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	int l=0,r=100000;
	while(r-l>1){
		int mid=(l+r)>>1;
		if(check(mid)){
			r=mid;
		}else l=mid;
	}
	printf("%d\n",r);
	return 0;
}
