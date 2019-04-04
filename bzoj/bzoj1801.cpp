#include<iostream>
#include<cstdio>
#include<cstring>
#define MOD(x) {if(x>mod) x %=mod;}
//by zrt
//problem:
using namespace std;
long long f[105][105][105];//Ç°iÐÐ jÁÐ1 kÁÐ·Å2¸ö 
int mod=9999973;
int n,m;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	memset(f,-1,sizeof f);
	scanf("%d%d",&n,&m);
	f[0][0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k<=m;k++){
				if(f[i][j][k]==-1) continue;
				//1. bufang
				if(f[i+1][j][k]==-1) f[i+1][j][k]=0;
				f[i+1][j][k]+=f[i][j][k];
				MOD(f[i+1][j][k]);
				//2. fang yi ge in nothing
				if(m-j-k>0){
					if(f[i+1][j+1][k]==-1) f[i+1][j+1][k]=0;
					f[i+1][j+1][k]+=f[i][j][k]*(m-j-k);
					MOD(f[i+1][j+1][k]);
				}
				//3. fang yi ge in yi ge
				if(j>0){
					if(f[i+1][j-1][k+1]==-1)f[i+1][j-1][k+1]=0;
					f[i+1][j-1][k+1]+=f[i][j][k]*j;
					MOD(f[i+1][j-1][k+1]);
				}
				//4. fang liang ge in mei fang
				if(m-j-k>1){
					if(f[i+1][j+2][k]==-1) f[i+1][j+2][k]=0;
					f[i+1][j+2][k]+=f[i][j][k]*(m-j-k)*(m-j-k-1)/2;
					MOD(f[i+1][j+2][k]);
				}
				//5. fang yi ge in mei fang fang yi ge in 1 ge
				if(m-j-k>0&&j>0){
					if(f[i+1][j][k+1]==-1) f[i+1][j][k+1]=0;
					f[i+1][j][k+1]+=f[i][j][k]*(m-j-k)*j;
					MOD(f[i+1][j][k+1]);
				} 
				//6. fang liang ge in yi ge
				if(j>1){
					if(f[i+1][j-2][k+2]==-1) f[i+1][j-2][k+2]=0;
					f[i+1][j-2][k+2]+=f[i][j][k]*(j-1)*j/2;
					MOD(f[i+1][j-2][k+2]);
				}
			}
		}
	}
	long long ans=0;
	for(int j=0;j<=m;j++)
	for(int k=0;k<=m;k++){
		if(f[n][j][k]==-1) continue;
		ans+=f[n][j][k];
		MOD(ans);
	}
	printf("%lld",ans);
	return 0;
}
