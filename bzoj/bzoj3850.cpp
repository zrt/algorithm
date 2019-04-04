#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long LL;
typedef long double ld;
void read(int&x){scanf("%d",&x);}
void read(long double&x){double xx;scanf("%lf",&xx);x=xx;}
void read(LL&x){scanf("%lld",&x);}
void read(char*s){scanf("%s",s);}

int n;
struct N{
	int t,k;
}a[100005];
bool cmp(N a,N b){
	return a.t*b.k<b.t*a.k;
}
int main(){
	read(n);
	for(int i=1;i<=n;i++) read(a[i].t);
	for(int i=1;i<=n;i++) read(a[i].k);
	sort(a+1,a+n+1,cmp);
	LL L(0),sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i].t;
		L+=sum*a[i].k;
	}
	printf("%lld\n",L);
	return 0;
}
