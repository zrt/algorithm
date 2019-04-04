#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int mo[31][31];
int get(int x,int y){
	return (x-1)*6+y;
}
int tt;
int a[31][31];
int kase;
int ans[31];
void solve(){
	for(int i=1;i<=30;i++){
		int pos=-1;
		for(int j=i;j<=30;j++){
			if(a[j][i]){
				pos=j;break;
			}
		}
		for(int j=0;j<=30;j++) swap(a[i][j],a[pos][j]);
		for(int j=i+1;j<=30;j++){
			if(a[j][i]){
				for(int k=i;k<=30;k++){
					a[j][k]^=a[i][k];
				}
				a[j][0]^=a[i][0];
			}
		}
	}
	for(int i=30;i>0;i--){
		if(a[i][i]){
			for(int k=i+1;k<=30;k++) {
				if(a[i][k]) a[i][0]^=ans[k];
			}
			ans[i]=a[i][0];
		}else ans[i]=0;
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	for(int i=1;i<=5;i++){
		for(int j=1;j<=6;j++){
			mo[get(i,j)][get(i,j)]=1;
			if(j>1) mo[get(i,j)][get(i,j-1)]=1;
			if(j<6) mo[get(i,j)][get(i,j+1)]=1;
			if(i>1) mo[get(i,j)][get(i-1,j)]=1;
			if(i<5) mo[get(i,j)][get(i+1,j)]=1;
		}
	}
	scanf("%d",&tt);
	while(tt--){
		printf("PUZZLE #%d\n",++kase);
		memcpy(a,mo,sizeof a);
		for(int i=1;i<=5;i++){
			for(int j=1;j<=6;j++){
				scanf("%d",&a[get(i,j)][0]);
			}
		}
		solve();
		for(int i=1;i<=5;i++){
			for(int j=1;j<=6;j++){
				printf("%d ",ans[get(i,j)]);
			}
			puts("");
		}
	}
	return 0;
}
