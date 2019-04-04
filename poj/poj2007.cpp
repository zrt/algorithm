#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
struct point{
	int x,y;
}p[55];
bool cmp(point a,point b){
	return (a.x-p[0].x)*(b.y-p[0].y)-(b.x-p[0].x)*(a.y-p[0].y)>0;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&p[0].x,&p[0].y);
	int tot=1;
	while(~scanf("%d%d",&p[tot].x,&p[tot].y)) tot++;
	sort(p+1,p+tot,cmp);
	for(int i=0;i<tot;i++){
		printf("(%d,%d)\n",p[i].x,p[i].y);
	}
	return 0;
}
