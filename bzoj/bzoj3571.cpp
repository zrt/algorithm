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
int tt;
int n;
int a[75][75];
int b[75][75];
int c[75][75];
int ans;
bool va[75],vb[75];
int la[75],lb[75],temp;
int lin[75];
bool dfs(int w[][75],int x){
	va[x]=1;
	for(int y=1;y<=n;y++){
		if(!vb[y]){
			if(!(la[x]+lb[y]-w[x][y])){
				vb[y]=1;
				if(!lin[y]||dfs(w,lin[y])){
					lin[y]=x;return 1;
				}
			}else temp=min(temp,la[x]+lb[y]-w[x][y]);
		}
	}
	return 0;
}
void KM(int w[][75],int&suma,int&sumb){
	suma=sumb=0;
	for(int i=1;i<=n;i++){
		la[i]=lb[i]=0;
		for(int j=1;j<=n;j++){
			la[i]=max(la[i],w[i][j]);
		}
	}
	memset(lin,0,sizeof lin);
	for(int i=1;i<=n;i++){
		while(1){
			memset(va,0,sizeof va);
			memset(vb,0,sizeof vb);
			temp=inf;
			if(dfs(w,i)) break;
			for(int j=1;j<=n;j++){
				if(va[j])la[j]-=temp;
				if(vb[j])lb[j]+=temp;
			}
		}
	}
	for(int i=1;i<=n;i++){
		suma+=a[lin[i]][i];
		sumb+=b[lin[i]][i];
	}
	return;
}
void solve(int x1,int y1,int x2,int y2){
	if(x1==x2&&y1==y2) return;
	int A,B,C;
	A=y1-y2;
	B=x2-x1;
	C=-x2*y1+x1*y2;
	if(C>0) A*=-1,B*=-1,C*=-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			c[i][j]=A*a[i][j]+B*b[i][j];
		}
	}
	int x0,y0;
	KM(c,x0,y0);
	x0*=-1;y0*=-1;
	ans=min(ans,x0*y0);
	if(A*x0+B*y0+C==0) return;
	solve(x1,y1,x0,y0);solve(x0,y0,x2,y2);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&tt);
	while(tt--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&a[i][j]);
				a[i][j]=0-a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&b[i][j]);
				b[i][j]=0-b[i][j];
			}
		}
		int x1,y1,x2,y2;
		KM(a,x1,y1);
		KM(b,x2,y2);
		x1*=-1;x2*=-1;
		y1*=-1;y2*=-1;
		ans=min(x1*y1,x2*y2);
		solve(x1,y1,x2,y2);
		printf("%d\n",ans);
	}
	
	return 0;
}
