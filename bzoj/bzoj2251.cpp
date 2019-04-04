//后缀数组 SA
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=6005;
char s[MAXN];
int rank[MAXN],sa[MAXN],height[MAXN];
int t[MAXN],t2[MAXN];
int c[MAXN];
int n;
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
	for(int i=1;i<=n;i++) rank[sa[i]]=i;//1..n
	int k=0;
	for(int i=0;i<n;i++){
		if(k) k--;
		int j=sa[rank[i]-1];
		while(s[j+k]==s[i+k]) k++;
		height[rank[i]]=k;
	}
}
int main(){
	scanf("%d%s",&n,s);
	mk_sa(n+1,128);
	mk_height(n);
	for(int i=1;i<=n;i++){
		for(int j=height[i]+1;sa[i]+j<=n;j++){
			int l=i,r=i;
			while(l>0&&height[l]>=j) l--;
			while(r<n&&height[r+1]>=j) r++;
			if(r-l+1<=1) continue;
			printf("%d\n",r-l+1);
		}
	}
	return 0;
}
