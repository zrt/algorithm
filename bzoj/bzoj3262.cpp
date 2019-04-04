#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k;
int tot;
struct N{
	int a,b,c,num,tot;
}a[100005];
bool cmp(const N&a,const N&b){
	if(a.a!=b.a)return a.a>b.a;
	if(a.b!=b.b) return a.b>b.b;
	return a.c>b.c;
}
bool cmp2(const N&a,const N&b){
	return a.b<b.b;
}
int num[100005];
int c[200005];
#define lowbit(x) ((x)&-(x))
void add(int pos,int d){
	while(pos<=k){
		c[pos]+=d;
		pos+=lowbit(pos);
	}
}
int ask(int pos){
	int ret=0;
	while(pos>0){
		ret+=c[pos];
		pos-=lowbit(pos);
	}
	return ret;
}
void solve(int l,int r){
	if(l==r) return ;
	int mid=(l+r)/2;
	solve(l,mid);solve(mid+1,r);
	sort(a+l,a+mid+1,cmp2);
	sort(a+mid+1,a+r+1,cmp2);
	int i=l,j=mid+1;
//	memset(c,0,sizeof c);
	while(i<=mid){
		while(j<=r){
			if(a[j].b<=a[i].b){
				add(a[j].c,a[j].tot);
				j++;
			}else break;
		}
		a[i].num+=ask(a[i].c);
		i++;
	}
	for(int i=mid+1;i<j;i++) add(a[i].c,-a[i].tot);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
	}
	sort(a+1,a+n+1,cmp);
	tot=1;
	a[tot].tot=1;
	for(int i=2;i<=n;i++){
		if(a[i].a==a[tot].a&&a[i].b==a[tot].b&&a[i].c==a[tot].c){
			a[tot].tot++;
		}else{
			tot++;
			a[tot].a=a[i].a;
			a[tot].b=a[i].b;
			a[tot].c=a[i].c;
			a[tot].tot=1;
		}
	}
	int nn=n;
	n=tot;
	solve(1,n);
	for(int i=1;i<=n;i++){
		num[a[i].num+a[i].tot-1]+=a[i].tot;
	//	printf("%d %d %d %d \n",a[i].a,a[i].b,a[i].c,a[i].num+a[i].tot-1);
	}
	for(int i=0;i<nn;i++){
		printf("%d\n",num[i]);
	}
//	while(1);
	return 0;
}
