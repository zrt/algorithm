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
const int MAXN = 120000;
int ls[MAXN*20],rs[MAXN*20],sum[MAXN*20];
int root[MAXN],tot;
void build(int l,int r,int &rt){
	rt=++tot;
	sum[rt]=0;
	if(l==r) return;
	int m=(l+r)>>1;
	build(l,m,ls[rt]);
	build(m+1,r,rs[rt]);
}
void update(int last,int p,int l,int r,int &rt,int v){
	rt=++tot;
	ls[rt]=ls[last];rs[rt]=rs[last];sum[rt]=sum[last]+v;
	if(l==r) return;
	int m=(l+r)>>1;
	if(p<=m) update(ls[last],p,l,m,ls[rt],v);
	else update(rs[last],p,m+1,r,rs[rt],v);
}
int cc,n,m;
int num[MAXN];
char op[10010][3];
const int NN = 10010;
int san[NN*2],P[NN],Q[NN],K[NN];
int L[30],R[30];
int N,M;
int query(int l,int r,int k){
	if(l==r) return l;
	int m=(l+r)>>1;
	int suma=0,sumb=0;
	for(int i=1;i<=N;i++) suma+=sum[ls[L[i]]];
	for(int i=1;i<=M;i++) sumb+=sum[ls[R[i]]];
	int del=sumb-suma;
	if(k<=del){
		for(int i=1;i<=N;i++) L[i]=ls[L[i]];
		for(int i=1;i<=M;i++) R[i]=ls[R[i]];
		return query(l,m,k);
	}else{
		for(int i=1;i<=N;i++) L[i]=rs[L[i]];
		for(int i=1;i<=M;i++) R[i]=rs[R[i]];
		return query(m+1,r,k-del);
	}
}
int ask(int l,int r,int k){
	N=0,M=0;
	for(;l>0;l-=l&-l) L[++N]=root[l];
	for(;r>0;r-=r&-r) R[++M]=root[r];
	return query(1,cc,k);
}
void Bit_update(int x,int val,int flag){
	for(;x<=n;x+=x&-x){
		update(root[x],val,1,cc,root[x],flag);
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
		san[++cc]=num[i];
	}
	for(int i=1;i<=m;i++){
		scanf("%s%d%d",op[i],&P[i],&Q[i]);
		if(op[i][0]=='Q') scanf("%d",&K[i]);
		else san[++cc]=Q[i];
	}
	sort(san+1,san+1+cc);
	cc=unique(san+1,san+1+cc)-(san+1);
	for(int i=1;i<=n;i++) num[i]=lower_bound(san+1,san+1+cc,num[i])-san;
	build(1,cc,root[0]);
	for(int i=1;i<=n;i++) Bit_update(i,num[i],1);
	for(int i=1;i<=m;i++){
		if(op[i][0]=='Q'){
			int id=ask(P[i]-1,Q[i],K[i]);
			printf("%d\n",san[id]);
		}else{
			int pos=lower_bound(san+1,san+1+cc,Q[i])-san;
			Bit_update(P[i],num[P[i]],-1);
			num[P[i]]=pos;
			Bit_update(P[i],num[P[i]],1);
		}
	}
	
	return 0;
}
