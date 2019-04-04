#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define lowbit(x) ((x)&-(x))
int f[100060];
int a[100060];
typedef long long LL;
LL b[100060];
int n,m;
int get(int x){
	return f[x]==x?x:f[x]=get(f[x]);
}
int x,l,r;
void add(int x,int d){
	while(x<=n){
		b[x]+=d;
		x+=lowbit(x);
	}
}
LL ask(int x){
	LL ret=0;
	while(x>0){
		ret+=b[x];
		x-=lowbit(x);
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);b[i]=a[i];
	}
	scanf("%d",&m);
	for(int i=1;i<n;i++){
		if(i+lowbit(i)<=n) b[i+lowbit(i)]+=b[i];
	}
	for(int i=1;i<=n;i++) f[i]=i;f[n+1]=n+1;
	while(m--){
		scanf("%d%d%d",&x,&l,&r);
		if(x==1){
			printf("%lld\n",ask(r)-ask(l-1));
		}else{
			for(int i=get(l);i<=r;i=get(i+1)){
				int tmp=(int)sqrt((double)a[i]);
				add(i,tmp-a[i]);
				a[i]=tmp;
				if(a[i]<=1){
					f[i]=get(i+1);
				}
			}
		}
	}
	return 0;
}
