#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int a[16][16];
int ans[16][16];
int b[16][16];
int t[16][16];
int n,m;
int minn=(1<<30);
int xk[]={0,0,1,-1,0};
int yk[]={1,-1,0,0,0};
inline void work(int x,int y){
	for(int k=0;k<5;k++){
		int X=x+xk[k],Y=y+yk[k];
		if(X<1||Y<1||X>n||Y>m) continue;
		b[X][Y]^=1;
	}
}
void judge(int x){
	memcpy(b,a,sizeof a);
	memset(t,0,sizeof t);
	int tot=0;
	for(int i=1;i<=m;i++){
		if((x>>(i-1))&1){
			t[1][i]=1;
			work(1,i);
			tot++;
			if(tot>=minn) return;
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i-1][j]){
				t[i][j]=1;
				work(i,j);
				tot++;
				if(tot>=minn) return;
			}
		}
	}
	for(int i=1;i<=m;i++) if(b[n][i]) return;
	minn=tot;
	memcpy(ans,t,sizeof t);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int s=0;s<(1<<m);s++){
		judge(s);
	}
	if(minn==(1<<30)){
		puts("IMPOSSIBLE");
		return 0;
	}
	for(int i=1;i<=n;i++){
		printf("%d",ans[i][1]);
		for(int j=2;j<=m;j++){
			printf(" %d",ans[i][j]);
		}
		puts("");
	}
	return 0;
}
