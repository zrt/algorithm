#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=6005;
char s[MAXN];
int root,last,tot;
int l[MAXN],go[MAXN][2],fa[MAXN];
int c[MAXN],t[MAXN],x[MAXN];
void add(int w){
	int p=last,np=++tot;
	last=np;l[np]=l[p]+1;
	c[np]++;
	while(p&&!go[p][w]) go[p][w]=np,p=fa[p];
	if(!p){
		fa[np]=root;
	}else{
		int q=go[p][w];
		if(l[q]==l[p]+1){
			fa[np]=q;
		}else{
			int nq=++tot;
			fa[nq]=fa[q];
			l[nq]=l[p]+1;
			fa[np]=fa[q]=nq;
			memcpy(go[nq],go[q],sizeof go[q]);
			while(go[p][w]==q) go[p][w]=nq,p=fa[p];
		}
	}
}
int n;
void dfs(int x){
	if(l[x]>0&&c[x]>1) printf("%d\n",c[x]);
	for(int i=0;i<2;i++){
		if(go[x][i]) dfs(go[x][i]);
	}
}
int main(){
	root=last=++tot;
	scanf("%d%s",&n,s);
	for(int i=0;i<n;i++) add(s[i]-'0');
	for(int i=1;i<=tot;i++) t[l[i]]++;
	for(int i=1;i<=n;i++) t[i]+=t[i-1];
	for(int i=1;i<=tot;i++) x[t[l[i]]--]=i;
	for(int i=tot;i>0;i--) if(fa[x[i]]) c[fa[x[i]]]+=c[x[i]];
	dfs(root);
	return 0;
}
