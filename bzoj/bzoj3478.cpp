#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
//by zrt

using namespace std;
typedef long long LL;
priority_queue<int> q;
int n;
int a[505];
int k;
int ans[505];
int stk[505];
int top;
bool check(){
	int x;
	while(!q.empty()){
		x=q.top();
		q.pop();
		if(x==0) continue;
		if(q.size()<x) return 0;
		top=0;
		for(int i=0;i<x;i++){
			int tmp=q.top();
			if(!tmp) return 0;
			q.pop();
			if(tmp>1)stk[top++]=tmp-1;
		}
		while(top>0) q.push(stk[--top]);
	}
	return 1;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=0;i<=n;i++) scanf("%d",&a[i]);
	for(int i=0;i<=n;i++){
		while(!q.empty()) q.pop();
		for(int j=0;j<=n;j++){
			if(i!=j){
				q.push(a[j]);
			}
		}
		if(check()) ans[++k]=i+1;
	}
	printf("%d\n",k);
	for(int i=1;i<=k;i++){
		printf("%d\n",ans[i]);
	}
	
	return 0;
}
