#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m;
const int MAXN=50005*4;
int a[MAXN];
int s[MAXN];
int to[MAXN],cc;
int c[MAXN],sa[MAXN],height[MAXN],t[MAXN],t2[MAXN],rank[MAXN];
int mn[MAXN][21];
int ans;
void mk_sa(int n,int m){
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
		for(int i=1;i<m;i++) c[i]+=c[i-1];
		for(int i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
		swap(x,y);
		p=1;x[sa[0]]=0;
		for(int i=1;i<n;i++){
			x[sa[i]]=y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k]?p-1:p++;
		}
		if(p>=n) break;
		m=p;
	}
}
void mk_height(int n){
	for(int i=0;i<=n;i++) rank[sa[i]]=i;
	int k=0;
	for(int i=0;i<n;i++){
		if(k) k--;
		int j=sa[rank[i]-1];
		while(s[i+k]==s[j+k]) k++;
		height[rank[i]]=k;
	}
}
void mk_rmq(){
	for(int i=0;i<=n;i++) mn[i][0]=height[i];
	for(int j=1;j<=19;j++){
		for(int i=0;i+(1<<j)-1<=n;i++){
			mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
		}
	}
}
int ask(int l,int r){
	//printf("%d %d\n",l,r);
	if(l>r) swap(l,r);
	l++;
	int L=r-l+1;
	int j=log2(L);
	return min(mn[l][j],mn[r-(1<<j)+1][j]);
}
void solve(int x){
	for(int i=0;i<n/2;i+=x){
		int p=i+m+x;
		if(p>=n/2) break;
		int R=ask(rank[i],rank[p]);
		int L=ask(rank[n/2+n/2-i],rank[n/2+n/2-p]);
		//printf("# %d %d %d %d %d\n",x,i,p,L,R);
		R=min(R,x);
		L=min(L,x);
		if(R+L-1>=x){
			ans+=R+L-x;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n-1;i++) s[i]=a[i+1]-a[i],to[i+1]=s[i];
	n--;
	sort(to+1,to+n+1);
	cc=unique(to+1,to+n+1)-(to+1);
	for(int i=0;i<n;i++) s[i]=lower_bound(to+1,to+cc+1,s[i])-to;
	cc++;
	s[n]=cc;
	for(int i=0;i<n;i++) s[n+i+1]=s[n-i-1];
	n=2*n+1;
	//for(int i=0;i<n;i++) printf("%d ",s[i]);
	//puts("");
	mk_sa(n+1,cc+1);
	mk_height(n);
	mk_rmq();
	for(int i=1;i<=n/2;i++){
		solve(i);
	}
	printf("%d\n",ans);
	return 0;
}
