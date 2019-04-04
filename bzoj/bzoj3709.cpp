#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int n;long long z;
struct N{
	int a,b,id;
}a[100005],b[100005];
int ca,cb;
inline bool cmp(N a,N b){
	return a.a<b.a;
}
inline bool cmp2(N a,N b){
	return a.b>b.b;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%lld",&n,&z);
	for(int i=1,x,y;i<=n;i++){
		scanf("%d%d",&x,&y);
		if(x<y){
			a[ca].a=x;a[ca].b=y;a[ca].id=i;
			ca++;
		}else{
			b[cb].a=x;b[cb].b=y;b[cb].id=i;
			cb++;
		}
	}
	sort(a,a+ca,cmp);
	sort(b,b+cb,cmp2);
	bool ok=1;
	for(int i=0;i<ca;i++){
		if(z<=a[i].a){
			ok=0;break;
		}else{
			z+=a[i].b-a[i].a;
		}
	}
	if(ok)
	for(int i=0;i<cb;i++){
		if(z<=b[i].a){
			ok=0;break;
		}else{
			z+=b[i].b-b[i].a;
		}
	}
	if(ok){
		puts("TAK");
		for(int i=0;i<ca;i++){
			printf("%d ",a[i].id);
		}
		for(int i=0;i<cb;i++){
			printf("%d ",b[i].id);
		}
	}else{
		puts("NIE");
	}
	return 0;
}
