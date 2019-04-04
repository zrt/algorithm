#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
bool oncircle[100005];
int du[100005];
int fa[100005];
int H[100005],X[200005],P[200005],tot;
double E[200005];
inline void add(int x,int y,int z){//add an edge
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
int n,m;
double F[100005];//for son E
double D[100005];// F * |son|
double p[100005];// ans
int num[100005];// |son|
int pre[100005];
double wpre[100005];
bool type;
void treedp1(int x){//Dp the tree first
	for(int i=H[x];i;i=X[i]){
		if(P[i]==fa[x]||oncircle[P[i]]) continue;
		fa[P[i]]=x;
		treedp1(P[i]);
		D[x]+=F[P[i]]+E[i];num[x]++;
	}
	if(num[x])
	F[x]=D[x]/num[x];
	else F[x]=0;
}
void treedp2(int x,double edge){//Dp the tree second | calc the P
	double other;
	if(!fa[fa[x]]) {
		if(!type){
			if(num[fa[x]]>1) other=(p[fa[x]]*(num[fa[x]]+0)-edge-F[x])/(num[fa[x]]-1)+edge;
			else other=edge;
		}else{
			other=(p[fa[x]]*(num[fa[x]]+2)-edge-F[x])/(num[fa[x]]+1)+edge;
		}
	}
	else other=(p[fa[x]]*(num[fa[x]]+1)-edge-F[x])/num[fa[x]]+edge;
	
	p[x]=(other+D[x])/(num[x]+1);
	for(int i=H[x];i;i=X[i]){
		if(P[i]==fa[x]||oncircle[P[i]]) continue;
		treedp2(P[i],E[i]);
	}
}
vector<int> circle;
bool ok;
int nxt[100005];double wnxt[100005];
void findcircle(int x,int fa){
	for(int i=H[x];i;i=X[i]){
		if(P[i]==fa) continue;
		if(pre[P[i]]){
			ok=1;
			int k=x;
			pre[P[i]]=x;
			wpre[P[i]]=E[i];
			do{
				oncircle[k]=1;
				circle.push_back(k);
				k=pre[k];
			}while(k!=P[i]);
			oncircle[k]=1;
			circle.push_back(k);
		}else{
			pre[P[i]]=x;wpre[P[i]]=E[i];
			findcircle(P[i],x);
			if(ok) return;
		}
	}
}
double calc_nxt(int now,int end){
	double ret=wnxt[now];
	now=nxt[now];
	int extra=0;
	if(nxt[now]!=end) ret+=calc_nxt(now,end)/(du[now]-1);
	else extra=-1;
	for(int i=H[now];i;i=X[i]){
		if(oncircle[P[i]]) continue;
		ret+=(E[i]+F[P[i]])/(du[now]-1+extra);
	}
	return ret;
}
double calc_pre(int now,int end){
	double ret=wpre[now];
	now=pre[now];
	int extra=0;
	if(pre[now]!=end) ret+=calc_pre(now,end)/(du[now]-1);
	else extra=-1;
	for(int i=H[now];i;i=X[i]){
		if(oncircle[P[i]]) continue;
		ret+=(E[i]+F[P[i]])/(du[now]-1+extra);
	}
	return ret;
}
int main(){// the main function
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=0,x,y,z;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		du[x]++;
		du[y]++;
		add(x,y,z);
		add(y,x,z);
	}
	if(m==n-1){
		treedp1(1);
		p[1]=F[1];
		for(int i=H[1];i;i=X[i]){
			treedp2(P[i],E[i]);
		}
		double ans=0;
		for(int i=1;i<=n;i++){
			 ans+=p[i];
		}
		printf("%.5f\n",ans/n);
	}else{
		type=1;
		pre[1]=-1;
		findcircle(1,-1);
		for(int now=0;now<circle.size();now++){
			nxt[pre[circle[now]]]=circle[now];
			wnxt[pre[circle[now]]]=wpre[circle[now]];
		}
		for(int now=0;now<circle.size();now++){
			for(int i=H[circle[now]];i;i=X[i]){
				if(oncircle[P[i]]) continue;
				treedp1(P[i]);
				p[circle[now]]+=(F[P[i]]+E[i])/du[circle[now]];
				num[circle[now]]++;
			}
		}
		for(int now=0;now<circle.size();now++){
			p[circle[now]]+=(calc_pre(circle[now],circle[now])+calc_nxt(circle[now],circle[now]))/du[circle[now]];
		}
		for(int now=0;now<circle.size();now++){
			for(int i=H[circle[now]];i;i=X[i]){
				if(oncircle[P[i]]) continue;
				fa[P[i]]=circle[now];
				treedp2(P[i],E[i]);
			}
		}
		double ans=0;
		for(int i=1;i<=n;i++){
			ans+=p[i];
		}
		printf("%.5f\n",ans/n);
	}
	return 0;
}
