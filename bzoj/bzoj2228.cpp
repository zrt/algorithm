#include <cstdio>
#include <cstring>
#include <algorithm>
//by zrt
//problem:
using namespace std;
const int inf(0x3f3f3f3f) ;
const double eps(1e-10) ;
typedef long long LL;
bool ok[155][155][155];
int dp[155][155][155];
char s[200];
int ans=0;
struct N{
	int x,w;//kuan gao
	N(int a=0,int b=0){
		x=a,w=b;
	}
};
int top;
struct ddz{
	N stk[200];
	int top;
	void clear(){
		top=0;
	}
	void insert(N a){
		int tmp=0;
		while(top>0&&stk[top-1].w>=a.w){
			a.x+=stk[top-1].x;tmp+=stk[top-1].x;
			ans=max(ans,tmp*stk[top-1].w);
			top--;
		}
		stk[top++]=a;
	}
	void qingkong(){
		int tmp=0;
		while(top>0){
			tmp+=stk[top-1].x;
			ans=max(ans,tmp*stk[top-1].w);
			top--;
		}
	}
}ddz;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int p,q,r;
	scanf("%d%d%d",&p,&q,&r);
	for(int i=1;i<=q;i++){//y
		for(int j=1;j<=p;j++){//x
			scanf("%s",s+1);
			for(int k=1;k<=r;k++){
				if(s[k]=='N') ok[j][i][k]=1;
			}
		}
	}
	//xy (pq)
	//dp
	for(int z=1;z<=r;z++){
		for(int x=1;x<=p;x++){
			for(int y=1;y<=q;y++){
				if(ok[x][y][z])dp[x][y][z]=min(dp[x-1][y][z],min(dp[x][y-1][z],dp[x-1][y-1][z])) +1;
				else dp[x][y][z]=0;
			}
		}
	}
	//dandiaozhan
	for(int x=1;x<=p;x++){
		for(int y=1;y<=q;y++){
			ddz.clear();
			for(int z=1;z<=r;z++){
				ddz.insert(N(1,dp[x][y][z]));
			}
			ddz.qingkong();
		}
	}
	
	//xz (pr)
	for(int y=1;y<=q;y++){
		for(int x=1;x<=p;x++){
			for(int z=1;z<=r;z++){
				if(ok[x][y][z])dp[x][y][z]=min(dp[x-1][y][z],min(dp[x][y][z-1],dp[x-1][y][z-1])) +1;
				else dp[x][y][z]=0;
			}
		}
	}
	for(int x=1;x<=p;x++){
		for(int z=1;z<=r;z++){
			ddz.clear();
			for(int y=1;y<=q;y++){
				ddz.insert(N(1,dp[x][y][z]));
			}
			ddz.qingkong();
		}
	}
	//yz (qr)
	for(int x=1;x<=p;x++){
		for(int y=1;y<=q;y++){
			for(int z=1;z<=r;z++){
				if(ok[x][y][z])dp[x][y][z]=min(dp[x][y-1][z],min(dp[x][y][z-1],dp[x][y-1][z-1])) +1;
				else dp[x][y][z]=0;
			}
		}
	}
	for(int y=1;y<=q;y++){
		for(int z=1;z<=r;z++){
			ddz.clear();
			for(int x=1;x<=p;x++){
				ddz.insert(N(1,dp[x][y][z]));
			}
			ddz.qingkong();
		}
	}
	printf("%d\n",ans*4);
	return 0;
}
