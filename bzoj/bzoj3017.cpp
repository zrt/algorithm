#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
int f[1005][1005];
char s[1005];
int l;
int sum[1005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%s",s+1);
	l=strlen(s+1);
	f[0][0]=1;
	for(int i=1;i<=l;i++){
		sum[i]=sum[i-1]+(s[i]=='('?1:(-1));
	}
	for(int i=0;i<l;i++){
		for(int j=0;j<=i;j++){
			if(f[i][j]){
				int k=sum[i]-j;
				if(k<0) continue;
				if(s[i+1]=='('){
					(f[i+1][j]+=f[i][j])%=2012;
					(f[i+1][j+1]+=f[i][j])%=2012;
				}else{
					if(j>0) (f[i+1][j-1] += f[i][j])%=2012;
					if(k>0) (f[i+1][j] += f[i][j])%=2012;
				}
			}
		}
	}
	printf("%d\n",f[l][0]);
	
	return 0;
}
