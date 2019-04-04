/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
//by zrt
//problem:
using namespace std;
int H[1005],P[2005],X[2005],E[2005],tot;
int st[1005];
bool vis[1005];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
void dfs(int x){
	vis[x]=1;
	for(int i=H[x];i;i=X[i]){
		if(!vis[P[i]]){
			if(E[i]){
				st[P[i]]=st[x]^1;
			}else st[P[i]]=st[x];
			dfs(P[i]);
		}
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int n;
	scanf("%d",&n);
	int x,y,z;
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	dfs(1);
	if(st[n]) puts("1");
	else puts("0");
	return 0;
}
