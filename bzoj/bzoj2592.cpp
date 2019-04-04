#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
int n;
int dcmp(double x){
	if(fabs(x)<eps) return 0;
	if(x>0) return 1;else return -1;
}
struct point{
	double x,y;
	point (double a=0,double b=0){
		x=a,y=b;
	}
	friend bool operator < (point a,point b){
		if(dcmp(a.x-b.x)) return a.x<b.x;
		return dcmp(a.y-b.y)<0;
	}
}p[1005];
typedef point Vector;
Vector operator - (point a,point b){
	return Vector(a.x-b.x,a.y-b.y);
}
Vector operator * (Vector a,double k){
	return Vector(a.x*k,a.y*k);
}
point operator + (point a,Vector b){
	return point(a.x+b.x,a.y+b.y);
}
Vector operator / (Vector a,double k){
	return Vector(a.x/k,a.y/k);
}
set<point> s;
set<Vector> line;
Vector Rot(Vector a){
	return Vector(-a.y,a.x);
}
double Length(Vector a){
	return sqrt(a.x*a.x+a.y*a.y);
}
double Cross(Vector a,Vector b){
	return a.x*b.y-a.y*b.x;
}
bool check(point a){
	set<point>::iterator it=s.lower_bound(a);
	if(it!=s.end()&&dcmp(it->x-a.x)==0&&dcmp(it->y-a.y)==0){
		return 1;
	}
	--it;
	if(it!=s.begin()&&dcmp(it->x-a.x)==0&&dcmp(it->y-a.y)==0){
		return 1;
	}
	return 0;
}

int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lf%lf",&p[i].x,&p[i].y),s.insert(p[i]);
	for(int i=2;i<=n;i++){//1
		Vector k=p[i]-p[1];
		point A=p[1]+k*0.5;
		Vector f=Rot(k);
		f=f/Length(f);
		bool ok=1;
		for(int j=2;j<=n;j++){
			if(i!=j){
				int tmp=dcmp(Cross(f,p[j]-A));
				if(tmp==0){
			//		ok=0;break;
				}else{//k
					point another=p[j]+k/Length(k)*Cross(f,p[j]-A)*2;
					if(!check(another)){
						ok=0;break;
					}
				}
			}
		}
		if(ok){
			if(f.x<0) f=f*-1;
			 line.insert(f);
		}
	}
	for(int i=3;i<=n;i++){//2
		Vector k=p[i]-p[2];
		point A=p[2]+k*0.5;
		Vector f=Rot(k);
		f=f/Length(f);
		bool ok=1;
		for(int j=1;j<=n;j++){
			if(i!=j&&j!=2){
				int tmp=dcmp(Cross(f,p[j]-A));
				if(tmp==0){
			//		ok=0;break;
				}else{//k
					point another=p[j]+k/Length(k)*Cross(f,p[j]-A)*2;
					if(!check(another)){
						ok=0;break;
					}
				}
			}
		}
		if(ok){
			if(f.x<0) f=f*-1;
			line.insert(f);
		}
	}
	for(int i=2;i<=n;i++){//1
		Vector f=p[i]-p[1];
		point A=p[1];
		f=f/Length(f);
		Vector k=Rot(f);
		bool ok=1;
		for(int j=2;j<=n;j++){
			if(i!=j){
				int tmp=dcmp(Cross(f,p[j]-A));
				if(tmp==0){
			//		ok=0;break;
				}else{//k
					point another=p[j]+k/Length(k)*Cross(f,p[j]-A)*-2;
					if(!check(another)){
						ok=0;break;
					}
				}
			}
		}
		if(ok){
			if(f.x<0) f=f*-1;
			line.insert(f);
		}
	}
//	for(set<Vector>::iterator it=line.begin();it!=line.end();++it){
//		printf("%.2f %.2f\n",it->x,it->y);
//	}
	printf("%u\n",line.size());
	return 0;
}
