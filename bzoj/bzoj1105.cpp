#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
struct N{
	int x,y,m;
}a[1000005];
int mnx,mny,mxx,mxy;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].m);
	mnx=mny=1000000000;
	mxx=mxy=0;
	for(int i=1;i<=n;i++){
		if(a[i].x<a[i].y){
			mnx=min(mnx,a[i].x);
			mxx=max(mxx,a[i].x);
			mny=min(mny,a[i].y);
			mxy=max(mxy,a[i].y);
		}else{
			mnx=min(mnx,a[i].y);
			mxx=max(mxx,a[i].y);
			mny=min(mny,a[i].x);
			mxy=max(mxy,a[i].x);
		}
	}
	printf("%lld ",2LL*(mxy-mny)+2LL*(mxx-mnx));
	int sum1=0;
	for(int i=1;i<=n;i++){
		if(a[i].x>=mnx&&a[i].x<=mxx&&a[i].y>=mny&&a[i].y<=mxy) continue;
		else if(a[i].y>=mnx&&a[i].y<=mxx&&a[i].x>=mny&&a[i].x<=mxy) sum1+=a[i].m;
		else{
			sum1=0x7fffffff;break;
		}
	}
	swap(mxx,mxy);
	int sum2=0;
	for(int i=1;i<=n;i++){
		if(a[i].x>=mnx&&a[i].x<=mxx&&a[i].y>=mny&&a[i].y<=mxy) continue;
		else if(a[i].y>=mnx&&a[i].y<=mxx&&a[i].x>=mny&&a[i].x<=mxy) sum2+=a[i].m;
		else{
			sum2=0x7fffffff;break;
		}
	}
	swap(mnx,mny);
	int sum3=0;
	for(int i=1;i<=n;i++){
		if(a[i].x>=mnx&&a[i].x<=mxx&&a[i].y>=mny&&a[i].y<=mxy) continue;
		else if(a[i].y>=mnx&&a[i].y<=mxx&&a[i].x>=mny&&a[i].x<=mxy) sum3+=a[i].m;
		else{
			sum3=0x7fffffff;break;
		}
	}
	swap(mxx,mxy);
	int sum4=0;
	for(int i=1;i<=n;i++){
		if(a[i].x>=mnx&&a[i].x<=mxx&&a[i].y>=mny&&a[i].y<=mxy) continue;
		else if(a[i].y>=mnx&&a[i].y<=mxx&&a[i].x>=mny&&a[i].x<=mxy) sum4+=a[i].m;
		else{
			sum4=0x7fffffff;break;
		}
	}
	swap(mnx,mny);
	int mnn=min(min(sum1,sum2),min(sum3,sum4));
	if(sum1==mnn){
		;
	}else if(sum2==mnn){
		swap(mxx,mxy);
	}else if(sum3==mnn){
		swap(mxx,mxy);swap(mnx,mny);
	}else{
		swap(mnx,mny);
	}
	printf("%d\n",mnn);
	for(int i=1;i<=n;i++){
		if(a[i].x>=mnx&&a[i].x<=mxx&&a[i].y>=mny&&a[i].y<=mxy) putchar('0');
		else putchar('1');
	}
	puts("");
	return 0;
}
