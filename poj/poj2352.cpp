#include<cstdio>
#include<cstring>
#define lowbit(x) (x&-x)
using namespace std;
int c[32005];
int n;
int x,y;
int maxn=32005;
inline void add(int pos){
	while(pos<maxn){
		c[pos]++;
		pos+=lowbit(pos);
	}
}
inline int ask(int pos){
	int ret=0;
	while(pos>0){
		ret+=c[pos];
		pos-=lowbit(pos);
	}
	return ret;
}
int p[15005];
int main(){
	memset(c,0,sizeof c);memset(p,0,sizeof p);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%*d",&x);
		x++;
		p[ask(x)]++;
		add(x);
	}
	for(int i=0;i<n;i++){
		printf("%d\n",p[i]);
	}
	return 0;
}