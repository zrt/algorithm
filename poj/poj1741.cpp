#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int H[10005],X[20005],P[20005],E[20005],tot;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
int n,k;int sum;
int ans;
bool solved[10005];
int dp[10005];
int maxx[10005];
vector<int> now;
void dfs(int x,int fa){
	dp[x]=1,maxx[x]=0;now.push_back(x);
	for(int i=H[x];i;i=X[i]){
		if(solved[P[i]]||P[i]==fa) continue;
		dfs(P[i],x);
		maxx[x]=max(maxx[x],dp[P[i]]);
		dp[x]+=dp[P[i]];
	}
}
int find(int x){
	now.clear();
	dfs(x,-1);
	sum=now.size();
	int minn=1<<29,minpos;
	for(int i=0;i<sum;i++){
		maxx[now[i]]=max(maxx[now[i]],sum-dp[now[i]]);
		if(maxx[now[i]]<minn){
			minn=maxx[now[i]];
			minpos=now[i];
		}
	}
	return minpos;
}
int d[10005];
void dfs2(int x,int fa){
	for(int i=H[x];i;i=X[i]){
		if(fa!=P[i]&&!solved[P[i]]){
			d[P[i]]=d[x]+E[i];
			dfs2(P[i],x);
		}
	}
}
int list[10005];
int belong[10005];
vector<int> son[10005];
vector<int> t[10005];
void dfs3(int x,int fa,int root){
	if(fa==root||fa==-1) belong[x]=x,son[root].push_back(x),t[belong[x]].push_back(x);
	else belong[x]=belong[fa],t[belong[x]].push_back(x);
	for(int i=H[x];i;i=X[i]){
		if(!solved[P[i]]&&P[i]!=fa) dfs3(P[i],x,root);
	}
}
void solve(int x){
	int root=find(x);
	solved[root]=1;
	d[root]=0;
	dfs2(root,-1);
	dfs3(root,-1,root);
	for(int i=0;i<sum;i++){
		list[i]=d[now[i]];
	}
	sort(list,list+sum);
	int l=0,r=sum-1;
	for(l=0;l<sum;l++){
		while(l<r&&list[l]+list[r]>k) r--;
		if(l==r) break;
		ans+=r-l;
	}
	for(int i=0;i<son[root].size();i++){
		int x=son[root][i];
		int tmp=t[x].size();
		for(int j=0;j<tmp;j++){
			list[j]=d[t[x][j]];
		}
		t[x].clear();
		sort(list,list+tmp);
		l=0,r=tmp-1;
		for(l=0;l<tmp;l++){
			while(l<r&&list[l]+list[r]>k) r--;
			if(l==r) break;
			ans-=r-l;
		}
	}
	for(int i=0;i<son[root].size();i++){
		if(son[root][i]!=root)solve(son[root][i]);
	}
	son[root].clear();
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%d%d",&n,&k),n|k){
		tot=1;
		memset(solved,0,sizeof solved);
		memset(H,0,sizeof H);
		for(int i=1,x,y,z;i<n;i++){
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);add(y,x,z);
		}
		ans=0;
		solve(1);
		printf("%d\n",ans);
	}
	
	return 0;
}
