#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int a[50005];
bool judge(int x){
	int tot=1,s=0;
	for(int i=1;i<=n;i++){
		if(a[i]>x) return 0;
		else if(a[i]+s>x){
			s=a[i];
			tot++;
			if(tot>m) return 0;
		}else s+=a[i];
	}
	return 1;
}
int ans;
const int mod=10007;
//int f[50005][1005];
short sum[50005][1005];
int main(){
	scanf("%d%d",&n,&m);
	m++;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int l=0,r=50000005;
	while(r-l>1){
		int mid=l+(r-l)/2;
		if(judge(mid)){
			r=mid;
		}else l=mid;
	}
	ans=r;
	//f[0][0]=1;
	sum[1][0]=1;
	for(int i=1;i<=n;i++) a[i]+=a[i-1];
	l=0;
	for(int i=1;i<=n;i++){
		while(a[i]-a[l]>ans) l++;
		//printf("$ %d\n",l);
		for(int j=0;j<=m;j++){
			int t=(sum[i][j-1]-sum[l][j-1]+mod)%mod;
			sum[i+1][j]=(sum[i][j]+t)%mod;
		//	printf("%d %d %d\n",i,j,f[i][j]);
		}
	}
	//printf("%d\n",sum[2][0]);
	int ans2=0;
	for(int i=1;i<=m;i++) ans2=(ans2+sum[n+1][i]-sum[n][i]+mod)%mod;
	printf("%d %d\n",ans,ans2);
	return 0;
}
