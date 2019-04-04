#include<iostream>
#include<cstdio>
//by zrt
//problem:
using namespace std;
int H[2005],P[4000005],X[4000005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int n,m;
char s[20];
int tim,dfn[2005],low[2005],stk[2005],top,cnt,belong[2005];
bool instack[2005];
void tarjan(int u){
	low[u]=dfn[u]=++tim;
	stk[top++]=u;
	instack[u]=1;
	for(int i=H[u];i;i=X[i]){
		if(!dfn[P[i]]){
			tarjan(P[i]);
			low[u]=min(low[P[i]],low[u]);
		}else if(instack[P[i]]){
			low[u]=min(low[u],dfn[P[i]]);
		}
	}
	if(low[u]==dfn[u]){
		int k;
		++cnt;
		do{
			k=stk[--top];
			instack[k]=0;
			belong[k]=cnt;
		}while(k!=u);
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	int x,y,z;
	for(int i=0;i<m;i++){
		scanf("%d%d%d%s",&x,&y,&z,s);
		if(s[0]=='A'){
			if(z==1){
				add(x,x+n);add(y,y+n);
			}else{
				add(x+n,y);add(y+n,x);
			}
		}else if(s[0]=='O'){
			if(z==1){
				add(x,y+n);add(y,x+n);
			}else{
				add(y+n,y);add(x+n,x);
			}
		}else if(s[0]=='X'){
			if(z==1){
				add(x,y+n);add(y,x+n);add(x+n,y);add(y+n,x);
			}else{
				add(x,y);add(x+n,y+n);
			}
		}
	}
	for(int i=0;i<n;i++){
		if(!dfn[i]) tarjan(i);
	}
	for(int i=0;i<n;i++){
		if(belong[i]==belong[i+n])goto tp;
	}
	if(0){
		tp:;puts("NO");
	}else puts("YES");
	return 0;
}
