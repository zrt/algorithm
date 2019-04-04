#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int f[205];
struct N{
	int a,b,c,t;
}q[10005];
int n,m;
int _a,_b;
bool cmpc(N a,N b){
	return a.c<b.c;
}
bool cmpt(N a,N b){
	return a.t<b.t;
}
bool cmpp(N a,N b){
	return _a*a.c+_b*a.t<_a*b.c+_b*b.t;
}
//x --> c y--> t
int ansc,anst;
void upd(int sumc,int sumt){
	if(ansc*1LL*anst>sumc*1LL*sumt){
		ansc=sumc;anst=sumt;
	}else if(ansc*1LL*anst==sumc*1LL*sumt&&sumc<ansc){
		ansc=sumc;anst=sumt;
	}
}
int get(int x){
	return x==f[x]?x:f[x]=get(f[x]);
}
void Kruskal(int&sumc,int&sumt){//sorted
	for(int i=1;i<=n;i++) f[i]=i;
	sumc=sumt=0;
	for(int i=0;i<m;i++){
		if(get(q[i].a)!=get(q[i].b)){
			sumc+=q[i].c,sumt+=q[i].t;
			f[get(q[i].a)]=get(q[i].b);
		}
	}
}

void solve(int x1,int y1,int x2,int y2){//Ax+By+C==0 C<0
	if(x1==x2&&y1==y2) return ;
	_a=y1-y2;
	_b=x2-x1;
	int C=-x2*y1+x1*y2;
	if(C>0) _a*=-1,_b*=-1,C*=-1;
	sort(q,q+m,cmpp);
	int x0,y0;
	Kruskal(x0,y0);
	upd(x0,y0);
	if(_a*x0+_b*y0+C>=0) return;
	solve(x1,y1,x0,y0);solve(x2,y2,x0,y0);
}
int x1,y1,x2,y2;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d",&q[i].a,&q[i].b,&q[i].c,&q[i].t);
		q[i].a++;q[i].b++;
	}
	ansc=anst=inf;
	sort(q,q+m,cmpc);
	Kruskal(x1,y1);
	upd(x1,y1);
	sort(q,q+m,cmpt);
	Kruskal(x2,y2);
	upd(x2,y2);
	solve(x1,y1,x2,y2);
	printf("%d %d\n",ansc,anst);
	return 0;
}
