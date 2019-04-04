#include<cstdio>
#include<algorithm>
using namespace std;
struct N{
	int x,y;
	friend bool operator < (N a,N b){
		return a.x<b.x;
	}
}a[10005];
int pos;
int n;
int L;
int main(){
	scanf("%d%d",&n,&L);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	sort(a,a+n);
	long long ans=0;
	for(int i=0;i<n;i++){
		if(pos>=a[i].y) continue;
		pos=max(pos,a[i].x);
		while(pos<a[i].y) ans++,pos+=L;
	}
	printf("%d\n",ans);
	return 0;
}
