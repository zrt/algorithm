#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,x,y,z;
struct N{
	int x,y,id;
}p[5005],a[5005],b[5005];
bool cmp1(N a,N b){
	return a.x<b.x;
}
bool cmp2(N a,N b){
	return a.x+a.y<b.x+b.y;
}
bool cmp3(N a,N b){
	return a.y<b.y;
}
bool chose[5005];
bool judge(int x,int y,int z){//p[x],a[y]
	if(p[x].x<a[y].x||p[x].y<b[z].y) return 0;
	else{
		chose[p[x].id]=1;
		return 1;
	}
}
int main(){
	scanf("%d%d%d%d",&n,&x,&y,&z);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
		p[i].x*=x;p[i].y*=y;
		p[i].id=i;a[i]=b[i]=p[i];
	}
	sort(a+1,a+n+1,cmp1);
	sort(b+1,b+n+1,cmp3);
	sort(p+1,p+n+1,cmp2);
	int l=1,r=0,sum=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		l=1,r=0;
		memset(chose,0,sizeof chose);
		sum=0;
		for(int j=1;j<=n;j++){
			while(r+1<=n&&p[r+1].x-a[i].x+p[r+1].y-b[j].y<=z) r++,sum+=judge(r,i,j);
			while(l<=r&&(p[l].x<a[i].x||p[l].y<b[j].y)){
				if(chose[p[l].id]){
					sum--;
					chose[p[l].id]=0;
				}
				l++;
			}
			ans=max(ans,sum);
			if(chose[b[j].id]){
				chose[b[j].id]=0;
				sum--;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
