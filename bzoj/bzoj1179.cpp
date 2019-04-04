#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps(1e-10);
int n,m;
bool bar[500005];
int H[500005],P[500005],X[500005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int a[500005];
int low[500005];
int stk[500005],top;
bool instk[500005];
int tim,cnt;
int belong[500005];
queue<int> q;
void tarjan(int x){
	int dfn=low[x]=++tim;
	stk[top++]=x;
	instk[x]=1;
	for(int i=H[x];i;i=X[i]){
		if(!low[P[i]]){
			tarjan(P[i]);
			low[x]=min(low[x],low[P[i]]);
		}else if(instk[P[i]]) low[x]=min(low[x],low[P[i]]);
	}
	if(low[x]==dfn){
		int k;
		cnt++;
		do{
			k=stk[--top];
			instk[k]=0;
			belong[k]=cnt;
		}while(k!=x);
	}
}
int _H[500005],_P[500005],_X[500005],_tot;
inline void _add(int x,int y){
	_P[++_tot]=y;_X[_tot]=_H[x];_H[x]=_tot;
}
bool hasbar[500005];
int ind[500005];
int d[500005];
int siz[500005];
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
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int S,p;
	scanf("%d%d",&S,&p);
	memset(d,128,sizeof d);
	for(int i=0,x;i<p;i++){
		scanf("%d",&x);
		bar[x]=1;
	}
	for(int i=1;i<=n;i++){
		if(!low[i]) tarjan(i);
	}
	for(int i=1;i<=n;i++){
		if(bar[i]){
			hasbar[belong[i]]=1;
		}
		siz[belong[i]]+=a[i];
		for(int j=H[i];j;j=X[j]){
			if(belong[i]!=belong[P[j]]){
				_add(belong[P[j]],belong[i]);
				ind[belong[i]]++;
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		if(ind[i]==0){
			q.push(i);
		//	if(hasbar[i]) d[i]=siz[i];
		}
	}
	int k,v;
	while(!q.empty()){
		k=q.front();q.pop();
		if(hasbar[k]) d[k]=max(d[k],siz[k]);
		for(int i=_H[k];i;i=_X[i]){
			v=_P[i];
			ind[v]--;
			if(!ind[v]) q.push(v);
		//	if(d[k]){
				d[v]=max(d[v],d[k]+siz[v]);
		//	}
		}
	}
	printf("%d\n",d[belong[S]]);
	return 0;
}
