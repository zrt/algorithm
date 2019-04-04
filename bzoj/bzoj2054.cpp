#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
long long p,q;
int f[1500000];
int get(int x){
	return f[x]==x?x:f[x]=get(f[x]);
}
int a[1500000];
int main(){
	scanf("%d%d%lld%lld",&n,&m,&p,&q);
	for(int i=1;i<=n;i++) f[i]=i;f[n+1]=n+1;
	int L,R;
	for(int i=m;i>=1;i--){
		L=(i*p+q)%n+1;
		R=(i*q+p)%n+1;
		if(L>R) swap(L,R);	
		int p=get(L);
		for(;p<=R;){
			a[p]=max(i,a[p]);
			if(p+1<=n) f[p]=p+1;
			p++;p=get(p);
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",a[i]);
	}
	return 0;
}
