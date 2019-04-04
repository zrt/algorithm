#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
int n,m;
const int mod=31011;
struct N{
	int a,b,c;
	friend bool operator < (N a,N b){
		return a.c<b.c;
	}
}e[1005];
int fa[1005];
int get(int x){
	return fa[x]==x?x:fa[x]=get(fa[x]);
}
int ans=1;
const double eps=1e-10;
double a[25][25];
int Gauss(int n){
	double ans=1;
	for(int i=1;i<=n;i++){
		double mx=eps;int pos=0;
		for(int j=i;j<=n;j++){
			if(fabs(a[j][i])>mx){
				mx=fabs(a[j][i]);
				pos=j;
			}
		}
		if(!pos) return 0;
		for(int j=i;j<=n;j++) swap(a[i][j],a[pos][j]);
		for(int j=i+1;j<=n;j++){
			if(fabs(a[j][i])>eps){
				double F=a[j][i]/a[i][i];
				for(int k=i;k<=n;k++) a[j][k]-=F*a[i][k];
			}
		}
	}
	for(int i=1;i<=n;i++) ans=ans*a[i][i];
	ans=fabs(ans);
	return (int)(ans+0.5);
}
int num;
int to[105];
int pos[105];
int vis[105];
int H[105],X[2005],P[2005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
queue<int> q;
void bfs(int x){
	vis[x]=x;
	q.push(x);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			if(!vis[P[i]]){
				vis[P[i]]=vis[x];
				q.push(P[i]);
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c);
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e,e+m);
	for(int i=0;i<m;i++){
		int j=i;
		while(j+1<m&&e[j+1].c==e[i].c) j++;
		num=0;
		memset(to,0,sizeof to);
		memset(H,0,sizeof H);
		memset(vis,0,sizeof vis);
		tot=0;
		for(int k=i;k<=j;k++){
			if(get(e[k].a)==get(e[k].b)) continue;
			if(!to[get(e[k].a)]) to[get(e[k].a)]=++num;
			if(!to[get(e[k].b)]) to[get(e[k].b)]=++num;
			add(to[get(e[k].a)],to[get(e[k].b)]);
			add(to[get(e[k].b)],to[get(e[k].a)]);
		}
		if(num<=1){
			for(int k=i;k<=j;k++){
				if(get(e[k].a)==get(e[k].b)) continue;
				fa[get(e[k].a)]=get(e[k].b);
			}
		}else{
			for(int i=1;i<=num;i++){
				if(!vis[i]){
					memset(a,0,sizeof a);
					bfs(i);
					int tt=0;
					for(int p=1;p<=num;p++){
						if(vis[p]==i){
							pos[p]=++tt;
						}
					}
					for(int p=1;p<=num;p++){
						if(vis[p]==i){
							for(int j=H[p];j;j=X[j]){
								a[pos[p]][pos[P[j]]]++;
								a[pos[p]][pos[p]]--;
							}
						}
					}
					int ppp=Gauss(tt-1);
	//				printf("%d\n",ppp);
					ans=ppp%mod*ans%mod;
				}
			}
		}
		for(int k=i;k<=j;k++){
			if(get(e[k].a)==get(e[k].b)) continue;
			fa[get(e[k].a)]=get(e[k].b);
		}
		i=j;
	}
	for(int i=1;i<n;i++) if(get(i)!=get(i+1)){
		puts("0");
		return 0;
	}
	printf("%d\n",ans);
	return 0;
}
