#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long LL ;
const double eps(1e-3) ;
const int inf(0x3f3f3f3f) ;
int n,m;
int fi[10050];
int H[10050],X[50050],t[50050],tot,P[50050];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;t[tot]=z;
}
double E[10050];
double d[10050];
struct N{
	int x;
	double w;
	int cnt;
	N(int a=0,double b=0,int c=0){
		x=a,w=b,cnt=c;
	}
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
};

priority_queue<N> q;
double Eps=1e-9;
bool judge(double x){
	while(!q.empty()) q.pop();
//	memset(vis,0,sizeof vis);
	for(int i=1;i<=tot;i++){
		E[i]=t[i]*x-fi[P[i]];
	}
//	d[1]=0;
	for(int i=1;i<=n;i++) d[i]=0,q.push(N(i,0,0));
	int a,cc;
	while(!q.empty()){
//		printf("$%d\n",q.top().cnt);
		if(q.top().cnt>n) return 1;
		a=q.top().x;cc=q.top().cnt;q.pop();
		for(int i=H[a];i;i=X[i]){
			if(d[P[i]]>d[a]+E[i]){
				d[P[i]]=d[a]+E[i];
				q.push(N(P[i],d[P[i]],cc+1));
			}
		}
		while(!q.empty()&&fabs(d[q.top().x]-q.top().w)>Eps) q.pop();
	}
	return false;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&fi[i]);
	for(int i=0,x,y,z;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	//	add(y,x,z);
	}
	double l,r,m;
	if(!judge(0)) {
		puts("0");
		goto ed;
	}
	l=0,r=2000;
	for(int tt=0;tt<30;tt++){
		m=(l+r)/2.0;
		if(judge(m)) l=m;
		else r=m;
	}
	printf("%.2f\n",l);
	ed:;
	return 0 ;
}
