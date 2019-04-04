#include <cstdio>
#include <cstring>
#include <algorithm>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long LL ;
const double eps(1e-10) ;
const int inf(0x3f3f3f3f) ;
int n,m;
//<<1 left <<1|1 right
//i<<1 h i<<1|1 w
int H[200],X[40005],P[40005];
int tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int x,y;
char s1[10],s2[10];
bool mark[200];
int stk[200],top;
bool dfs(int x){
	if(mark[x^1]) return 0;
	if(mark[x]) return 1;
	mark[x]=1;
	stk[top++]=x;
	for(int i=H[x];i;i=X[i]){
		if(!dfs(P[i])) return 0;
	}
	return 1;
}
bool solve(){
	if(!dfs(2)) return 0;
	for(int i=4;i<n<<2;i+=2){
		if(!mark[i]&&!mark[i^1]){
			top=0;
			if(!dfs(i)){
				while(top>0) mark[stk[--top]]=0;
				if(!dfs(i^1)) return 0;
			}
		}
	}
	return 1;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	while(scanf("%d%d",&n,&m),n|m){
		tot=0;
		memset(H,0,sizeof H);
		for(int i=0;i<n;i++){
			add((i<<1)<<1,(i<<1|1)<<1|1);
			add((i<<1|1)<<1,(i<<1)<<1|1);
			add((i<<1)<<1|1,(i<<1|1)<<1);
			add((i<<1|1)<<1|1,(i<<1)<<1);
		}
		for(int i=0;i<m;i++){
			scanf("%d%s%d%s",&x,s1,&y,s2);
			if(s1[0]=='h') x=x<<1;
			else x=x<<1|1;
			if(s2[0]=='h') y=y<<1;
			else y=y<<1|1;
			add(x<<1|1,y<<1);
			add(y<<1|1,x<<1);
		}
		memset(mark,0,sizeof mark);
		if(solve()){
			bool ff=1;
			for(int i=1;i<n;i++){
				if(ff) ff=0;else putchar(' ');
				if(mark[(i<<1)<<1]) printf("%dh",i);
				else printf("%dw",i);
			}
			puts("");
		}else puts("bad luck");
	}
	return 0 ;
}