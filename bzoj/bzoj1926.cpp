#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,q;
int a[500005];
int rt[500005];
int sum[500005*28];
int ls[500005*28],rs[500005*28],num[500005*28];
int cc;
int getnew(){
	return ++cc;
}
int insert(int o,int l,int r,int pos){
	int p=getnew();
	sum[p]=sum[o]+pos;
	num[p]=num[o]+1;
	if(l==r) return p;
	int mid=(l+r)>>1;
	if(pos<=mid) ls[p]=insert(ls[o],l,mid,pos),rs[p]=rs[o];
	else rs[p]=insert(rs[o],mid+1,r,pos),ls[p]=ls[o];
	return p;
}
int ask(int o1,int o2,int l,int r,int h){
	if(l==r){
		return (h-1)/l+1;
	}else{
		int mid=(l+r)>>1;
		int sumr=sum[rs[o1]]-sum[rs[o2]];
		if(sumr>=h){
			return ask(rs[o1],rs[o2],mid+1,r,h);
		}else{
			return num[rs[o1]]-num[rs[o2]]+ask(ls[o1],ls[o2],l,mid,h-sumr);
		}
	}
}
void solve1(){
	for(int i=1;i<=m;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) rt[i]=insert(rt[i-1],1,1000,a[i]),a[i]+=a[i-1];
	while(q--){
		int x1,y1,x2,y2,h;
		scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&h);
		if(a[y2]-a[y1-1]<h){
			puts("Poor QLW");
			continue;
		}
		printf("%d\n",ask(rt[y2],rt[y1-1],1,1000,h));
	}
}
int d[205][205];
int f[205][205][1005];
int g[205][205][1005];
int Sum(int f[205][205][1005],int x1,int y1,int x2,int y2,int k){
	return f[x2][y2][k]-f[x1-1][y2][k]-f[x2][y1-1][k]+f[x1-1][y1-1][k];
}
void solve2(){
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&d[i][j]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=1000;k>=0;k--){
				f[i][j][k]=f[i-1][j][k]+f[i][j-1][k]-f[i-1][j-1][k]+(d[i][j]>=k?d[i][j]:0);
				g[i][j][k]=g[i-1][j][k]+g[i][j-1][k]-g[i-1][j-1][k]+(d[i][j]>=k);
			}
		}
	}
	for(int i=0;i<q;i++){
		int x1,x2,y1,y2,h;
		scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&h);
		if(Sum(f,x1,y1,x2,y2,0)<h){
			puts("Poor QLW");
		//	printf("%d\n",f[x2][y2][0]);
		//	printf("# %d %d\n",Sum(f,x1,y1,x2,y2,0),h);
			continue;
		}
		int l=-1,r=1001;
		while(r-l>1){
			int mid=(l+r)>>1;
			if(Sum(f,x1,y1,x2,y2,mid)>=h) l=mid;
			else r=mid;
		}
		int R=h-Sum(f,x1,y1,x2,y2,r);
		printf("%d\n",Sum(g,x1,y1,x2,y2,r)+(R-1)/l+1);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	if(n==1){
		solve1();
	}else{
		solve2();
	}
	return 0;
}
