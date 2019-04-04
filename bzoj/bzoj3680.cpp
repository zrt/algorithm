#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
typedef long double ld;
struct Point{
	ld x,y,z;
	void read(){
		double xx,yy,zz;
		scanf("%lf%lf%lf",&xx,&yy,&zz);
		x=xx;y=yy;z=zz;
	}
	
}a[10005],ans,now;
ld Rand(){
	return rand()%1000/1000.0;
}
ld Ans=1e200;
ld sqr(ld a){
	return a*a;
}
ld dis(Point&a,Point&b){
	return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
ld Judge(Point&p){
	ld ret=0;
	for(int i=1;i<=n;i++) ret+=dis(p,a[i])*a[i].z;
	if(ret<Ans){
		Ans=ret;
		ans=p;
	}
	return ret;
}
void SA(ld T){
	Point New;
	ld last=Judge(now);
	while(T>0.001){
	//	printf("%.3f\n",(double)T);
		New.x=now.x+(Rand()*2-1)*T;
		New.y=now.y+(Rand()*2-1)*T;
		ld kk=Judge(New);
		ld DE=last-kk;
		if(DE>0){
			last=kk;
			now=New;
		}else if(Rand()<exp(DE/T)){
			last=kk;
			now=New;
		}
		T*=0.99;
	}
	for(int i=0;i<=1000;i++){
		New.x=ans.x+(Rand()*2-1)*T;
		New.y=ans.y+(Rand()*2-1)*T;
		Judge(New);
	}
}
int main(){
	srand(401794301);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) a[i].read(),now.x+=a[i].x,now.y+=a[i].y;
	now.x/=n,now.y/=n;
	SA(1000000);
	printf("%.3f %.3f\n",(double)ans.x,(double)ans.y);
	return 0;
}
