#include<cstdio>
#include<cstring>
using namespace std;
int n;
long long ans;
int main(){
	scanf("%d",&n);
	for(int i=0,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		ans-=x;ans+=y;
	}
	for(int i=0,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		ans+=x;ans-=y;
	}
	printf("%lld\n",ans);
//	while(1);
	return 0;
}
