#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps(1e-10);
int n;
int H[1000005],X[1000005],P[1000005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int tim,low[1000005],stk[1000005],top;
bool instack[1000005];
int cnt;
int belong[1000005];
void tarjan(int x){
	int dfn=low[x]=++tim;
	instack[x]=1;stk[top++]=x;
	for(int i=H[x];i;i=X[i]){
		if(!low[P[i]]) tarjan(P[i]),low[x]=min(low[x],low[P[i]]);
		else if(instack[P[i]]) low[x]=min(low[x],low[P[i]]);
	}
	if(low[x]==dfn){
		cnt++;
		int k;
		do{
			k=stk[--top];
			instack[k]=0;
			belong[k]=cnt;
		}while(k!=x);
	}
}
bool ind[1000005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		add(x,i);
	}
	for(int i=1;i<=n;i++){
		if(!low[i]) tarjan(i);
	}
	for(int i=1;i<=n;i++){
		for(int j=H[i];j;j=X[j]){
			if(belong[i]!=belong[P[j]]) ind[belong[P[j]]]=1;
		}
	}
	int ot=0;
	for(int i=1;i<=cnt;i++){
		if(!ind[i]) ot++;
	}
	printf("%d\n",ot);
	return 0;
}
