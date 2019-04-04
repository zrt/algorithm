#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
int n,L;
LL s[50005];
LL f[50005];
int q[50005],l,r;
LL cx(int j){
	return j+s[j];
}
LL cy(int j){
	return f[j]+j*1LL*j+s[j]*s[j]+2*j*s[j]+2*j*1LL*L+2*s[j]*L;
}
bool judge2(int i,int j,int k){
	LL x1,y1,x2,y2,x3,y3;
	x1=cx(i),y1=cy(i);x2=cx(j),y2=cy(j);x3=cx(k),y3=cy(k);
	return (x1-x2)*(y3-y2)-(x3-x2)*(y1-y2)>=0;
}
LL g(int j,int i){
	return f[j]+j*1LL*j+s[j]*s[j]+2*j*s[j]+2*j*1LL*L+2*s[j]*L-2*(i+s[i])*(j+s[j]);
}
bool judge1(int j1,int j2,int i){ //if j2 better than j1 (g[j2]<g[j1]) return true
	//printf("$ %d %d %d\n",j1,j2,i);
	return g(j2,i)<=g(j1,i);
}
int main(){
	scanf("%d%d",&n,&L);
	for(int i=1;i<=n;i++) scanf("%lld",&s[i]);
	for(int i=1;i<=n;i++) s[i]+=s[i-1];
	q[r++]=0;
	for(int i=1;i<=n;i++){
		while(l+1<r&&judge1(q[l],q[l+1],i)) l++;
		f[i]=f[q[l]]+(i-q[l]-1+s[i]-s[q[l]]-L)*(i-q[l]-1+s[i]-s[q[l]]-L);
		//printf("# %d %lld\n",i,f[i]);
		//printf("%d\n",q[l]);
		while(l+1<r&&judge2(q[r-2],q[r-1],i)) r--;
		q[r++]=i;	
	}
	printf("%lld\n",f[n]);
	return 0;
}
