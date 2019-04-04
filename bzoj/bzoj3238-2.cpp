//SAM 后缀树 dp
#include<bits/stdc++.h>
using namespace std;
char s[500005];
int n;
int root,last,tot;
const int MAXN=500005*2;
int c[MAXN],l[MAXN],go[MAXN][26],fa[MAXN],t[MAXN],x[MAXN];
void add(int w){
	int p=last,np=++tot;
	last=np;l[np]=l[p]+1;c[np]++;
	while(p&&!go[p][w]) go[p][w]=np,p=fa[p];
	if(!p){
		fa[np]=root;
	}else{
		int q=go[p][w];
		if(l[q]==l[p]+1){
			fa[np]=q;
		}else{
			int nq=++tot;
			l[nq]=l[p]+1;
			fa[nq]=fa[q];
			memcpy(go[nq],go[q],sizeof go[q]);
			fa[np]=fa[q]=nq;
			while(go[p][w]==q) go[p][w]=nq,p=fa[p];
		}
	}
}
typedef long long LL;
LL ans;
int main(){
	root=last=++tot;
	scanf("%s",s);
	n=strlen(s);
	for(int i=n-1;i>=0;i--) add(s[i]-'a');
	for(int i=1;i<=tot;i++) t[l[i]]++;
	for(int i=1;i<=n;i++) t[i]+=t[i-1];
	for(int i=1;i<=tot;i++) x[t[l[i]]--]=i;
	for(int i=tot;i>=1;i--) if(fa[x[i]]) c[fa[x[i]]]+=c[x[i]];
	for(int i=1;i<=tot;i++){
		if(fa[i]){
			ans+=(l[i]-l[fa[i]])*1LL*(c[i]*1ll*(c[i]-1)/2);
		}
	}
	printf("%lld\n",n*1LL*(n-1)*(n+1)/2-2*ans);
	return 0;
}
