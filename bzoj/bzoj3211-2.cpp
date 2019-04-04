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
int getint(){
	static int tmp;
	static char c;
	tmp=0;
	while(c=getchar(),c<'0'||c>'9');
	tmp=c-'0';
	while(c=getchar(),c>='0'&&c<='9'){
		tmp=tmp*10+c-'0';
	}
	return tmp;
}
int main(){
	n=getint();
	for(register int i=1;i<=n;i++){
		b[i]=a[i]=getint();
	}
	m=getint();
	for(register int i=1;i<n;i++){
		if(i+lowbit(i)<=n) b[i+lowbit(i)]+=b[i];
	}
	for(register int i=1;i<=n;i++) f[i]=i;f[n+1]=n+1;
	while(m--){
		x=getint();
		l=getint();
		r=getint();
		if(x==1){
			printf("%lld\n",ask(r)-ask(l-1));
		}else{
			for(register int i=get(l);i<=r;i=get(i+1)){
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
