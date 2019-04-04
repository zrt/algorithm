/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<complex>
//by zrt
//problem:
using namespace std;
typedef long long ll;
typedef complex<double> Point;
typedef Point Vector;
int n,m;double x,y,xx,yy,tmpa,tmpb;
double Dot(Vector A,Vector B){
	return real(conj(A)*B);
}
double Cross(Vector A,Vector B){
	return imag(conj(A)*B);
}
struct K{
	Point a,b;
};
K L[5005];
int num[5005];
Point now;
const double eps=1e-10;
int dcmp(double x){
	if(fabs(x)<eps) return 0;
	else if(x>0) return 1;
	else return -1;
}
bool judge(int x){
	//if the now righter than x
	Vector v1=now-L[x].a,v2=L[x].b-L[x].a;
	if(dcmp(Cross(v1,v2)<0))return true;
	else return false;
}
bool cmp(K a,K b){
	return real(a.a)<real(b.a);
}
struct xy{
	int x,y;
};
bool Cmp(xy a,xy b){
	if(a.y!=b.y)return a.y>b.y;
	return a.x<b.x;
}
xy Ans[5005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%d%d%lf%lf%lf%lf",&n,&m,&x,&y,&xx,&yy)==6){
		L[0].a=Point(x,y),L[0].b=Point(x,yy);
		for(int i=1;i<=n;i++){
			scanf("%lf%lf",&tmpa,&tmpb);
			L[i].a=Point(tmpa,y),L[i].b=Point(tmpb,yy);
		}
		L[n+1].a=Point(xx,y),L[n+1].b=Point(xx,yy);
		sort(L,L+n+2,cmp);
		memset(num,0,sizeof num);
		for(int i=0;i<m;i++){
			scanf("%lf%lf",&tmpa,&tmpb);
			now=Point(tmpa,tmpb);
			int l=0,r=n+1;
			while(l!=r-1){
				int m=(l+r)>>1;
				if(judge(m)){
					l=m;
				}else r=m;
			}
			num[l]++;
		}
		for(int i=0;i<=m;i++) Ans[i].x=i,Ans[i].y=0;
		for(int i=0;i<=n;i++) Ans[num[i]].y++;
	//	sort(Ans+1,Ans+m+1,Cmp);
		puts("Box");
		for(int i=1;i<=m;i++){
			if(Ans[i].y){
				if(Ans[i].x)
				printf("%d: %d\n",Ans[i].x,Ans[i].y);
			}
		//	else break;
		}
	}
	
	return 0;
}
