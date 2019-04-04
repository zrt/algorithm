#include<cstdio>
#include<cstring>
#include<algorithm>
#include<deque>
//by zrt
//problem:
//
using namespace std;
typedef long long ll;
const double eps(1e-10);
const int inf(0x7fffffff);
struct N{
	int x,w;
	N(int a=0,int b=0){
		x=a,w=b;
	} 
};
deque<N> q;
#define MAXN 1020000 
int n,tmin[MAXN],tmax[MAXN];
int ans;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&tmin[i],&tmax[i]);
	}
	for(int i=1,a,b;i<=n;i++){
		a=tmin[i],b=tmax[i];
		int front=i;
		while(!q.empty() && q.front().w<=a){
			front=min(front,q.front().x);
			q.pop_front();
		}
		//feels 记录最小值递减 然后 队尾不合适的退出 更新答案。easy 
		q.push_front(N(front,a));
		while(!q.empty() && q.back().w> b){ 
			ans=max(ans,i-q.back().x);
			q.pop_back();
		}
	}
	while(!q.empty()){
		ans=max(ans,n-q.back().x+1);
		q.pop_back();
	}
	printf("%d\n",ans);
	///单调队列有点感觉了。 
	return 0;
}
