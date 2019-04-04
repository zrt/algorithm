#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005*2;
char s[MAXN];
int n;
int sa[MAXN],c[MAXN],t[MAXN],height[MAXN],rank[MAXN],t2[MAXN];
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
struct N{
	int x,pos;
	N(int a=0,int b=0){
		x=a,pos=b;
	}
};
N stk[MAXN];
int top;
typedef long long LL;
LL ans;
LL sum;
int main(){
	scanf("%s",s);
	n=strlen(s);
	mk_sa(n+1,128);
	mk_height(n);
	stk[top++]=N(0,0);
	for(int i=1;i<=n;i++){
		while(stk[top-1].x>height[i]){
			sum-=stk[top-1].x*1LL*(stk[top-1].pos-stk[top-2].pos);
			top--;
		}
		stk[top++]=N(height[i],i);
		sum+=stk[top-1].x*1LL*(stk[top-1].pos-stk[top-2].pos);
		ans+=sum;
	}
	printf("%lld\n",n*1LL*(n-1)*(n+1)/2-2*ans);
	return 0;
}
