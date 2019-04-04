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
struct N{
	int l,r;
}a[10005];
bool cmp(N a,N b){
	return a.r<b.r;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].l,&a[i].r);
		a[i].r+=a[i].l-1;
	}
	sort(a+1,a+1+n,cmp);
	int pos=0;
	int num=0;
	for(int i=1;i<=n;i++){
		while(i<=n&&a[i].l<=pos) i++;
		if(i>n) break;
		num++;
		pos=a[i].r;
	}
	printf("%d\n",num);
	return 0;
}
