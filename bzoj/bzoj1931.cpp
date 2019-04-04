#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
struct N{
	int a[205];
	friend N operator + (const N&a,const N&b){
		N c;
		for(int i=0;i<=204;i++) c.a[i]=a.a[i]+b.a[i];
		for(int i=0;i<204;i++) c.a[i+1]+=c.a[i]/10,c.a[i]%=10;
		return c;
	}
	friend N operator * (const N&a,int x){
		N c;
		for(int i=0;i<=204;i++) c.a[i]=a.a[i]*x;
		for(int i=0;i<204;i++) c.a[i+1]+=c.a[i]/10,c.a[i]%=10;
		return c;
	}
	friend N operator * (const N&a,const N&b){
		N c;
		memset(c.a,0,sizeof c.a);
		for(int i=0;i<=100;i++){
			for(int j=0;j<=100;j++){
				c.a[i+j]+=a.a[i]*b.a[j];
			}
		}
		return c;
	}
}d[65],c[65][65],F[65][65],f[65],ans;
int n;
int a[200];
bool use[200];
int p;
int main(){
	d[0].a[0]=1;d[1].a[0]=0;d[2].a[0]=1;
	for(int i=3;i<=64;i++) d[i]=(d[i-1]+d[i-2])*(i-1);
	f[0].a[0]=1;
	for(int i=1;i<=64;i++) f[i]=f[i-1]*i;
	for(int i=0;i<=64;i++){
		c[i][0].a[0]=1;
		for(int j=1;j<=i;j++){
			c[i][j]=c[i-1][j]+c[i-1][j-1];
		}
	}
	for(int i=0;i<=64;i++) F[i][0]=f[i];
	for(int i=1;i<=64;i++){
		for(int j=1;j<=i;j++){
			F[i][j]=F[i-1][j-1]*(i-j)+F[i-1][j-2]*(j-1);
		}
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]),p+=(a[i]==i);
	printf("%d ",p);
	int K=p;
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			if(use[j]) continue;
			if(j==i) K--;
			if(K<0){
				K++;
				continue;
			}
			use[j]=1;
			
			int tot=0;
			for(int k=i+1;k<n;k++){
				if(!use[k]) tot++;
			}
			if(tot>=K){
				ans=ans+c[tot][K]*F[n-i-1-K][tot-K];
			}
			use[j]=0;
			if(j==i) K++;
		}
		if(a[i]==i) K--;
		use[a[i]]=1;
	}
	int top=201;
	while(top>1&&ans.a[top-1]==0) top--;
	while(top>0) printf("%d",ans.a[--top]);
	puts("");
	return 0;
}
