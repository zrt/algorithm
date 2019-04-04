#include <cstdio>
#include <cstring>
#include <algorithm>
//  by zrt
//  problem:
using namespace std ;
typedef long long LL ;
const double eps(1e-10) ;
const int inf(0x3f3f3f3f) ;
int n,m;
//二分。判定
int n1[1025],n2[1025];
int m1[2049],m2[2049];
int H[5000],X[2500000],P[2500000],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int low[5000];
int stk[5000],top,tim;
bool instk[5000];int cnt;
int belong[5000];
void tarjan(int x){
	instk[x]=1;stk[top++]=x;
	int dfn=low[x]=++tim;
	for(int i=H[x];i;i=X[i]){
		if(!low[P[i]]){
			tarjan(P[i]);
			low[x]=min(low[x],low[P[i]]);
		}else if(instk[P[i]]) low[x]=min(low[x],low[P[i]]);
	}
	if(low[x]>=dfn){
		int k;
		cnt++;
		do{
			k=stk[--top];
			instk[k]=0;
			belong[k]=cnt;
		}while(k!=x);
	}
}
//<<1 chose <<1|1 nochose
bool judge(int num){
	tot=0;tim=0;cnt=0;
	memset(H,0,sizeof H);
	memset(low,0,sizeof low);
	for(int i=0;i<num;i++){
		add(m1[i]<<1|1,m2[i]<<1);
		add(m2[i]<<1|1,m1[i]<<1);
	}
	for(int i=0;i<n;i++){
		add(n1[i]<<1,n2[i]<<1|1);
		add(n2[i]<<1,n1[i]<<1|1);
	}
	for(int i=0;i<n<<2;i++){
		if(!low[i]) tarjan(i);
	}
	for(int i=0;i<n<<1;i++){
		if(belong[i<<1]==belong[i<<1|1]) return 0;
	}
	return 1;
} 
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	while(scanf("%d%d",&n,&m),n|m){
		for(int i=0;i<n;i++){
			scanf("%d%d",&n1[i],&n2[i]);
		}
		for(int i=0;i<m;i++){
			scanf("%d%d",&m1[i],&m2[i]);
		}
		int l=0,r=m+1;
		int M;
		while(r-l>1){
			M=(l+r)/2;
			if(judge(M)){
				l=M;
			}else{
				r=M;
			}
		}
		printf("%d\n",l);
	}
	return 0 ;
}
