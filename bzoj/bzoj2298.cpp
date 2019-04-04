#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct N{
	int l,r,c;
	friend bool operator < (N a,N b){
		if(a.r!=b.r) return a.r<b.r;
		return a.l<b.l;
	}
}a[100005];
int n,ans,tot;
int mn[100005];
int main(){
	scanf("%d",&n);
	for(int i=0,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		if(x+y>=n){
			ans++;
			continue;
		}
		a[tot].l=x+1;
		a[tot].r=n-y;
		a[tot].c=1;
		tot++;
	}
	sort(a,a+tot);
	int k=0;
	for(int i=1;i<tot;i++){
		if(a[i].l==a[k].l&&a[i].r==a[k].r) a[k].c++;
		else{
			a[++k]=a[i];
		}
	}
	tot=k+1;
	for(int i=0;i<tot;i++) a[i].c=min(a[i].c,a[i].r-a[i].l+1);
	int j=0;
	for(int i=1;i<=n;i++){
		mn[i]=mn[i-1];
		while(j<tot&&a[j].r==i){
			mn[i]=max(mn[i],mn[a[j].l-1]+a[j].c);
			j++;
		}
	}
	printf("%d\n",n-mn[n]);
	return 0;
}
