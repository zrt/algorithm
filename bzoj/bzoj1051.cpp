#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int n,m;
int H[10005],X[50005],P[50005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
bool instk[10005];
int stk[10005],top;
int low[10005];
int tim;
int cnt;
int belong[10005];
int siz[10005];
void tarjan(int x){
	instk[x]=1;
	stk[top++]=x;
	int dfn=low[x]=++tim;
	for(int i=H[x];i;i=X[i]){
		if(!low[P[i]]){
			tarjan(P[i]);
			low[x]=min(low[x],low[P[i]]);
		}else if(instk[P[i]])low[x]=min(low[x],low[P[i]]);
	}
	if(dfn==low[x]) {
		cnt++;
		int k;
		do{
			k=stk[--top];
			instk[k]=0;
			belong[k]=cnt;
			siz[cnt]++;
		}while(k!=x);
	}
}
int out[10005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=0,x,y;i<m;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	for(int i=1;i<=n;i++) if(!low[i]) tarjan(i);
	for(int i=1;i<=n;i++){
		for(int j=H[i];j;j=X[j]){
			if(belong[i]!=belong[P[j]]){
				out[belong[i]]++;
			}
		}
	}
	int sum=0,pos;
	for(int i=1;i<=cnt;i++){
		if(!out[i]){
			sum++;
			pos=i;
		}
	}
	if(sum==1){
		printf("%d\n",siz[pos]);
	}else printf("0\n");
	return 0;
}
