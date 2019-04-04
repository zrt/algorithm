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
int n;
int n2;
int get(int x,int y){
	return (x-1)*n+y;
}
int tt;
int a[250][250];
int ans[250];
int r;
int gmh;
bool isz[250];
void solve(){
	int n=n2;
	memset(isz,0,sizeof isz);
	for(int i=1;i<=n;i++){
		int pos=-1;
		for(int j=r+1;j<=n;j++){
			if(a[j][i]){
				pos=j;break;
			}
		}
		if(pos==-1) continue;
		r++;isz[i]=1;
		for(int j=0;j<=n;j++) swap(a[r][j],a[pos][j]);
		for(int j=r+1;j<=n;j++){
			if(a[j][i]){
				for(int k=i;k<=n;k++){
					a[j][k]^=a[r][k];
				}
				a[j][0]^=a[r][0];
			}
		}
	}
	for(int i=n;i>0;i--){
		if(a[i][0]){
			bool ok=0;
			for(int k=1;k<=n&&!ok;k++){
				if(a[i][k]) ok=1;
			}
			if(!ok){
				gmh=1;return;
			}
		}
	}
	r=n;
	for(int i=n;i>0;i--){
		while(r>0&&!isz[r]){
			ans[r]=0;r--;
		}
		if(r==0) break;
		if(a[i][r]){
			for(int k=r+1;k<=n;k++) {
				if(a[i][k]) a[i][0]^=ans[k];
			}
			ans[r]=a[i][0];
			r--;
		}
	}
}
char s[20];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&tt);
	while(tt--){
		r=0;gmh=0;
		scanf("%d",&n);
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[get(i,j)][get(i,j)]=1;
				if(j>1) a[get(i,j)][get(i,j-1)]=1;
				if(j<n) a[get(i,j)][get(i,j+1)]=1;
				if(i>1) a[get(i,j)][get(i-1,j)]=1;
				if(i<n) a[get(i,j)][get(i+1,j)]=1;
			}
		}
		for(int i=1;i<=n;i++){
			scanf("%s",s+1);
			for(int j=1;j<=n;j++){
				if(s[j]=='w') a[get(i,j)][0]=1;
				else a[get(i,j)][0]=0;
			}
		}
		n2=n*n;
		solve();
		int _ans=0;
		if(gmh){
			puts("inf");goto ed;
		}
		for(int i=1;i<=n2;i++) if(ans[i]) _ans++;
		printf("%d\n",_ans);
		ed:;
	}
	return 0;
}
