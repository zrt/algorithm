/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//永远做自己会做的题就永远还是原来的样子
#include<cstdio>
//by zrt
//problem:
using namespace std;
int n,k;int cnt[1024];
int hefa[1024];
int count(int x){
	int ret=0;
	while(x){
		ret++;x&=(x-1);
	}
	return ret;
}
void dfs(int p,int pos){
	if(pos==9){
		cnt[p]=count(p);hefa[p]=1;return;
	}
	if(pos>9) return;
	if(p&1){
		dfs(p<<1,pos+1);
	}else{
		dfs(p<<1,pos+1);
		dfs((p<<1)+1,pos+1);
	}
}
long long f[10][90][1024];

int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&k);
	dfs(0,0);dfs(1,0);
	for(int i=0;i<1<<n;i++){
		if(hefa[i]) f[0][cnt[i]][i]=1;
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<1<<n;j++){
			if(hefa[j]){
				for(int p=k-cnt[j];p>=0;p--){
					for(int k=0;k<1<<n;k++){
						if(hefa[k]&&(!(j&k))&&hefa[j|k]){
							f[i][p+cnt[j]][j]+=f[i-1][p][k];
						}
					}
				}
			}
		}
	}
	long long sum=0;
	for(int i=0;i<1<<n;i++){
		if(hefa[i]){
			sum+=f[n-1][k][i];
		}
	}
	printf("%lld",sum);
	return 0;
}
