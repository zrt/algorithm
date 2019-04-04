#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long double ld;
ld f[50005][21];
int pos[50005][21];
int from[50005][21];
int n;
const ld inf=1e200;
int p[17]={0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
ld LOG[17];
typedef long long LL;
struct N{
	LL a[10001];
	friend N operator + (const N&a,const N&b){
		N c;
		for(int i=0;i<=10000;i++) c.a[i]=a.a[i]+b.a[i];
		for(int i=0;i<10000;i++) c.a[i+1]+=c.a[i]/100000000,c.a[i]%=100000000;
		return c;
	}
	friend N operator * (const N&a,const N&b){
		N c;
		memset(c.a,0,sizeof c.a);
		int tot1=10000,tot2=10000;
		while(a.a[tot1]==0) tot1--;
		while(b.a[tot2]==0) tot2--;
		for(int i=0;i<=tot1;i++){
			for(int j=0;j<=tot2;j++){
				c.a[i+j]+=a.a[i]*b.a[j];
			}
		}
		for(int i=0;i<10000;i++) c.a[i+1]+=c.a[i]/100000000,c.a[i]%=100000000;
		return c;
	}
}ans,tmp;
N pow(N a,int b){
	N t;
	memset(t.a,0,sizeof t.a);
	t.a[0]=1;
	while(b){
		if(b&1) t=t*a;
		a=a*a;
		b>>=1;
	}
	return t;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=15;i++) LOG[i]=log((double)p[i]);
	for(int i=1;i<=n;i++){
		f[i][1]=LOG[1]*(i-1);
		int lim=sqrt(i)+0.5;
		for(int j=2;j<=15;j++){
			ld mn=inf;int pos;
			for(int k=1;k<=lim;k++){
				if(i%k==0){
					ld t=f[i/k][j-1]+LOG[j]*(k-1);
					if(t<mn){
						mn=t;
						pos=k;
					}
					t=f[k][j-1]+LOG[j]*(i/k-1);
					if(t<mn){
						mn=t;
						pos=i/k;
					}
				}
			}
			f[i][j]=mn;
			from[i][j]=pos;
		}
	}
	ans.a[0]=1;
	int pos=15;
	int k=n;
	while(k>1){
		int pp=from[k][pos];
		if(pos==1) pp=k;
	//	printf("%d %d %d\n",k,pos,pp);
		memset(tmp.a,0,sizeof tmp.a);
		tmp.a[0]=p[pos];
		ans=ans*pow(tmp,pp-1);
		k/=pp;pos--;
	}
	int top=10000;
	while(top>1&&ans.a[top-1]==0) top--;
	printf("%lld",ans.a[--top]);
	while(top>0) printf("%08lld",ans.a[--top]);
	puts("");
	return 0;
}
