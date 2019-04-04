#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int H[100005],X[100005],P[100005];
int tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
long long ans[100005];
int low[100005];
int stk[100005];
bool instk[100005];
int to[100005];
int belong[100005];
int hav[100005];
int cnt,tim;
int top;
void tarjan(int x){
	int dfn=low[x]=++tim;
	stk[top++]=x;instk[x]=1;
	if(!low[to[x]]){
		tarjan(to[x]);
		low[x]=min(low[x],low[to[x]]);
	}else if(instk[to[x]]) low[x]=min(low[x],low[to[x]]);
	if(dfn==low[x]){
		int k;
		cnt++;
		do{
			k=stk[--top];
			instk[k]=0;
			belong[k]=cnt;
			hav[cnt]++;
		}while(x!=k);
	}
}
int ask(int x){
	if(ans[x]) return ans[x];
	ans[x]=hav[x];
	if(hav[x]==1)
		ans[x]+=ask(P[H[x]]);
	return ans[x];
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&to[i]);
	}
	for(int i=1;i<=n;i++){
		if(!low[i]) tarjan(i);
	}
	for(int i=1;i<=n;i++){
		if(belong[i]!=belong[to[i]]) add(belong[i],belong[to[i]]);
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",ask(belong[i]));
	}
	return 0;
}
