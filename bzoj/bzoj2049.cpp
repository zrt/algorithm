#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,x,y;
char s[20];
bool rev[10005];
int ls[10005],rs[10005],fa[10005];
bool notroot(int x){
	return ls[fa[x]]==x||rs[fa[x]]==x;
}
void zig(int x){
	int y=fa[x];
	if(rs[x]) ls[y]=rs[x],fa[rs[x]]=y;else ls[y]=0;
	fa[x]=fa[y];
	if(ls[fa[y]]==y) ls[fa[y]]=x;else if(rs[fa[y]]==y) rs[fa[y]]=x;
	fa[y]=x;
	rs[x]=y;
}
void zag(int x){
	int y=fa[x];
	if(ls[x]) rs[y]=ls[x],fa[ls[x]]=y;else rs[y]=0;
	fa[x]=fa[y];
	if(ls[fa[y]]==y) ls[fa[y]]=x;else if(rs[fa[y]]==y) rs[fa[y]]=x;
	fa[y]=x;
	ls[x]=y;
}
void pushdown(int x){
	if(rev[x]){
		swap(ls[x],rs[x]);
		rev[x]=0;
		rev[ls[x]]^=1;
		rev[rs[x]]^=1;
	}
}
int list[10005],t;
void splay(int x){
	int y=x;t=0;
	for(;notroot(y);y=fa[y]) list[t++]=y;
	pushdown(y);
	for(int i=t-1;i>=0;i--) pushdown(list[i]);
	while(notroot(x)){
		int y=fa[x];
		if(!notroot(y)){
			if(ls[y]==x) zig(x);
			else zag(x);
		}else{
			if(ls[fa[y]]==y){
				if(ls[y]==x) zig(y),zig(x);
				else zag(x),zig(x);
			}else{
				if(ls[y]==x) zig(x),zag(x);
				else zag(y),zag(x);
			}
		}
	}
}
void access(int x){
	int y=0;
	while(x){
		splay(x);
		rs[x]=y;//up(x)
		y=x;
		x=fa[x];
	}
}
void mkroot(int x){
	access(x);
	splay(x);
	rev[x]^=1;
	pushdown(x);
}
void link(int x,int y){
	mkroot(x);
	pushdown(y);
	fa[x]=y;
	access(x);
}
void cut(int x,int y){
	mkroot(x);
	access(y);
	splay(x);
	fa[y]=rs[x]=0;
}
bool ask(int x,int y){
	mkroot(x);
	access(y);
	splay(x);
	while(notroot(y)) y=fa[y];
	return y==x;
}
int main(){
	//freopen("zqt.in","r",stdin);
	//freopen("zqt.out","w",stdout);
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%s%d%d",s,&x,&y);
		if(s[0]=='C') link(x,y);
		else if(s[0]=='D') cut(x,y);
		else{
			if(ask(x,y)) puts("Yes");
			else puts("No");
		}
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
