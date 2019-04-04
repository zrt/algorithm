#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int n,m,s,t;
int H[1005],X[2005],P[2005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
//a cc |b kk 0..a 1..b
double f[1005][1005][2];
bool calc[1005][1005][2];
int d[1005];
vector<int> v[1005][1005];
queue<int> q;
int degree[1005];
double dfs(int a,int b,int who){
	if(calc[a][b][who]) return f[a][b][who];
	else calc[a][b][who]=1;
	if(who==0){
		if(v[b][a][0]!=b){
			f[a][b][who]=dfs(v[b][v[b][a][0]][0],b,1)+1;
		}else f[a][b][who]=1;
	}else{
		double sum=0.0;
		sum+=dfs(a,b,0);
		for(int i=H[b];i;i=X[i]){
			sum+=dfs(a,P[i],0);
		}
		f[a][b][who]=sum/(degree[b]+1);
	}
	return f[a][b][who];
}
void pre(){
	for(int i=1;i<=n;i++){
		calc[i][i][0]=calc[i][i][1]=1;
		f[i][i][0]=f[i][i][1]=0;
	}
	for(int I=1;I<=n;I++){
		memset(d,0,sizeof d);
		d[I]=1;int x;q.push(I);
		while(!q.empty()){
			x=q.front();q.pop();
			for(int i=H[x];i;i=X[i]){
				if(!d[P[i]]){
					d[P[i]]=d[x]+1;
					q.push(P[i]);
					v[I][P[i]].push_back(x);
				}else if(d[P[i]]==d[x]+1){
					v[I][P[i]].push_back(x);
				}
			}
		}
		for(int i=1;i<=n;i++) sort(v[I][i].begin(),v[I][i].end());
	}
	
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	tot=1;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=0,x,y;i<m;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
		degree[x]++;degree[y]++;
	}
	pre();
	printf("%.3f\n",dfs(s,t,0));
	return 0;
}
