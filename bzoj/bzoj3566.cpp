#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
int H[500005],X[1000005],P[1000005],tot;
double E[1000005];
inline void add(int x,int y,double z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
double a[500005];
double f[500005];
double g[500005];
double F(double x,double y){
	return x+y-x*y;
}
void dfs(int x,int fa){
	f[x]=a[x];
	for(int i=H[x];i;i=X[i]){
		if(fa==P[i]) continue;
		dfs(P[i],x);
		f[x]=F(f[x],f[P[i]]*E[i]);
	}
}
void dfs2(int x,int fa){
	for(int i=H[x];i;i=X[i]){
		if(P[i]==fa) continue;
		if(fabs(1-f[P[i]]*E[i])<1e-10){
			g[P[i]]=1.0;
		}else{
			double y=(g[x]-f[P[i]]*E[i])/(1-f[P[i]]*E[i]);
			g[P[i]]=F(y*E[i],f[P[i]]);
		}
		dfs2(P[i],x);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y,z;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z/100.0);
		add(y,x,z/100.0);
	}
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		a[i]=x/100.0;
	}
	dfs(1,0);
	g[1]=f[1];
	dfs2(1,0);
	double ans=0;
	for(int i=1;i<=n;i++) ans+=g[i];
	printf("%.6f\n",ans);
	return 0;
}
