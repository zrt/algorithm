#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a,b,n;
int c[1005][1005];
struct N{
	int x,w;
	N(int a=0,int b=0){
		x=a,w=b;
	}
};
int mx[1005][1005],mn[1005][1005];
struct Que{//mx
	N q[1005];
	int l,r;
	void insert(N a){
		while(l<r&&q[r-1].w<=a.w) r--;
		q[r++]=a;
	}
	int ask(){
		return q[l].w;
	}
	void pop(int x){
		if(q[l].x==x) l++;
	}
	void clear(){
		l=r=0;
	}
}q1,q2;
int ans;
int main(){
	ans=~0U>>1;
	scanf("%d%d%d",&a,&b,&n);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&c[i][j]);
	for(int j=1;j<=b;j++){
		q1.clear(),q2.clear();
		for(int i=1;i<=a;i++){
			q1.insert(N(i,c[i][j]));
			q2.insert(N(i,-c[i][j]));
			q1.pop(i-n);
			q2.pop(i-n);
			mx[i][j]=q1.ask();
			mn[i][j]=-q2.ask();
		}
	}
	for(int i=n;i<=a;i++){
		q1.clear(),q2.clear();
		for(int j=1;j<=b;j++){
			q1.insert(N(j,mx[i][j]));
			q2.insert(N(j,-mn[i][j]));
			q1.pop(j-n);
			q2.pop(j-n);
			if(j>=n)ans=min(q1.ask()+q2.ask(),ans);
		}
	}
	printf("%d\n",ans);
	return 0;
}
