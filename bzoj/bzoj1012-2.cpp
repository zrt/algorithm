#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;
#define MAXN 200005
int m,mod,T,x;
char s[10];
struct N{
	int x,w;
}q[MAXN];
int h,t,pos;
void add(int x){
	pos++;
	while(h!=t&&q[t-1].w<=x) t--;
	q[t].w=x,q[t].x=pos;t++;
	return;
}
int ask(int L){
	int Pos=pos-L;
	//x > Pos de di yi ge shu
	int l=-1,r=t-1,m;
	while(r-l>1){
		m=(l+r)>>1;
		if(q[m].x>Pos)
			r=m;
		else l=m;
	}
	return q[r].w;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d%d",&m,&mod);
	while(m--){
		scanf("%s%d",s,&x);
		if(s[0]=='A')	add((x+T)%mod);
		else	printf("%d\n",T=ask(x));
	}
	return 0 ;
}
