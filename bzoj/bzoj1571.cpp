#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int f[10005][105];
int t,s,n;
int ke[10005][105];
int po[105];
int g[10005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	memset(f,128,sizeof f);
	scanf("%d%d%d",&t,&s,&n);
	for(int i=1,m,l,a;i<=s;i++){
		scanf("%d%d%d",&m,&l,&a);
		ke[m+l-1][a]=max(ke[m+l-1][a],m);
	}
	memset(po,0x3f,sizeof po);
	for(int i=1,c,d;i<=n;i++){
		scanf("%d%d",&c,&d);
		for(int j=c;j<=100;j++){
			po[j]=min(po[j],d);
		}
	}
	f[0][1]=0;
	g[0]=0;
	for(int i=1;i<=t;i++){
		for(int j=1;j<=100;j++){
			f[i][j]=f[i-1][j];
			if(ke[i-1][j])f[i][j]=max(f[i][j],g[ke[i-1][j]]);
			if(i-po[j]>=0)f[i][j]=max(f[i][j],f[i-po[j]][j]+1);
			g[i]=max(g[i],f[i][j]);
		}
	}
	printf("%d\n",g[t]);
	return 0;
}
