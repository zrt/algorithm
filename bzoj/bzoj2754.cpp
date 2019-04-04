#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
const int MAXN=320005*2;
int s[MAXN],len,rank[MAXN],height[MAXN],c[MAXN],t[MAXN],t2[MAXN];
int pos[MAXN],pos2[MAXN],asklen[MAXN],sa[MAXN];
int II=10001;
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
int ans[20005];
int vis[20005];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		while(x--){
			pos[len]=i;
			scanf("%d",&s[len]);len++;
		}
		s[len++]=++II;
		scanf("%d",&x);
		while(x--){
			pos[len]=i;
			scanf("%d",&s[len]);len++;
		}
		s[len++]=++II;
	}
	for(int i=1,x;i<=m;i++){
		scanf("%d",&x);
		pos2[i]=len;asklen[i]=x;
		while(x--){
			scanf("%d",&s[len]);len++;
		}
		s[len++]=++II;
	}
	mk_sa(len+1,II+1);
	mk_height(len);
	for(int i=1;i<=m;i++){
		int l=rank[pos2[i]],r=rank[pos2[i]];
		int num=0;
		while(l>=0&&height[l]>=asklen[i]) l--;
		while(r<len&&height[r+1]>=asklen[i]) r++;
		int ppp=i;
		for(int i=l;i<=r;i++){
			if(pos[sa[i]]){
				if(vis[pos[sa[i]]]!=ppp){
					vis[pos[sa[i]]]=ppp;
					num++;
					ans[pos[sa[i]]]++;
				}
			}
		}
		printf("%d\n",num);
	}
	for(int i=1;i<n;i++) printf("%d ",ans[i]);
	printf("%d\n",ans[n]);
	return 0;
}
