#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
struct point{
    double x,y;
}a[505],b[505],stk[505];
int m,n,top;
double tmp;
const double eps=1e-12;
bool cmp(const point&a,const point&b){
    if(fabs(a.x-b.x)>eps) return a.x<b.x;
    return a.y<b.y; 
}
int floyd[505][505];
bool judge(const point &a,const point&bb){
    point p;
    p.x=bb.x-a.x;
    p.y=bb.y-a.y;
    for(int i=0;i<n;i++){
        if(p.x*(b[i].y-a.y)-p.y*(b[i].x-a.x)<-eps) return 0;
    }
    return 1;
}
int belong[505];
bool judge(const point&a,const point&b,const point&c){
    return (a.x-b.x)*(c.y-b.y)-(a.y-b.y)*(c.x-b.x)>eps;
}
int main(){
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++){
        scanf("%lf%lf%lf",&a[i].x,&a[i].y,&tmp);
    }
    for(int i=0;i<n;i++){
        scanf("%lf%lf%lf",&b[i].x,&b[i].y,&tmp);
    }
    sort(a,a+m,cmp);
    for(int i=0;i<m;i++){
        while(top>1&&judge(stk[top-2],stk[top-1],a[i])) top--;
        stk[top++]=a[i];
    }
    int t=top;
    for(int i=m-2;i>=0;i--){
        while(top>t&&judge(stk[top-2],stk[top-1],a[i])) top--;
        stk[top++]=a[i];
    }
    top--;
    for(int i=0;i<n;i++){
        for(int j=0;j<top;j++){
            if(judge(stk[j],stk[j+1],b[i])){
                puts("-1");
                return 0;
            }
        }
    }
    memset(floyd,0x3f,sizeof floyd);
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(i!=j){
                if(judge(a[i],a[j])) floyd[i][j]=1;
            }
        }
    }
    for(int k=0;k<m;k++) for(int i=0;i<m;i++) for(int j=0;j<m;j++) floyd[i][j]=min(floyd[i][j],floyd[i][k]+floyd[k][j]);
    int ans=0x3f3f3f3f;
    for(int i=0;i<m;i++) ans=min(ans,floyd[i][i]);
	if(ans>m) ans=1;

	//哎。。
	
    printf("%d\n",ans);
    return 0;
}
