#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long double ld;
int n,m;
int H[505],X[500050],P[500050],from[500050],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;from[tot]=x;
}
int du[505];
ld a[505][505];
void Gauss(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(fabs(a[i][j]>fabs(a[i][i]))){
				for(int k=i;k<=n;k++) swap(a[j][k],a[i][k]);
			}
		}
		for(int j=i+1;j<=n+1;j++) a[i][j]/=a[i][i];
		a[i][i]=1;
		for(int j=1;j<=n;j++){
			if(i!=j){
				ld f=a[j][i]/a[i][i];
				for(int k=1;k<=n+1;k++){
					a[j][k]-=f*a[i][k];
				}
			}
		}
	}
}
ld e[500050];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0,x,y;i<m;i++){
		scanf("%d%d",&x,&y);
		du[x]++;du[y]++;
		add(x,y);add(y,x);
	}
	for(int i=1;i<n;i++){
		a[i][i]=1;
		for(int j=H[i];j;j=X[j]){
			a[i][P[j]]=-1.0/du[P[j]];
		}
		if(i==1) a[i][n+1]=1;
	}
	a[n][n]=1;
	Gauss();
	for(int i=1;i<=tot;i+=2){
		e[i/2]=a[from[i]][n+1]/du[from[i]]+a[P[i]][n+1]/du[P[i]];
	}
	ld ans=0;
	sort(e,e+m);
	for(int i=0;i<m;i++){
		ans+=(m-i)*e[i];
	}
	printf("%.3f\n",(double)ans);
	return 0;
}
