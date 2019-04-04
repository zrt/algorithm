/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
//by zrt
//problem:
using namespace std;
long long n,mod;
long long pow10[20];
long long t[3][3],to[3][3];
void mul(long long t[3][3],long long to[3][3]){
	long long ret[3][3]={{0}};
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				ret[i][j]+=t[i][k]*to[k][j];
				if(ret[i][j]>=mod) ret[i][j]%=mod;
			}
		}
	}
	for(int i=0;i<3;i++) for(int j=0;j<3;j++) t[i][j]=ret[i][j];
	return;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%lld%lld",&n,&mod);
	pow10[0]=1;
	for(int i=1;i<=18;i++){
		pow10[i]=pow10[i-1]*10;
	}
	
	t[0][1]=t[0][0]=t[0][2]=1;
	int last=0;
	for(int i=1;i<=18;i++){
		if(n>=pow10[i]){
			last=i;
			long long d=pow10[i]-pow10[i-1];
			if(i==1) d--;
			to[1][0]=to[1][1]=to[2][0]=to[2][1]=to[2][2]=1;
			to[0][0]=pow10[i]%mod;
			while(d){
				if(d&1) mul(t,to);
				mul(to,to);
				d>>=1;
			}
		}
	}
	long long d=n-pow10[last]+1;
	to[1][0]=to[1][1]=to[2][0]=to[2][1]=to[2][2]=1;
	to[0][0]=pow10[last+1]%mod;
	while(d){
		if(d&1) mul(t,to);
		mul(to,to);
		d>>=1;
	}
	printf("%lld\n",t[0][0]);
	return 0;
}
