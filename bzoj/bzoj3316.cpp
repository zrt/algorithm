#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,L,R;
int a[200005];
typedef long double ld;
typedef long long LL;
ld sum[200005];
int l,r;
struct N{
	ld w;
	int x;
	N(int a=0,ld b=0){
		x=a,w=b;
	}
}q[200005];
int len;
bool judge(ld x){
	for(int i=1;i<=n*2;i++) sum[i]=sum[i-1]+a[i]-x;
	l=r=0;
	for(int i=0;i<=n*2;i+=2){
		if(i-L<0) continue;
		while(l<r&&q[r-1].w>sum[i-L]) r--;
		q[r++]=N(i-L,sum[i-L]);
		while(l<r&&q[l].x<i-R) l++;
		if(l<r&&q[l].w<sum[i]){
			len=i-q[l].x;
			return 1;
		}
	}
	l=r=0;
	for(int i=1;i<=n*2;i+=2){
		if(i-L<0) continue;
		while(l<r&&q[r-1].w>sum[i-L]) r--;
		q[r++]=N(i-L,sum[i-L]);
		while(l<r&&q[l].x<i-R) l++;
		if(l<r&&q[l].w<sum[i]){
			len=i-q[l].x;
			return 1;
		}
	}
	return 0;
}
LL gcd(LL a,LL b){
	return b?gcd(b,a%b):a;
}
int main(){
	scanf("%d%d%d",&n,&L,&R);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i+n]=a[i];
	if(L&1) L++;
	if(R&1) R--;
	ld l=0,r=1e10;
	for(int i=0;i<=50;i++){
		ld mid=(l+r)/2;
		if(judge(mid)) l=mid;
		else r=mid;	
	}
	judge(l);
	LL f=l*len+0.5;
	LL g=gcd(f,len);
	f/=g;len/=g;
	if(len==1) printf("%lld\n",f);
	else printf("%lld/%d\n",f,len);
	return 0;
}
