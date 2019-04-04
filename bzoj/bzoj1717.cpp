#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int n,K;
const int MAXN=20005;
int s[MAXN];
int sa[MAXN],t[MAXN],t2[MAXN],c[MAXN],rank[MAXN],height[MAXN];
void build_sa(int m){
	memset(t,-1,sizeof t);
	memset(t2,-1,sizeof t2); 
	int *x=t,*y=t2;
	for(int i=0;i<m;i++) c[i]=0;
	for(int i=0;i<n;i++) c[x[i]=s[i]]++;
	for(int i=1;i<m;i++) c[i]+=c[i-1];
	for(int i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
	for(int k=1;k<=n;k<<=1){
		int p=0;
		for(int i=n-k;i<n;i++) y[p++]=i;
		for(int i=0;i<n;i++) if(sa[i]>=k) y[p++]=sa[i]-k;
		for(int i=0;i<m;i++) c[i]=0;
		for(int i=0;i<n;i++) c[x[y[i]]]++;
		for(int i=0;i<m;i++) c[i]+=c[i-1];
		for(int i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
		
		swap(x,y);
		p=1;x[sa[0]]=0;
		for(int i=1;i<n;i++){
			x[sa[i]]= y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;
		}
		if(p>=n) break;
		m=p;
	}
}

int tot;
struct N{
	int x,w;
	N(int a=0,int b=0){
		x=a,w=b;
	}
};
struct dddl{
	N q[MAXN];
	int h,t;
	void insert(N a){
		while(h!=t&&q[t-1].w>=a.w) t--;
		q[t++]=a;
	}
	void pop(int pos){
		if(q[h].x==pos) h++;
	}
	int ask(){
		return q[h].w;
	}
}dddl;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&K);
	for(int i=0;i<n;i++){
		scanf("%d",&s[i]);
		c[i+1]=s[i];
	}
	sort(c+1,c+n+1);
	tot=unique(c+1,c+n+1)-(c+1);
	for(int i=0;i<n;i++){
		s[i]=lower_bound(c+1,c+tot+1,s[i])-c;
	}
	s[n]=-1;
	build_sa(tot+1);
	for(int i=0;i<n;i++) rank[sa[i]]=i;
	int k=0;
	for(int i=0;i<n;i++){
		if(k) k--;
		if(!rank[i]) continue;
		int j=sa[rank[i]-1];
		while(s[i+k]==s[j+k]) k++;
		height[rank[i]]=k;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		dddl.insert(N(i,height[i]));
		dddl.pop(i-K+1);
		ans=max(ans,dddl.ask());
	}
	printf("%d\n",ans);
	return 0;
}
