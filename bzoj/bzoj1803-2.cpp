#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int w[100005],H[100005],X[200005],P[200005],tot,to[100005],l[100005],r[100005],root[100005];
int sum[100005*50],ls[100005*50],rs[100005*50];
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int n,cc,m;
int tim;
int add(int o,int l,int r,int pos){
	int p=++cc;
	sum[p]=sum[o]+1;
	if(l==r){
		return p;
	}else{
		int mid=(l+r)>>1;
		if(pos<=mid){
			ls[p]=add(ls[o],l,mid,pos);
			rs[p]=rs[o];
		}else{
			ls[p]=ls[o];
			rs[p]=add(rs[o],mid+1,r,pos);
		}
	}
	return p;
}
void dfs(int x,int fa){
	l[x]=++tim;
	root[tim]=add(root[tim-1],1,n,w[x]);
	for(int i=H[x];i;i=X[i]){
		if(P[i]==fa) continue;
		dfs(P[i],x);
	}
	r[x]=tim;
}
int ask(int o1,int o2,int l,int r,int k){
	if(l==r){
		return l;
	}else{
		int mid=(l+r)>>1;
		int tmp=sum[ls[o1]]-sum[ls[o2]];
		if(tmp>=k){
			return ask(ls[o1],ls[o2],l,mid,k);
		}else return ask(rs[o1],rs[o2],mid+1,r,k-tmp);
	}
}
int getint(){
	static char c;
	static int x;
	while(c=getchar(),c<'0'||c>'9');
	x=c-'0';
	while(c=getchar(),c>='0'&&c<='9') x=x*10+c-'0';
	return x;
}
int main(){
	n=getint();
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
		to[i]=w[i];
	}
	sort(to+1,to+n+1);
	for(int i=1;i<=n;i++) w[i]=lower_bound(to+1,to+n+1,w[i])-to;
	for(int i=1;i<=n;i++) to[w[i]]=i;
	for(int i=1,x,y;i<n;i++){
		x=getint();y=getint();
		add(x,y);add(y,x);
	}
	dfs(1,0);
	m=getint();
	for(int i=0,x,k;i<m;i++){
		x=getint();k=getint();
		printf("%d\n",to[ask(root[r[x]],root[l[x]-1],1,n,k)]);
	}
	return 0;
}
