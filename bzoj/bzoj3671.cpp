#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int _x,A,b,c,d;
int Rand(){
	return _x=(A*1LL*_x%d*_x%d+b*1LL*_x%d+c)%d;
}
int a[5005*5005];
int pos[5005*5005];
int l[5005],r[5005];
int n,m,q;
bool judge(int k){
	int p=pos[k];
	int x=p/m,y=p%m;
	if(l[x]<=y&&r[x]>=y){
		for(int i=0;i<x;i++){
			r[i]=min(r[i],y);
		}
		//l[x]=m;
		for(int i=x+1;i<n;i++){
			l[i]=max(l[i],y);
		}
		return 1;
	}else return 0;
}
int main(){
	scanf("%d%d%d%d%d",&_x,&A,&b,&c,&d);
	//printf("%d %d %d %d %d\n",_x,A,b,c,d);
	scanf("%d%d%d",&n,&m,&q);
	int nm=n*m;
	for(int i=0;i<nm;i++) a[i]=i+1;
	for(int i=0;i<nm;i++) swap(a[i],a[Rand()%(i+1)]);
	for(int i=0;i<n;i++) r[i]=m-1;
	for(int i=0,x,y;i<q;i++){
		scanf("%d%d",&x,&y);
		swap(a[x-1],a[y-1]);
	}
	for(int i=0;i<nm;i++) pos[a[i]]=i;
	int p=n+m-1;
	int i=1;
	while(p){
		while(!judge(i)) i++;
		if(p-1)printf("%d ",i);
		else printf("%d",i);
		i++;
		p--;
	}
	puts("");
	return 0;
}
