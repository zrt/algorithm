#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long LL;

int n,m,q;

int p[200005];
int inv[200005];
int a[200005];
int last[200005];
int nxt[200005][25];
int len[200005];
int mn[200005][25];
inline int lowbit(int x){
	return x&-x;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	// 0~n
	for(int i=0;i<n;i++) scanf("%d",&p[i]),inv[p[i]]=i;
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	for(int i=m;i>=1;i--){
		last[a[i]] = i;
		nxt[i][0] = last[p[(inv[a[i]]+1)%n]];
	}
	for(int i=1;(1<<i)<=n;i++){
		for(int j=1;j<=m;j++){
			nxt[j][i] = nxt[nxt[j][i-1]][i-1];
		}
	}
	int t = n-1;
	for(int i=1;i<=m;i++){
		len[i] = i;
		for(int j=0;j<=20;j++){
			if(t>>j&1){
				len[i] = nxt[len[i]][j];
			}
		}
	}
	for(int i=1;i<=m;i++){
		mn[i][0] = len[i];
		if(mn[i][0] == 0) mn[i][0] = m+1;
	}
	for(int j=1;j<=20;j++){
		for(int i=1;i<=m;i++)
			if(i+(1<<(j-1)) <= m)
				mn[i][j] = min(mn[i][j-1], mn[i+(1<<(j-1))][j-1]);
	}
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		int ans = mn[l][0];
		int p = l;
		int t = r-l+1;
		for(int i=0;i<=20;i++){
			if(t>>i&1){
				ans = min(ans,mn[p][i]);
				p+=(1<<i);
			}
		}
		// printf("\n# %d\n",ans);
		if(ans<=r){
			putchar('1');
		}else{
			putchar('0');
		}
	}
	puts("");

	







	


	return 0;
}
