#include <cstdio>
#include <cstring>
#include <algorithm>
#include<queue>
//by zrt
//problem:
using namespace std;
const int inf(0x3f3f3f3f) ;
const double eps(1e-10) ;
typedef long long LL;
struct N{
	int x,w;
	N(int a=0,int b=0){
		x=a,w=b;
	}
}tmp;
queue<N> q;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		q.push(N(i,x));
	}
	int last;
	while(!q.empty()){
		tmp=q.front();q.pop();
		last=tmp.x;
		tmp.w-=m;
		if(tmp.w>0) q.push(tmp);
	}
	printf("%d\n",last);
	return 0;
}

