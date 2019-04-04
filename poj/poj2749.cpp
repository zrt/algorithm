#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
//  by zrt
//  problem:
using namespace std ;
typedef long long LL ;
const double eps(1e-10) ;
const int inf(0x3f3f3f3f) ;
int n,a,b;
struct Pt{
	int x,y;
};
int dis(Pt a,Pt b){
	return abs(a.x-b.x)+abs(a.y-b.y);
}
Pt s1,s2;
Pt p[505];
int a1[1005],a2[1005];
int b1[1005],b2[1005];
int H[1005],X[1000005],P[1000005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
//<<1 s1 <<1|1 s2
int low[1005];
int stk[1005],top;
bool instk[1005];
int tim;
int cnt;
int belong[1005];
void tarjan(int x){
	int dfn=low[x]=++tim;
	stk[top++]=x;instk[x]=1;
	for(int i=H[x];i;i=X[i]){
		if(!low[P[i]]){
			tarjan(P[i]);
			low[x]=min(low[x],low[P[i]]);
		}else if(instk[P[i]]) low[x]=min(low[x],low[P[i]]);
	}
	if(low[x]>=dfn){
		cnt++;
		int k;
		do{
			k=stk[--top];
			instk[k]=0;
			belong[k]=cnt;
		}while(k!=x);
	}
}
bool judge(int lim){
	tot=0;tim=0;cnt=0;
	memset(H,0,sizeof H);
	memset(low,0,sizeof low);
	for(int i=0;i<a;i++){
		add(a1[i]<<1,a2[i]<<1|1);
		add(a1[i]<<1|1,a2[i]<<1);
		add(a2[i]<<1,a1[i]<<1|1);
		add(a2[i]<<1|1,a1[i]<<1);
	}
	for(int i=0;i<b;i++){
		add(b1[i]<<1,b2[i]<<1);
		add(b1[i]<<1|1,b2[i]<<1|1);
		add(b2[i]<<1,b1[i]<<1);
		add(b2[i]<<1|1,b1[i]<<1|1);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(dis(p[i],s1)+dis(s1,p[j])>lim){
				add(i<<1,j<<1|1);
				add(j<<1,i<<1|1);
			}
			if(dis(p[i],s2)+dis(s2,p[j])>lim){
				add(i<<1|1,j<<1);
				add(j<<1|1,i<<1);
			}
			if(dis(p[i],s1)+dis(s1,s2)+dis(s2,p[j])>lim){
				add(i<<1,j<<1);
				add(j<<1|1,i<<1|1);
			}
			if(dis(p[i],s2)+dis(s1,s2)+dis(s1,p[j])>lim){
				add(i<<1|1,j<<1|1);
				add(j<<1,i<<1);
			}
		}
	}
	for(int i=2;i<=(n<<1|1);i++){
		if(!low[i]) tarjan(i);
	}
	for(int i=1;i<=n;i++){
		if(belong[i<<1]==belong[i<<1|1]) return 0;
	}
	return 1;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d%d%d",&n,&a,&b);
	scanf("%d%d%d%d",&s1.x,&s1.y,&s2.x,&s2.y);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
	}
	for(int i=0;i<a;i++){
		scanf("%d%d",&a1[i],&a2[i]);
	}
	for(int i=0;i<b;i++){
		scanf("%d%d",&b1[i],&b2[i]);
	}
	int l=0,r=4000005;
	int M;
	if(!judge(r)){
		puts("-1");return 0;
	}
	while(r-l>1){
		M=(l+r)/2;
		if(judge(M)) r=M;
		else l=M;
	}
	printf("%d\n",r);
	return 0 ;
}
