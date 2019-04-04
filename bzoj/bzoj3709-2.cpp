#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
long long z;
struct N{
	int d,a,id;
}a[100006],b[100006];
int t1,t2;
// a d-a >=0
// b d-a <0
bool cmp1(N a,N b){
	return a.d<b.d;
}
bool cmp2(N a,N b){
	return a.a>b.a;
}
int main(){
	scanf("%d%lld",&n,&z);
	for(int i=0,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		if(y-x>=0){
			t1++;
			a[t1].d=x;
			a[t1].a=y;
			a[t1].id=i+1;
		}else{
			t2++;
			b[t2].d=x;
			b[t2].a=y;
			b[t2].id=i+1;
		}
	}
	
	sort(a+1,a+t1+1,cmp1);
	sort(b+1,b+t2+1,cmp2);
	int flag=0;
	for(int i=1;i<=t1;i++){
		if(z>a[i].d){
			z-=a[i].d;
			z+=a[i].a;
		}else{
			flag=1;
		}
	}
	for(int i=1;i<=t2;i++){
		if(z>b[i].d){
			z-=b[i].d;
			z+=b[i].a;
		}else{
			flag=1;
		}
	}
	if(!flag) puts("TAK");
	else puts("NIE");
	if(!flag){
		for(int i=1;i<=t1;i++) printf("%d ",a[i].id);
		for(int i=1;i<=t2;i++) printf("%d ",b[i].id);
	}
	
	
	return 0;
}
