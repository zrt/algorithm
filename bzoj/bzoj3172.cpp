#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
char s[2000005];
int L[250];
int c[2000005];
int t[2000005],t2[2000005];
int sa[2000005];
int rank[2000005];
int pos[250];
int height[2000005];
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
		swap(x,y);x[sa[0]]=0;p=1;
		for(int i=1;i<n;i++){
			x[sa[i]]=y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k]?p-1:p++;
		}
		if(p>=n) break;
		m=p;
	}
}
void calc(int n){
	for(int i=0;i<=n;i++) rank[sa[i]]=i;
	int k=0;
	for(int i=0;i<n;i++){
		if(k) k--;
		int j=sa[rank[i]-1];
		while(s[i+k]==s[j+k]) k++;
		height[rank[i]]=k;
	}
}
int main(){
	scanf("%d",&n);
	int now=0;
	for(int i=0;i<n;i++){
		scanf("%s",s+now);
		pos[i]=now;
		L[i]=strlen(s+now);
		now+=L[i];
		s[now++]='#';
	}
	mk_sa(now+1,128);
	calc(now);
	for(int i=0;i<n;i++){
		int l=rank[pos[i]],r=rank[pos[i]];
		while(height[l]>=L[i]) l--;
		while(height[r+1]>=L[i]) r++;
		printf("%d\n",r-l+1);
	}
	return 0;
}
