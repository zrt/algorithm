/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
#include<cstring>
//by zrt
//problem:
using namespace std;
// http://ydcydcy1.blog.163.com/blog/static/2160890402013195167512
/*
 1 3
 2 6
 4 x
*/
bool vis[100005];
bool hefa[8193];
int n;
void dfs(int p,int pos){
	if(pos==12){
		hefa[p]=1;
	}else{
		if(p&1){
			dfs(p<<1,pos+1);
		}else{
			dfs(p<<1,pos+1);
			dfs((p<<1)+1,pos+1);
		}
	}
}
unsigned mod=1000000001;
unsigned long long fangan=1;
int hang[18];
int length[18];
int dp[18][18];
unsigned f[18][4096];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	dfs(0,0);
	dfs(1,0);
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		else{
			memset(f,0,sizeof f);
			int m=0;
			vis[i]=1;
			dp[0][0]=i;
			length[0]=0;
			for(int i=1;dp[0][i-1]*3<=n;i++){
				dp[0][i]=dp[0][i-1]*3;
				vis[dp[0][i]]=1;
				length[0]=i;
			}
			for(int i=1;dp[i-1][0]<<1<=n;i++){
				m=i;
				length[i]=0;
				for(int j=0;j<=length[i-1];j++){
					if(dp[i-1][j]<<1<=n){
						dp[i][j]=dp[i-1][j]<<1;
						vis[dp[i][j]]=1;
						length[i]=j;
					}
				}
			}
			for(int i=0;i<1<<(length[0]+1);i++){
				if(hefa[i]) f[0][i]=1;
			}
			for(int i=1;i<=m;i++){
				for(int j=0;j<1<<(length[i]+1);j++){
					if(hefa[j]){
						for(int k=0;k<1<<(length[i-1]+1);k++){
							if(hefa[k]&&(!(j&k))){
								f[i][j]+=f[i-1][k];
								if(f[i][j]>=mod) f[i][j]-=mod;
							}
						}
					}
				}
			}
			unsigned sum=0;
			for(int i=0;i<1<<(length[m]+1);i++){
				if(hefa[i]){
					sum+=f[m][i];
					if(sum>=mod) sum-=mod;
				}
			}
			fangan*=sum;
			if(fangan>=mod) fangan%=mod;
		//	printf("%d\n",m);
		}
	}
	printf("%llu\n",fangan);
	return 0;
}
