#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
typedef long long LL;
int d[1000005],p[1000005],c[1000005];
LL b[1000005],sum[1000005],f[1000005];
int q[1000005],l,r;
LL g(int j,int i){
	return f[j]+b[j]-d[i]*sum[j];
}
bool judge1(int j1,int j2,int i){//j2 < j1 return 1
	return g(j2,i)<=g(j1,i);
}
LL x(int i){
	return sum[i];
}
LL y(int i){
	return f[i]+b[i];
}
bool judge2(int i,int j,int k){
	LL x1,x2,x3,y1,y2,y3;
	x1=x(i),x2=x(j),x3=x(k);
	y1=y(i),y2=y(j),y3=y(k);
	return (x1-x2)*(y3-y2)-(x3-x2)*(y1-y2)>=0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&d[i],&p[i],&c[i]);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+d[i]*1LL*p[i];
		sum[i]=sum[i-1]+p[i];
	}
	q[r++]=0;
	for(int i=1;i<=n;i++){
		while(l+1<r&&judge1(q[l],q[l+1],i)) l++;
		f[i]=f[q[l]]+d[i]*1LL*(sum[i]-sum[q[l]])-(b[i]-b[q[l]])+c[i];
		while(l+1<r&&judge2(q[r-2],q[r-1],i)) r--;
		q[r++]=i;
	}
	printf("%lld\n",f[n]);
	return 0;
}
