#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
struct point{
	int x,y;
}a[105],b[105],stk[105];
bool cmp(const point&a,const point&b){
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
bool judge(const point&a,const point&b,const point&c){
	return (a.x-b.x)*(c.y-b.y)-(a.y-b.y)*(c.x-b.x)>0;
}
int top;
bool del[105];
int floyd[105][105];
int tot;
bool judge(const point&a,const point&bb){
	point p;
	p.x=bb.x-a.x;
	p.y=bb.y-a.y;
	for(int i=0;i<m;i++){
		if(del[i]) continue;
		if(p.x*(b[i].y-a.y)-p.y*(b[i].x-a.x)<0) return 0;
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	for(int i=0;i<m;i++) scanf("%d%d",&b[i].x,&b[i].y);
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		while(top>1&&judge(stk[top-2],stk[top-1],a[i])) top--;
		stk[top++]=a[i];
	}
	int t=top;
	for(int i=n-2;i>=0;i--){
		while(top>t&&judge(stk[top-2],stk[top-1],a[i])) top--;
		stk[top++]=a[i];
	}
	top--;
	for(int i=0;i<m;i++){
		for(int j=0;j<top;j++){
			if(judge(stk[j],stk[j+1],b[i])){
				del[i]=1;tot++;
				break;
			}
		}
	}
	memset(floyd,0x3f,sizeof floyd);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j){
				if(judge(a[i],a[j])){
					floyd[i][j]=1;
				}
			}
		}
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++) floyd[i][j]=min(floyd[i][j],floyd[i][k]+floyd[k][j]);
		}
	}
	int ans=0x3f3f3f3f;
	for(int i=0;i<n;i++) ans=min(ans,floyd[i][i]);
	if(ans>n||ans<3){
		printf("%d\n",m*111);
	}else{
		printf("%d\n",tot*111+20*ans);
	}
	return 0;
}
