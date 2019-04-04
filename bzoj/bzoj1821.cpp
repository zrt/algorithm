#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k;
double x[1005],y[1005];
int fa[1005];
int get(int x){
	return fa[x]==x?x:fa[x]=get(fa[x]);
}
bool judge(double lim){
	for(int i=1;i<=n;i++) fa[i]=i;
	double lim2=lim*lim;
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(get(i)!=get(j)&&(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<=lim2)  fa[get(i)]=get(j);
	int tot=0;
	for(int i=1;i<=n;i++) if(fa[i]==i) tot++;
	return tot>=k;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lf%lf",&x[i],&y[i]);
	double l=0,r=1e10;
	for(int i=0;i<50;i++){
		double mid=(l+r)/2.0;
		if(judge(mid)) l=mid;
		else r=mid;
	}
	printf("%.2f\n",l);
	return 0;
}
