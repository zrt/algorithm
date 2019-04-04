#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
//by zrt
//problem:
using namespace std;
const int MAXN=20005;
int n;
map<int,int> mp;
int a[MAXN];
int s[MAXN];
int cc;
int sa[MAXN],t[MAXN],t2[MAXN],c[MAXN],rank[MAXN],height[MAXN];
void build_sa(int m){
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
			x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;
		}
		if(p>=n) break;
		m=p;
	} 
}
bool judge(int X){
	int p=0;
	while(p<n){
		int minn=sa[p],maxx=sa[p];
		while(p+1<n&&height[p+1]>=X){
			minn=min(minn,sa[p+1]);
			maxx=max(maxx,sa[p+1]);
			p++;
		}
		if(maxx-minn>X) return 1;
		p++;
	}
	return 0;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%d",&n),n){
		mp.clear();cc=0;
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		for(int i=0;i<n-1;i++) s[i]=a[i+1]-a[i];
		for(int i=0;i<n;i++) {
			if(mp.find(s[i])==mp.end()) mp[s[i]]=cc++;
			s[i]=mp[s[i]];
		}
		s[n]=cc;
		build_sa(cc);
		//rank
		for(int i=0;i<n;i++) rank[sa[i]]=i;
		int k=0;
		for(int i=0;i<n;i++){
			if(k) k--;
			int j=sa[rank[i]-1];
			if(rank[i])while(s[i+k]==s[j+k]) k++;
			if(rank[i])height[rank[i]]=k;
		}
		int l=0,r=n+1;
		while(r-l>1){
			int mid=(l+r)>>1;
			if(judge(mid)) l=mid;
			else r=mid;
		}
		if(l>=4)
		printf("%d\n",l+1);
		else puts("0");
	}
	return 0;
}
