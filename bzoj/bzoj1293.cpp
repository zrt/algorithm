#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int num[65];
struct N{
	int type,pos;
	friend bool operator <(const N&a,const N&b){
		return a.pos<b.pos;
	}
}a[1000005];
int n,k,tot;
bool check(){
	for(int i=0;i<k;i++) if(num[i]==0) return 0;
	return 1;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0,x;i<k;i++){
		scanf("%d",&x);
		for(int j=0,t;j<x;j++){
			scanf("%d",&t);
			a[tot].type=i;
			a[tot++].pos=t;
		}
	}
	sort(a,a+n);
	int p=0;
	int ans=0x7fffffff;
	for(int i=0;i<n;i++){
		while(p<n&&!check()) num[a[p].type]++,p++;
		if(check()){
			ans=min(ans,a[p-1].pos-a[i].pos);
		}
		num[a[i].type]--;
	}
	printf("%d\n",ans);
//	while(1);
	return 0;
}
