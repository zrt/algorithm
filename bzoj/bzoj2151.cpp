#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,m;
int a[200005];
bool del[200005];
struct N{
	int x,w;
	N(int a=0,int b=0){
		x=a,w=b;
	}
	friend bool operator < (N a,N b){
		return a.w<b.w;
	}
};
priority_queue<N> q;
int pre[200005],nxt[200005];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n/2<m){
		puts("Error!");
		return 0;
	}
	for(int i=1;i<=n;i++){
		q.push(N(i,a[i]));
		pre[i]=i-1;nxt[i]=i+1;
	}
	pre[1]=n;nxt[n]=1;
	int ans=0;
	for(int i=1;i<=m;i++){
		while(del[q.top().x]) q.pop();
		int x=q.top().x;q.pop();
		ans+=a[x];
		a[x]=a[pre[x]]+a[nxt[x]]-a[x];
		q.push(N(x,a[x]));
		del[pre[x]]=1;del[nxt[x]]=1;
		pre[x]=pre[pre[x]];
		nxt[pre[x]]=x;
		nxt[x]=nxt[nxt[x]];
		pre[nxt[x]]=x;
	}
	printf("%d\n",ans);
	return 0;
}
