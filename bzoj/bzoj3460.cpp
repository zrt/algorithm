#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
#define int LL
int n,m,key;
int dfn[200005];
int belong[200005];
struct N{
	int x,y,id;
	N(int a=0,int b=0,int d=0){
		x=a,y=b,id=d;
		if(dfn[x]>dfn[y]) swap(x,y);
	}
	friend bool operator < (const N&a,const N&b){
		if(belong[a.x]!=belong[b.x]) return belong[a.x]<belong[b.x];
		return dfn[a.y]<dfn[b.y];
	}
}q[400005];
int to[200005],cc;
int t[200005];
int H[200005],X[200005],P[200005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
char s[10];
LL ans[400005];
int num,tim;
int stk[200005],top;
int SIZE;
int cnt;
int fa[200005][21];
int dep[200005];
void dfs(int x){
	int bot=top;dfn[x]=++tim;
	dep[x]=dep[fa[x][0]]+1;
	for(int i=H[x];i;i=X[i]){
		fa[P[i]][0]=x;
		dfs(P[i]);
		if(top-bot>=SIZE){
			cnt++;
			while(top>bot){
				belong[stk[--top]]=cnt;
			}
		}
	}
	stk[top++]=x;
}
bool v[200005];
LL Ans;
#define lowbit(x) ((x)&-(x))
struct BIT{
	long long c[200005];
	void add(int x,int d){
		while(x<=200000){
			c[x]+=d;
			x+=lowbit(x);
		}
	}
	LL ask(int x){
		LL ret=0;
		while(x>0){
			ret+=c[x];
			x-=lowbit(x);
		}
		return ret;
	}
}A,B;
//A sum
//B num
// <= x <
void do_(int x,int type){
	if(type){
		//add
		int p=t[x];
		Ans+=A.ask(p);// <=
		Ans+=(B.ask(200000)-B.ask(p))*1LL*to[t[x]];
		Ans+=to[t[x]];
		A.add(p,to[t[x]]);
		B.add(p,1);
	}else{
		//remove
		int p=t[x];
		A.add(p,-to[t[x]]);
		B.add(p,-1);
		Ans-=A.ask(p);// <=
		Ans-=(B.ask(200000)-B.ask(p))*1LL*to[t[x]];
		Ans-=to[t[x]];
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--) if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	if(x==y) return x;
	for(int i=20;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
#undef int
int main(){
	#define int LL
	scanf("%lld%lld%lld",&n,&m,&key);
	SIZE=sqrt((double)n)+1;
	for(int i=1;i<=n;i++) scanf("%lld",&t[i]),to[i]=t[i];
	sort(to+1,to+n+1);
	cc=unique(to+1,to+n+1)-(to+1);
	for(int i=1;i<=n;i++) t[i]=lower_bound(to+1,to+cc+1,t[i])-to;
	for(int i=1,x;i<=n;i++){
		scanf("%lld",&x);
		if(i==1) continue;
		add(x,i);
	}
	dfs(1);
	while(top>0) belong[stk[--top]]=cnt;
	for(int i=0,x=1;i<m;i++){
		scanf("%s",s);
		if(s[0]=='C'){
			scanf("%lld",&x);
		}else{
			int k;
			scanf("%lld",&k);
			int y=k%n+1;
			int qqq=num/2;
			q[num]=N(x,y,qqq<<1);
			num++;
			y=(k+key)%n+1;
			q[num]=N(x,y,qqq<<1|1);
			num++;
		}
	}
	for(int j=0;j<=19;j++){
		for(int i=1;i<=n;i++){
			fa[i][j+1]=fa[fa[i][j]][j];
		}
	}
	sort(q,q+num);
	int x=1,y=1;
	for(int i=0;i<num;i++){
		int qx=lca(x,q[i].x);
		int qy=lca(y,q[i].y);
		while(x!=qx){
			do_(x,v[x]^=1);
			x=fa[x][0];
		}
		x=q[i].x;
		while(x!=qx){
			do_(x,v[x]^=1);
			x=fa[x][0];
		}
		while(y!=qy){
			do_(y,v[y]^=1);
			y=fa[y][0];
		}
		y=q[i].y;
		while(y!=qy){
			do_(y,v[y]^=1);
			y=fa[y][0];
		}
		x=lca(q[i].x,q[i].y);
		do_(x,v[x]^=1);
		ans[q[i].id]=Ans;
		do_(x,v[x]^=1);
		x=q[i].x,y=q[i].y;
	}
	LL pre=0;
	for(int i=0;i<num/2;i++){
		if(pre&1){
			printf("%lld\n",pre=ans[i<<1|1]);
		}else{
			printf("%lld\n",pre=ans[i<<1]);
		}
	}
	return 0;
}
/*
3 2 0
3 3 2
0 3 1
C 3
Q 1


7




*/
