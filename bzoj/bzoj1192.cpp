#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps(1e-10);
int n;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	int tot=0;
	for(int i=1;n-i>=0;i<<=1) n-=i,tot++;
	if(n>0) tot++;
//	if((n>1)&&((n&(n-1))==0)) tot++;
	printf("%d\n",tot);
	return 0;
}
