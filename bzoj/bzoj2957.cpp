#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n,m;
int x[100005],y[100005];
int to[100005],cc;
int SIZE;
typedef long double ld;
bool cmp(ld a,ld b){
	return fabs(a-b)<1e-10;
}
struct Block{
	ld a[401];
	ld b[401];
	int cc;
	void mk(){
		cc=0;
		for(int i=1;i<=400;i++){
			if(cc==0||a[i]>b[cc]) b[++cc]=a[i];
		}
	}
	void change(int x,ld k){
		a[x]=k;
		mk();
	}
	int ask(ld k){
		int p=upper_bound(b+1,b+cc+1,k)-b;
		return cc-p+1;
	}
}B[401];
void change(int x,int y){
	ld k=y/(ld)x;
	int id=lower_bound(to+1,to+cc+1,x)-to;
	int num=(id-1)/SIZE+1;
	B[num].change(id-(num-1)*SIZE,k);
}
int ask(){
	ld mx=1e-12;
	int ans=0;
	for(int i=1;i<=400;i++){
		ans+=B[i].ask(mx);
		mx=max(mx,B[i].b[B[i].cc]);
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d",&x[i],&y[i]),to[i]=x[i];
	sort(to+1,to+m+1);
	cc=unique(to+1,to+m+1)-(to+1);
	SIZE=400;
	for(int i=1;i<=m;i++){
		change(x[i],y[i]);
		printf("%d\n",ask());
	}
	return 0;
}
