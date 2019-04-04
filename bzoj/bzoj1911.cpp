#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
int n,a,b,c;
const int MAXN=1e6+5;
int q[MAXN],l,r;
LL s[MAXN];
LL f[MAXN];
LL calcx(int j){
	return s[j-1];
}
LL calcy(int j){
	return f[j-1]+a*s[j-1]*s[j-1]-b*s[j-1]+c;
}
LL calcb(int j,int i){
	return calcy(j)-2*a*s[i]*calcx(j);
}
bool judge1(int j1,int j2,int i){// j2 better than j1 return true
	LL b1,b2;
	b1=calcb(j1,i);
	b2=calcb(j2,i);
	return b1<=b2;
}
bool judge2(int i,int j,int k){// i,j,k not tu return true
	LL x1,x2,x3,y1,y2,y3;
	x1=calcx(i),x2=calcx(j),x3=calcx(k);
	y1=calcy(i),y2=calcy(j),y3=calcy(k);
	return (x3-x2)*(y1-y2)-(x1-x2)*(y3-y2)>=0;
}
int main(){
	scanf("%d",&n);
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=n;i++) scanf("%lld",&s[i]);
	s[0]=0;
	for(int i=1;i<=n;i++) s[i]+=s[i-1];
	f[0]=0;
	q[r++]=1;// j-1=0
	for(int i=1;i<=n;i++){
		while(l+1<r&&judge1(q[l],q[l+1],i)) l++;
		f[i]=f[q[l]-1]+a*(s[i]-s[q[l]-1])*(s[i]-s[q[l]-1])+b*(s[i]-s[q[l]-1])+c;
		while(l+1<r&&judge2(q[r-2],q[r-1],i+1)) r--;
		q[r++]=i+1;
	}
	printf("%lld\n",f[n]);
	return 0;
}
