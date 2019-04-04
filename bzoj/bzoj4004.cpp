#include<bits/stdc++.h>
using namespace std;
int n,m;
typedef long double ld;
struct N{
	int w;
	ld x[505];
	friend bool operator < (const N&a,const N&b){
		return a.w<b.w;
	}
}a[505];
int ans,num;
int ji[505];
void solve(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ji[j]){
				ld f=a[i].x[j]/a[ji[j]].x[j];
				for(int k=1;k<=m;k++) a[i].x[k]-=f*a[ji[j]].x[k];
			}else if(fabs(a[i].x[j])>1e-8){
				ans+=a[i].w;
				ji[j]=i;
				num++;
				break;
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%Lf",&a[i].x[j]);
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].w);
	}
	sort(a+1,a+n+1);
	solve();
	printf("%d %d\n",num,ans);
	return 0;
}
