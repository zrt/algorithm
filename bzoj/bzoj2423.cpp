#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define int long long
int n;
const int mod=100000000;
char a[5005],b[5005];
int f[2][5005],g[2][5005];
void Mod(int&a){
	a%=mod;
}
#undef int
int main(){
	#define int long long
	scanf("%s%s",a+1,b+1);
	int n=max(strlen(a+1),strlen(b+1));
	for(int i=1;i<=n;i++) g[0][i]=1;
	for(int i=1;a[i];i++){
		memset(f[i&1],0,sizeof f[i&1]);
		memset(g[i&1],0,sizeof g[i&1]);
		g[i&1][0]=1;g[(i&1)^1][0]=1;
		for(int j=1;b[j];j++){
			if(a[i]==b[j]){
				f[i&1][j]=max(f[i&1][j],f[(i&1)^1][j-1]+1);
				Mod(g[i&1][j]+=g[(i&1)^1][j-1]);
				if(f[(i&1)^1][j]==f[i&1][j])Mod(g[i&1][j]+=g[(i&1)^1][j]);
				if(f[i&1][j-1]==f[i&1][j])Mod(g[i&1][j]+=g[(i&1)][j-1]);
			}else{
				f[i&1][j]=max(f[i&1][j],max(f[(i&1)^1][j],f[i&1][j-1]));
				if(f[(i&1)^1][j]==f[i&1][j])Mod(g[i&1][j]+=g[(i&1)^1][j]);
				if(f[i&1][j-1]==f[i&1][j])Mod(g[i&1][j]+=g[(i&1)][j-1]);
				if(f[i&1][j]==(f[(i&1)^1][j-1])) Mod(g[i&1][j]-=g[(i&1)^1][j-1]);
			}
		}
	}
	int la=strlen(a+1),lb=strlen(b+1);
	printf("%lld\n%lld\n",f[la&1][lb]-1,(g[la&1][lb]%mod+mod)%mod);
	return 0;
}
