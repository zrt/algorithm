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
Point La[5005],Lb[5005];
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
	Vector v1=now-La[x],v2=Lb[x]-La[x];
	if(dcmp(Cross(v1,v2)<=0))return true;
	else return false;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%d%d%lf%lf%lf%lf",&n,&m,&x,&y,&xx,&yy)==6){
		La[0]=Point(x,y),Lb[0]=Point(x,yy);
		for(int i=1;i<=n;i++){
			scanf("%lf%lf",&tmpa,&tmpb);
			La[i]=Point(tmpa,y),Lb[i]=Point(tmpb,yy);
		}
		La[n+1]=Point(xx,y),Lb[n+1]=Point(xx,yy);
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
		for(int i=0;i<=n;i++){
			printf("%d: %d\n",i,num[i]);
		}
		puts("");
	}
	
	return 0;
}
