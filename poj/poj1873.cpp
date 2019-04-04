#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iostream>
int n;
using namespace std;
struct point{
	int x,y,w,l;
	point(int x=0,int y=0){
		this->x=x;this->y=y;
	}
	friend point operator - (point a,point b){
		return point(a.x-b.x,a.y-b.y);
	}
}a[15];
point b[15];int tot;
bool cmp(point a,point b){
	if(a.y!=b.y) return a.y<b.y;
	return a.x<b.x;
}
int stk[21],top;
int cross(point a,point b){
	return a.x*b.y-b.x*a.y;
}
double dis(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int minnum,minans,sta;
double now;
int k;
int main(){
	#ifdef LOCAL
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int kase(0);
	while(scanf("%d",&n),n){
		for(int i=0;i<n;i++){
			scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].w,&a[i].l);
		}
		minans=1<<30;
		minnum=1<<30;
		double anss;
		for(int chose=1;chose<1<<n;chose++){
		//	printf("%d\n",chose);
			tot=0;int sum=0,c=0;
		//	int ans=0;
			int num=0;
	//		cout<<"minans "<<minans<<endl;
			for(int i=0;i<n;i++) if(!(chose&(1<<i))) b[tot++]=a[i];else num++,sum+=a[i].l,c+=a[i].w;
			if(c>minans) continue;
		//	puts("HAHAHAHAHAHAHAHAHA");
	//		printf("n: %d tot: %d\n",n,tot);
	//		printf("Tot %d\n",n-tot);
			if(n-num<2) {
				now=0;
				goto door;
			}
		//	puts("HAHAHAHAHAHAHAHAHA");
		//	if(tot<3) continue;
			sort(b,b+tot,cmp);
			top=0;
			for(int i=0;i<tot;i++){
				while(top>1&&cross( b[stk[top-1]]-b[stk[top-2]] , b[i]-b[stk[top-1]] )<=0) top--;
				stk[top++]=i;
			}
			k=top;
			for(int i=tot-1;i>=0;i--){
				while(top>k&&cross( b[stk[top-1]]-b[stk[top-2]] , b[i]-b[stk[top-1]] )<=0) top--;
				stk[top++]=i;
			}
			top--;
			now=0;
			for(int i=0;i<top;i++){
				now+=dis(b[stk[i]],b[stk[i+1]]);
			}
			door:
		//	cout<<now<<' '<<sum<<endl;
			if(now<=(double) sum){
				if(c<minans){
					minans=c;
					minnum=num;
					sta=chose;
					anss=sum-now;
				}else if(minnum>num){
					minnum=num;
					sta=chose;
					anss=sum-now;
				}
			}
		}
		printf("Forest %d\nCut these trees:",++kase);
		for(int i=0;i<n;i++) if(sta&(1<<i)) printf(" %d",1+i);
		printf("\nExtra wood: %.2f\n\n",anss);
	}
	return 0;
}