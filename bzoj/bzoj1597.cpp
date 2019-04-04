/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//永远做自己会做的题就永远还是原来的样子
// 有时间了再重写一遍 不太懂还是.... !!!
#include<cstdio>
#include<algorithm>
//by zrt
//problem:
using namespace std;
struct N{
	long long x,y;
	friend bool operator < (N a,N b){
		if(a.x!=b.x) return a.x>b.x;
		return a.y>b.y;
	}
};
const int maxn=50007;
N a[maxn];
// cmp a/b c/d  < -1 > 1 == 0
inline int cmprc(long long a,long long b,long long c,long long d){
	long long t1=a/b,t2=c/d;
	//避免浮点数误差 
	if(t1!=t2){
		if(t1<t2) return -1;
		else return 1;
	}
	a-=t1*b;
	c-=t2*d;
	t1=a*d;t2=b*c;// 移项
	if(t1<t2) return -1;
	else if(t1>t2) return 1;
	else return 0; 
}
long long f[maxn];
int Q[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].x,&a[i].y);
	}
	sort(a+1,a+n+1);
	//http://lightsky0713.blog.163.com/blog/static/223581083201362785923281/
	//巧妙的去重
	int m=1; 
	for(int i=2;i<=n;i++){
		if(a[i].y>a[m].y)
			a[++m]=a[i];
	}
	n=m;
	//去重 完毕 x递减 y递增
	// 斜率优化: 
	int lo=1,hi=1;
	f[1]=a[1].x*a[1].y;
	Q[1]=1;
	for(int i=2;i<=n;i++){
		while(lo<hi&&cmprc(f[Q[lo]-1]-f[Q[lo+1]-1],a[Q[lo]].x-a[Q[lo+1]].x,-a[i].y,1)>=0) //核心 比较 前两个的斜率 与新增的斜率 
			lo++; 
		//这个状态转移或者队首转移 
		f[i]=min(f[i-1]+a[i].x*a[i].y,f[Q[lo]-1]+a[Q[lo]].x*a[i].y);
		//维护类似凸包 ？/
		while(lo<hi&&cmprc(f[i-1]-f[Q[hi]-1],a[i].x-a[Q[hi]].x,f[Q[hi]-1]-f[Q[hi-1]-1],a[Q[hi]].x-a[Q[hi-1]].x)>=0)
			hi--;
		Q[++hi]=i;
	}
	printf("%lld\n",f[n]);
	return 0;
}
