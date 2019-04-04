#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int n,m;
int H[105],X[20005],P[20005],tot,E[20005];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
int d[105];
double f[105][105];// 1..n | n+1 
int way;
double Ans[105];
void solve(){//高斯消元 
	for(int i=1;i<=n;i++){
		double maxx=0.0;int pos;//精度 
		for(int j=i;j<=n;j++){
			if(fabs(f[j][i])>maxx){
				maxx=fabs(f[j][i]);
				pos=j;
			}
		}
		if(i!=pos) for(int j=1;j<=n+1;j++) swap(f[i][j],f[pos][j]);
	//	if(fabs(f[i][i])<eps) continue;
		double p;
		for(int j=i+1;j<=n;j++){
			p=f[j][i]/f[i][i];
			for(int k=i;k<=n+1;k++) f[j][k]-=f[i][k]*p;
		}
	}
	for(int i=n;i>=1;i--){
	//	if(fabs(f[i][i])<eps) continue;
		for(int j=i+1;j<=n;j++) f[i][n+1]-=Ans[j]*f[i][j];
		Ans[i]=f[i][n+1]/f[i][i];
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=0,x,y,z;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		d[x]++;if(x!=y) d[y]++,add(y,x,z);//!!!!!!!!
		add(x,y,z);

	}
	double ans=0.0;
	for(way=0;way<31;way++){
		memset(f,0,sizeof f);
		for(int i=1;i<n;i++){//第i行
			double di=1.0/d[i];
			for(int j=H[i];j;j=X[j]){
				if(E[j]>>way&1){
					f[i][n+1]+=di;
					f[i][P[j]]+=di;
				}else{
					f[i][P[j]]-=di;
				}
			}
			f[i][i]+=1.0;
		}
		f[n][n]=1.0;
		solve();
		ans+=(1<<way)*Ans[1];
	}
	printf("%.3f\n",ans);
	return 0;
}
