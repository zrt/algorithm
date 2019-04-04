#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps(1e-10);
/*
Sub(x) = sigma Sub(childk) + 1
Down(x) = sigma Down(childk) + Sub(x)
Up(x) = Up(Fa(x)) + Down(Fa(x)) ?Down(x) ?Sub(x) + N ?Sub(x)

*/
int n;
int H[1000005],P[2000005],X[2000005],tot;
inline void add(int x,int y){
	P[++tot]=y,X[tot]=H[x],H[x]=tot;
}
long long son[1000005],down[1000005],up[1000005],fa[1000005];
int stk[20000050],top;
bool vis[1000005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	tot=1;
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	stk[top++]=1;
	int x;
	while(top>0){
		x=stk[--top];
		if(!vis[x]){
			vis[x]=1;
			stk[top++]=x;
			for(int i=H[x];i;i=X[i]){
				if(P[i]==fa[x]) continue;
				fa[P[i]]=x;
				stk[top++]=P[i];
			}
		}else{
			for(int i=H[x];i;i=X[i]){
				if(P[i]==fa[x]) continue;
				son[x]+=son[P[i]];
				down[x]+=down[P[i]];
			}
			son[x]+=1;
			down[x]+=son[x];
		}
	}
	stk[top++]=1;
	while(top>0){
		x=stk[--top];
		if(fa[x]!=0) up[x]=up[fa[x]]+down[fa[x]]-down[x]-son[x]+n-son[x];
		for(int i=H[x];i;i=X[i]){
			if(P[i]==fa[x]) continue;
			stk[top++]=P[i];
		}
	}
	long long maxn=-1;int maxx;
	for(int i=1;i<=n;i++){
		if(up[i]+down[i]>maxn){
			maxn=up[i]+down[i];
			maxx=i;
		}
	}
	printf("%d\n",maxx);
	return 0;
}
