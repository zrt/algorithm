#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
const int MAXN=(1e6+250)*2;
char s[MAXN];
int root,tot,last;
int f[MAXN],l[MAXN],go[MAXN][27],L;
int c[MAXN],x[MAXN];
void add(int w){
	int p=last;
	int np=++tot;
	last=np;
	l[np]=l[p]+1;
	while(p&&!go[p][w]) go[p][w]=np,p=f[p];
	if(!p){
		f[np]=root;
	}else{
		int q=go[p][w];
		if(l[q]==l[p]+1){
			f[np]=q;
		}else{
			int nq=++tot;
			l[nq]=l[p]+1;
			memcpy(go[nq],go[q],sizeof go[q]);
			f[nq]=f[q];
			f[q]=f[np]=nq;
			while(p&&go[p][w]==q) go[p][w]=nq,p=f[p];
		}
	}
}
int main(){
	last=root=++tot;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		char c;
		while(c=getchar(),c>'z'||c<'a');
		while(c>='a'&&c<='z'){
			s[L++]=c-'a';
			c=getchar();
		}
		s[L++]=26;
	}
	for(int i=0;i<L;i++) add(s[i]);
	for(int i=1;i<=tot;i++) ++c[l[i]];
	for(int i=1;i<=L;i++) c[i]+=c[i-1];
	for(int i=1;i<=tot;i++) x[c[l[i]]--]=i;
	memset(c,0,sizeof c);
	int id=root;
	for(int i=0;i<L;i++){
		id=go[id][s[i]];
		c[id]=1;
	}
	for(int i=tot;i>0;i--){
		c[f[x[i]]]+=c[x[i]];
	}
	c[0]=0;c[1]=0;
	id=root;
	for(int i=0;i<L;i++){
		if(s[i]==26){
			printf("%d\n",c[id]);
			id=root;
		}else{
			id=go[id][s[i]];
		}
	}
	return 0;
}
