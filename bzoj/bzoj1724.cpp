/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
#include<queue>
//by zrt
//problem:
using namespace std;
struct N{
	int x;
	N(int a=0) {
		x=a;
	}
	friend bool operator < (N a,N b){
		return a.x>b.x;
	}
};
priority_queue<N> q;
int n,x;
long long sum=0;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		q.push(N(x));
	}
	int k,p;
	while(1){
		k=q.top().x;
		q.pop();
		if(q.empty()) break;
		p=q.top().x;
		q.pop();
		sum+=k+p;
		q.push(N(k+p));
	}
	printf("%lld\n",sum);
	
	return 0;
}
