#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
#define int LL
int n,q;
const int MAXN=100005*2;
char s[MAXN];
int sa[MAXN],rank[MAXN],height[MAXN],c[MAXN],t[MAXN],t2[MAXN],cnt[MAXN];
int sa2[MAXN],height2[MAXN],rank2[MAXN];
int mn[MAXN][20],mn2[MAXN][20];
void mk_sa(int*sa,int n,int m){
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
		p=1,x[sa[0]]=0;
		for(int i=1;i<n;i++){
			x[sa[i]]=y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k]?p-1:p++;
		}
		if(p>=n) break;
		m=p;
	}
}
void mk_height(int*height,int*rank,int*sa,int n){
	for(int i=0;i<=n;i++) rank[sa[i]]=i;
	int k=0;
	for(int i=0;i<n;i++){
		if(k) k--;
		int j=sa[rank[i]-1];
		while(s[i+k]==s[j+k]) k++;
		height[rank[i]]=k;
	}
}
void find(int k,int&l,int&r){
	int p=lower_bound(cnt,cnt+n+1,k)-cnt;
	if(p==n+1){
		l=r=-1;return;
	}
	l=sa[p];r=sa[p]+k-cnt[p-1]+height[p]-1;
}
void mk_rmq(int mn[][20],int*height){
	for(int i=0;i<=n;i++) mn[i][0]=height[i];
	for(int j=1;j<20;j++){
		for(int i=0;i+(1<<j)-1<=n;i++){
			mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
		}
	}
}
int rmq(int mn[][20],int l,int r){
	if(l>r) swap(l,r);
	if(l==r) return n;
	l++;
	int L=r-l+1;
	int j=log2(L);
	return min(mn[l][j],mn[r-(1<<j)+1][j]);
}
LL ask(int l1,int r1,int l2,int r2){
	//printf("ASK %d %d %d %d\n",l1,r1,l2,r2);
	LL a=rmq(mn,rank[l1],rank[l2]);
	a=min(a,min(r1-l1+1LL,r2-l2+1LL));
	LL b=rmq(mn2,rank2[n-r1-1],rank2[n-r2-1]);
	b=min(b,min(r1-l1+1LL,r2-l2+1LL));
	//printf("## %lld %lld\n",a,b);
	return a*a+b*b;
}
#undef int
int main(){
	#define int LL
	scanf("%lld%lld%s",&n,&q,s);
	mk_sa(sa,n+1,128);
	mk_height(height,rank,sa,n);
	for(int i=1;i<=n;i++) cnt[i]=cnt[i-1]+(n-sa[i])-height[i];
	reverse(s,s+n);
	mk_sa(sa2,n+1,128);
	mk_height(height2,rank2,sa2,n);
	mk_rmq(mn,height);
	mk_rmq(mn2,height2);
	for(int i=0,x,y;i<q;i++){
		scanf("%lld%lld",&x,&y);
		int lx,rx,ly,ry;
		find(x,lx,rx);
		find(y,ly,ry);
		if(lx==-1||ly==-1){
			puts("-1");
			continue;
		}
		printf("%lld\n",ask(lx,rx,ly,ry));
	}
	
	return 0;
}
