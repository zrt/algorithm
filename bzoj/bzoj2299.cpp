#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,a,b,x,y,p1,p2,p3;
void exgcd(int a1,int a2,int&p1,int&p2,int&p3){
	if(!a2) p1=1,p2=0,p3=a1;
	else{
		exgcd(a2,a1%a2,p2,p1,p3);p2-=p1*(a1/a2);
	}
}
int calc(int a1,int a2){
	a1-=a2;
	if(a1<0) a1=-a1;
	return a1%2;
}
bool check(){
	if(!a&&!b) return 0;
	p1=0,p2=0,p3=0;
	exgcd(a,b,p1,p2,p3);
	if(x%p3) return 0;
	if(y%p3) return 0;
	if(!a) return 1;
	if(!b) return 1;
	int a1=p1*(x/p3),b1=p2*(x/p3);
	int b2=p1*(y/p3),a2=p2*(y/p3);
	int c1=b/p3,c2=a/p3;
	if(calc(a1,0)==calc(a2,0)&&calc(b1,0)==calc(b2,0)) return 1;
	if(calc(a1,c1)==calc(a2,0)&&calc(b1,c2)==calc(b2,0)) return 1;
	if(calc(a1,0)==calc(a2,c2)&&calc(b1,0)==calc(b2,c1)) return 1;
	if(calc(a1,c1)==calc(a2,c2)&&calc(b1,c2)==calc(b2,c1)) return 1;
	return 0;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&a,&b,&x,&y);
		if(x<0) x=-x;
		if(y<0) y=-y;
		if(a<0) a=-a;
		if(b<0) b=-b;
		int ok=check();
		if(ok) puts("Y");
		else puts("N");
	}
	return 0;
}
