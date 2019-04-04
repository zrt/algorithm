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
int tt,n;
int now[30],to[30];
int a[31][31];
int has[31];
int r;
void solve(){
	for(int i=1;i<=n;i++){//每一列 
		int pos=-1;
		for(int j=r+1;j<=n;j++){
			if(a[j][i]){
				pos=j;break;
			}
		}
		if(pos==-1) continue;
		has[i]=1;r++;
		for(int j=1;j<=n+1;j++) swap(a[r][j],a[pos][j]);
		for(int j=r+1;j<=n;j++){
			if(a[j][i]){
				for(int k=i;k<=n+1;k++){
					a[j][k]^=a[r][k];
				}
			}
		}
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&tt);
	while(tt--){
		scanf("%d",&n);
		memset(a,0,sizeof a);
		memset(has,0,sizeof has);
		r=0;
		for(int i=1;i<=n;i++) scanf("%d",&now[i]);
		for(int i=1;i<=n;i++) scanf("%d",&to[i]);
		for(int i=1;i<=n;i++){
			a[i][i]=1;a[i][n+1]=now[i]^to[i];
		}
		{
			int x,y;
			while(scanf("%d%d",&x,&y),x|y){
				a[y][x]=1;
			}
		}
		solve();
		for(int i=r+1;i<=n;i++){
			if(a[i][n+1]) {
				puts("Oh,it's impossible~!!");
				goto ed;
			}
		}
		printf("%d\n",1<<(n-r));
		ed:;
	}
	
	return 0;
}
