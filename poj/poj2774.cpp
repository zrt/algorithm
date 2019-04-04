#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
const int MAXN=220005;
char s[MAXN];
int c[MAXN],sa[MAXN],height[MAXN],t[MAXN],t2[MAXN],rank[MAXN];
int n;
void mk_sa(int m){
//	memset(t,-1,sizeof t);
//	memset(t2,-1,sizeof t2); 
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
		for(int i=1;i<n;i++) x[sa[i]]=y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k]?p-1:p++;
		if(p>=n) break;
		m=p;
	}
}
char sb[MAXN];
int L;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%s%s",s,sb);
	L=strlen(s);
	s[L]='$';
	for(int i=0;sb[i];i++){
		s[i+L+1]=sb[i];
	}
	n=strlen(sb)+L+1;
	s[n]='\0';
	mk_sa(128);
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
	for(int i=1;i<n;i++){
		if((sa[i]>L&&sa[i-1]<L)||(sa[i]<L&&sa[i-1]>L)){
			ans=max(ans,height[i]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
