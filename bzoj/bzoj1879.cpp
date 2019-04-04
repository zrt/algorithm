#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,k;
const int mod=1000003;
char s[16][55];
int f[55][1<<15];
int count(int x){
	int ret=0;
	while(x){
		ret++;
		x&=(x-1);
	}
	return ret;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++) scanf("%s",s[i]+1);
		memset(f,0,sizeof f);
		f[0][(1<<n)-1]=1;
		int L=strlen(s[0]+1);
		for(int i=0;i<=L;i++){
			for(int j=0;j<1<<n;j++){
				if(f[i][j]){
					for(int k=0;k<26;k++){
						int to=j;
						for(int p=0;p<n;p++){
							if(j&(1<<p)){
								if(s[p][i+1]=='?'||s[p][i+1]=='a'+k) continue;
								to^=1<<p;
							}
						}
						f[i+1][to]+=f[i][j];
						if(f[i+1][to]>=mod) f[i+1][to]-=mod;
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<1<<n;i++){
			if(count(i)==k){
				ans=(ans+f[L][i])%mod;
			}
		}
		printf("%d\n",ans);
	}
	
	
	
	return 0;
}
