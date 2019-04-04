#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
int n;LL k;
char s[1000005];
int p[1000005];
LL num[1000005];//odd
const int mod=19930726;
void manacher(){
	int id=0,mx=-1;
	for(int i=1;i<=n;i++){
		if(i<mx){
			p[i]=min(mx-i,p[id-(i-id)]);
		}else{
			p[i]=1;
		}
		while(s[i+p[i]]==s[i-p[i]]) p[i]++;
		num[p[i]]++;
		if(i+p[i]>=mx){
			mx=i+p[i];
			id=i;
		}
	}
}
int pow(int a,LL b,int p){
	int ret=1;
	while(b){
		if(b&1) ret=ret*1LL*a%p;
		a=a*1LL*a%p;
		b>>=1;
	}
	return ret;
}
int main(){
	scanf("%d%lld%s",&n,&k,s+1);
	s[0]='#';
	manacher();
	LL ans=1;
	for(int i=n/2+1;i>0;i--){
		if(num[i]){
			if(num[i]>=k){
				ans=ans*pow((i*2-1),k,mod)%mod;
				break;
			}else{
				num[i-1]+=num[i];
				ans=ans*pow((i*2-1),num[i],mod)%mod;
				k-=num[i];
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
