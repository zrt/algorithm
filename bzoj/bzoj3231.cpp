/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
#include<cstring>
//by zrt
//problem:
// jilu yige Si
using namespace std;
long long mod;
long long m,n;
struct Matrix{
	int n;
	long long t[16][16];
	friend Matrix operator * (Matrix a,Matrix b){
		Matrix ret;
		memset(ret.t,0,sizeof ret.t);
		ret.n=a.n;
		for(int i=0;i<a.n;i++){
			for(int j=0;j<a.n;j++){
				for(int k=0;k<a.n;k++){
					ret.t[i][j]+=a.t[i][k]*b.t[k][j];
					if(ret.t[i][j]>=mod) ret.t[i][j]%=mod;
				}
			}
		}
		return ret;
	}
};
long long Sm,Sn,sum;
Matrix t,to;
long long d;
Matrix his;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int k;
	scanf("%d",&k);
	to.n=t.n=k+1;
	for(int i=0;i<k;i++){
		scanf("%lld",&t.t[0][k-i]);
		sum+=t.t[0][k-i];
	}
	t.t[0][0]=sum;
	to.t[0][0]=1;
	for(int i=1;i<k;i++){
		to.t[i][i+1]=1;
	}
	for(int i=0;i<k;i++){
		scanf("%lld",&to.t[i+1][0]);
		to.t[i+1][1]=to.t[i+1][0];
	}
	scanf("%lld%lld%lld",&m,&n,&mod);
/*	t=t*to;
	t=t*to;
	t=t*to;
	t=t*to;*/
	m--;
	his=to;
	if(m<=k){
		for(int i=k;i>0&&m;i--){
			m--;
			Sm+=t.t[0][i];
			if(Sm>=mod) Sm%=mod;
		}
		m=k;
		if(n<=k){
			for(int i=k;i>0&&n;i--){
				n--;
				Sn+=t.t[0][i];
				if(Sn>=mod) Sn%=mod;
			}
		}else{
			goto casn;
		}
	}else{
		d=m-k;
		while(d){
			if(d&1) t=t*to;
			to=to*to;
			d>>=1;
		}
		Sm=t.t[0][0];
		casn:;
		d=n-m;
		to=his;
		while(d){
			if(d&1) t=t*to;
			to=to*to;
			d>>=1;
		}
	
		Sn=t.t[0][0];
	}
	
	printf("%lld\n",(Sn+mod-Sm)%mod);
	return 0;
}
