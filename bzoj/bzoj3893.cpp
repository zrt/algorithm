#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=100100;
int n,ans,pos[MAXN],spd[MAXN];
typedef long long LL;
LL T;
int main(){
	scanf("%d%lld",&n,&T);
	for(int i=1;i<=n;i++) scanf("%d%d",&pos[i],&spd[i]);
	pos[n+1]=spd[n+1]=~0U>>1;
	int slowest=n+1;
	for(int i=n;i>0;i--){
		if(pos[i]+spd[i]*T<pos[slowest]+spd[slowest]*T){
			ans++;
			slowest=i;
		}
	}
	printf("%d\n",ans);
	return 0;
}
