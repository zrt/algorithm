#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
//by zrt
//problem:
using namespace std;
int n;
struct line{
	double x;
	double y1,y2;
}a[80];
int cc;
int num;
double eps=1e-10;
int H[405],X[800005],P[800005],tot;
double E[800005];
inline void add(int x,int y,double z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
struct point{
	double x,y;
}p[405];
double dis(int i,int j){
	return sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
}
bool check(int x,int y){
	if(p[x].x>p[y].x) swap(x,y);
	if(fabs(p[x].x-p[y].x)<eps){
		return 0;
	}
	for(int i=0;i<cc;i++){
		if(a[i].x-eps<p[x].x) continue;
		if(a[i].x+eps>p[y].x) continue;
		double h=(p[y].y-p[x].y)/(p[y].x-p[x].x)*(a[i].x-p[x].x)+p[x].y;
		if(h>=a[i].y1&&h<=a[i].y2) return 0;
	}
	return 1;
}
double d[405];
struct N{
	int x;
	double w;
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
	N(int a=0,double b=0){
		x=a,w=b;
	}
};
priority_queue<N> q;
bool vis[405];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%d",&n),~n){
		double x,y1,y2,y3,y4;
		cc=0;num=0;
		memset(H,0,sizeof H);
		tot=0;
		p[num].x=0;
		p[num++].y=5;
		p[num].x=10;
		p[num++].y=5;
		for(int i=0;i<n;i++){
			scanf("%lf%lf%lf%lf%lf",&x,&y1,&y2,&y3,&y4);
			a[cc].x=x;
			a[cc].y1=0;
			a[cc].y2=y1;
			cc++;
			a[cc].x=x;
			a[cc].y1=y2;
			a[cc].y2=y3;
			cc++;
			a[cc].x=x;
			a[cc].y1=y4;
			a[cc].y2=10;
			cc++;
			p[num].x=x;
			p[num++].y=y1;
			add(num-1,num,y2-y1);
			add(num,num-1,y2-y1);
			p[num].x=x;
			p[num++].y=y2;
			p[num].x=x;
			p[num++].y=y3;
			add(num-1,num,y4-y3);
			add(num,num-1,y4-y3);
			p[num].x=x;
			p[num++].y=y4;
		}
		for(int i=0;i<num;i++){
			for(int j=i+1;j<num;j++){
				if(check(i,j)){
					add(i,j,dis(i,j));
					add(j,i,dis(i,j));
				}
			}
		}
		memset(vis,0,sizeof vis);
		for(int i=0;i<num;i++) d[i]=1e10;
		q.push(N(0,0));
		d[0]=0;
		while(!q.empty()){
			int x=q.top().x;q.pop();
			if(vis[x]) continue;
			vis[x]=1;
			for(int i=H[x];i;i=X[i]){
				if(!vis[P[i]]&&d[P[i]]+eps>d[x]+E[i]){
					d[P[i]]=d[x]+E[i];
					q.push(N(P[i],d[P[i]]));
				}
			}
		}
		printf("%.2f\n",d[1]);
	}
	
	return 0;
}
