#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=250000;
char s1[MAXN],s2[MAXN],s3[MAXN],s[MAXN];
int sa[MAXN],belong[MAXN],rank[MAXN],height[MAXN];
int t[MAXN],t2[MAXN],c[MAXN];
int n,l1,l2,l3;
int nxt[MAXN];
int loc[MAXN],cnt;
int f[MAXN];
void mk_sa(int n,int m){
	int*x=t,*y=t2;
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
		for(int i=1;i<n;i++) x[sa[i]]=y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k]?p-1:p++;
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
int main(){
	scanf("%s%s%s",s1,s2,s3);
	l1=strlen(s1),l2=strlen(s2),l3=strlen(s3);
	for(int i=0;i<l1;i++) s[n++]=s1[i];
	s[n++]='#';
	for(int i=0;i<l2;i++) s[n++]=s2[i];
	int j=-1;
	nxt[0]=-1;
	for(int i=1;i<l3;i++){
		while(~j&&s3[j+1]!=s3[i]) j=nxt[j];
		if(s3[j+1]==s3[i]) j++;
		nxt[i]=j;
	}
	j=-1;
	for(int i=0;i<n;i++){
		while(~j&&s3[j+1]!=s[i]) j=nxt[j];
		if(s3[j+1]==s[i]) j++;
		if(j==l3-1){
			loc[++cnt]=i-l3+1;
			j=nxt[j];
		}
	}
	j=1;
	for(int i=0;i<n;i++){
		while(j<=cnt&&loc[j]<i) j++;
		if(j>cnt){
			f[i]=n-i;
		}else{
			f[i]=loc[j]+l3-i-1;
		}
	}
	mk_sa(n+1,128);
	mk_height(n);
	int tmp=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		tmp=min(tmp,height[i]);
		if(sa[i]<l1){
			tmp=max(tmp,f[sa[i]]);
		}else if(sa[i]>l1){
			ans=max(ans,min(tmp,f[sa[i]]));
		//	printf("# %d %d\n",ans,sa[i]);
		}
	}
	tmp=0;
	for(int i=n;i>=1;i--){
		if(sa[i]<l1){
			tmp=max(tmp,f[sa[i]]);
		}else if(sa[i]>l1){
			ans=max(ans,min(tmp,f[sa[i]]));
		//	printf("# %d %d\n",ans,sa[i]);
		}
		tmp=min(tmp,height[i]);
	}
	printf("%d\n",ans);
	return 0;
}
