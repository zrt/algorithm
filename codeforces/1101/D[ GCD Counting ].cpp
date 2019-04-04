#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;

int n;
int H[200005],X[200005*2],P[200005*2];
int a[200005];
int tot;
void add(int x,int y){
	P[++tot] = y;X[tot]=H[x];H[x] = tot;
}
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
// int fa[200005][25];
// int dep[200005];
// void dfs(int x){
// 	dep[x] = dep[fa[x][0]]+1;
// 	for(int i=H[x];i;i=X[i]){
// 		if(P[i] == fa[x][0]) continue;
// 		fa[P[i]][0] = x;
// 		dfs(P[i]);
// 	}
// }
// int lca(int x,int y){
// 	if(dep[x]<dep[y]) swap(x,y);
// 	// dep[x] >= dep[y]
// 	for(int i=20;i>=0;i--){
// 		if(dep[fa[x][i]]>=dep[y]) x = fa[x][i];
// 	}
// 	if(x==y) return x;
// 	for(int i=20;i>=0;i--){
// 		if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
// 	}
// 	return fa[x][0];
// }
vector<int> v[200005];
int mark[200005];
bool vis[200005];
int ans;
int dfs(int x,int fa){
	vis[x] = 1;
	int mx= 1;
	for(int i=H[x];i;i=X[i]){
		if(P[i] == fa) continue;
		if(!mark[P[i]]) continue;
		int t=dfs(P[i],x);
		ans = max(ans, mx+t);
		mx = max(mx, t+1);
	}
	ans = max(ans,mx);
	return mx;
}
// int ask(int x,int y){
// 	cout<<x<<" "<<y<<endl;
// 	int lcaxy = lca(x,y);
// 	return dep[x]+dep[y] - 2* dep[lcaxy]+1;
// }
int main(){
	ios::sync_with_stdio(0);

	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1,x,y;i<n;i++){
		cin >> x>> y;
		add(x,y);
		add(y,x);
	}
	// dfs(1);
	// for(int j=1;j<=20;j++){
	// 	for(int i=1;i<=n;i++){
	// 		fa[i][j] = fa[fa[i][j-1]][j-1];
	// 	}
	// }
	for(int i=1;i<=n;i++){
		int x = a[i];
		for(int j=2;j*j<=x;j++){
			if(x%j == 0) v[j].push_back(i);
			while(x%j == 0) x/=j;
		}
		if(x!=1)
			v[x].push_back(i);
	}
	int sqrtn = sqrt(n);
	int mx = 0;
	for(int i=2;i<=200000;i++){
		if(v[i].size()<=1) continue;
		for(int j=0;j<v[i].size();j++) mark[v[i][j]] = 1;
		for(int j=0;j<v[i].size();j++){
			if(!vis[v[i][j]]){
				ans = 0;
				dfs(v[i][j],0);
				mx = max(mx,ans);
			}
		}
		for(int j=0;j<v[i].size();j++) mark[v[i][j]] = 0, vis[v[i][j]] = 0;
	}
	cout<<mx;
	// dfs(1);




	return 0;
}