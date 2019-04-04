#include<iostream>
#include<cstdio>
#include<queue>
//by zrt
//problem:
using namespace std;
int H[150],X[300],P[300],tot;double r[300],c[300];
int s,n,m,p,q;
double sum,x,y;
inline void add(int x,int y,double p,double q){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;r[tot]=p,c[tot]=q;
}
struct N{
	int x,num;double w;
	friend bool operator < (N a,N b){
		return a.w<b.w;
	}
	N(int a=0,double b=0.0,int c=0){
		x=a,w=b,num=c;
	}
}t;
double d[150];
priority_queue<N> Q;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d%lf",&n,&m,&s,&sum);
	for(int i=0;i<m;i++){
		scanf("%d%d%lf%lf",&p,&q,&x,&y);
		add(p,q,x,y);
		scanf("%lf%lf",&x,&y);
		add(q,p,x,y);
	}
	d[s]=sum;
	Q.push(N(s,d[s],0));
	bool _ok=1;
	while(!Q.empty()){
		t=Q.top();Q.pop();
		if(t.num>=n){
			_ok=0;break;
		} 
		if(t.w!=d[t.x]) continue;
		for(int i=H[t.x];i;i=X[i]){
			x=(d[t.x]-c[i])*r[i];
			if(x>d[P[i]]){
				d[P[i]]=x;
				Q.push(N(P[i],d[P[i]],t.num+1));
			}
		}
	}
	if(!_ok) puts("YES");
	else puts("NO");
	return 0;
}
