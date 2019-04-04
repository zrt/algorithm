#include<iostream>
#include<cstdio>
//by zrt
//problem:
using namespace std;
int n,m,x[50500],y[50500],a,b;
int H[150000],X[350000],P[350000],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int dfn[150000],low[150000],cnt,tim,point[150000],stk[150000],top;
bool instack[150000];
void tarjan(int u){
	low[u]=dfn[u]=++tim;
	instack[u]=1;stk[top++]=u;
	for(int i=H[u];i;i=X[i]){
		if(!dfn[P[i]]){
			tarjan(P[i]);
			low[u]=min(low[u],low[P[i]]);
		}else if(instack[P[i]]){
			low[u]=min(low[u],dfn[P[i]]);
		}
	}
	if(low[u]==dfn[u]){
		++cnt;int k;
		do{
			k=stk[--top];instack[k]=0;
			point[k]=cnt;
		}while(k!=u);
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		x[i]=min(a,b);y[i]=x[i]^a^b;
	}
	for(int i=0;i<m;i++){
		for(int j=i+1;j<m;j++){
			if((x[j]>x[i]&&x[j]<y[i]&&(y[j]<x[i]||y[j]>y[i]))||(y[j]>x[i]&&y[j]<y[i]&&(x[j]<x[i]||x[j]>y[i]))){
				add(i,j+m);
				add(j,i+m);
				add(i+m,j);
				add(j+m,i);
			}
		}
	}
	int m2=m*2;
	for(int i=0;i<m2;i++){
		if(!dfn[i]) tarjan(i);
	}
	bool ok=1;
	for(int i=0;i<m&&ok;i++){
		if(point[i]==point[i+m]) ok=0;
	}
	if(ok) puts("panda is telling the truth...");
	else puts("the evil panda is lying again");
	return 0;
}