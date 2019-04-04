#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
//by zrt
//problem:
using namespace std;
map<int,int> mp;
const int MAXN=200050;
int s[MAXN];
int n,k;
int sa[MAXN],rank[MAXN],t[MAXN],t2[MAXN],c[MAXN],height[MAXN];
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
	int num=1;
	for(int i=1;i<n;i++){
		if(height[i]>=X) ++num;
		else num=1;
		if(num>=k) return 1;
		
	}
	return 0;
}

int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&s[i]);
	int cc=0;
	for(int i=0;i<n;i++){
		if(mp.find(s[i])==mp.end()) mp[s[i]]=++cc;
		s[i]=mp[s[i]];
	}
	++cc;
	build_sa(cc);
	s[n]=cc;
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
		int m=(l+r)>>1;
		if(judge(m)) l=m;
		else r=m;
	}
	printf("%d\n",l);
	return 0;
}