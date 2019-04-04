#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
LL a,b;
struct num{
	LL a[10];
};
num operator * (const num&a,LL k){
	num c;
	memset(c.a,0,sizeof c.a);
	for(int i=0;i<10;i++) c.a[i]=a.a[i]*k;
	return c;
}
num operator + (const num&a,const num&b){
	num c;
	memset(c.a,0,sizeof c.a);
	for(int i=0;i<10;i++) c.a[i]=a.a[i]+b.a[i];
	return c;
}
num operator - (const num&a,const num&b){
	num c;
	memset(c.a,0,sizeof c.a);
	for(int i=0;i<10;i++) c.a[i]=a.a[i]-b.a[i];
	return c;
}
num ans;
num all={1,1,1,1,1,1,1,1,1,1};
num azero={0,1,1,1,1,1,1,1,1,1};
num zero={1};
num t[20];
num base[20];
LL tt[20];
char s[20];
void solve(LL a,LL k){
	if(a==0){
		ans=ans+zero*k;
	}else{
		sprintf(s,"%lld",a);
		num now,ret;
		memset(now.a,0,sizeof now.a);
		memset(ret.a,0,sizeof ret.a);
		int l=strlen(s);
		if(l!=1)ret=ret+base[l-2];
		for(int i=0;i<l-1;i++){
			int tmp=s[i]-'0';
			for(int j=(i==0?1:0);j<tmp;j++){
				now.a[j]++;
				ret=ret+now*tt[l-i-1]+t[l-i-2];
				now.a[j]--;
			}
			now.a[tmp]++;
		}
		int tmp=s[l-1]-'0';
		for(int i=0;i<=tmp;i++) ret.a[i]++;
		ret=ret+now*(tmp+1);
		ans=ans+ret*k;
	}
}
int main(){

//	freopen("digital.in","r",stdin);
//	freopen("digital.out","w",stdout);

	t[0]=all;//0~9
	base[0]=all;
	tt[0]=1;
	for(int i=1;i<=12;i++){//10^i-1 10^i-1
		tt[i]=tt[i-1]*10;t[i]=t[i-1]*10+all*tt[i];
	}
	for(int i=1;i<=12;i++){
		base[i]=base[i-1]+t[i-1]*9+azero*tt[i];
	}
	scanf("%lld%lld",&a,&b);
	solve(a-1,-1);solve(b,1);
	for(int i=0;i<9;i++){
		printf("%lld ",ans.a[i]);
	}
	printf("%lld\n",ans.a[9]);
	return 0;
}
