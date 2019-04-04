#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,m;
vector<int> has[300005];
int p[300005];
typedef long long LL;
LL c[300005];
int k,T;
int l[300005],r[300005], a[300005];
int ans[300005];
int id[300005];
bool mark[300005];
int tmp[300005];
#define lowbit(x) ((x)&-(x))
void add(int x,int k){
	while(x<=m){
		c[x]+=k;
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
void Add(int x,int f){
	if(l[x]<=r[x]){
		add(l[x],f*a[x]);
		add(r[x]+1,-f*a[x]);
	}else{
		add(l[x],f*a[x]);
		add(1,f*a[x]);
		add(r[x]+1,-f*a[x]);
	}
}
void solve(int l,int r,int L,int R){
	if(L>R) return;
	if(l==r){
		for(int i=L;i<=R;i++){
			ans[id[i]]=l;
		}
	}else{
		int mid=(l+r)>>1;
		while(T<mid) T++,Add(T,1);
		while(T>mid) Add(T,-1),T--;
		for(int i=L;i<=R;i++){
			LL tmp=0;
			for(int j=0;j<has[id[i]].size();j++){
				tmp+=ask(has[id[i]][j]);
				if(tmp>=p[id[i]]) {
					mark[id[i]]=1;break;
				}
				
			}
		}
		int cc=0,tot=0;
		for(int i=L;i<=R;i++){
			if(mark[id[i]]){
				id[L+cc]=id[i];
				cc++;
			}else{
				tmp[tot++]=id[i];
			}
		}
		for(int i=L;i<L+cc;i++) mark[id[i]]=0;
		for(int i=0;i<tot;i++) id[L+cc+i]=tmp[i];
		solve(l,mid,L,L+cc-1),solve(mid+1,r,L+cc,R);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=m;i++) scanf("%d",&x),has[x].push_back(i);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		scanf("%d%d%d",&l[i],&r[i],&a[i]);
	}
	k++;
	l[k]=1,r[k]=m,a[k]=0x3fffffff;
	for(int i=1;i<=n;i++) id[i]=i;
	solve(1,k,1,n);
	for(int i=1;i<=n;i++){
		if(ans[i]==k) puts("NIE");
		else printf("%d\n",ans[i]);
	}
	return 0;
}
