#include <cstdio>
#include <cstring>
#include <algorithm>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long ll ;
const double eps(1e-10) ;
const int inf(0x3f3f3f3f) ;
int H[10001],P[2020000],X[2020000],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int link[1000050];
bool cover[1000050];
int stk[1000050],top;
bool find(int x){
	for(int i=H[x];i;i=X[i]){
		if(!cover[P[i]]){
			stk[top++]=P[i];
			cover[P[i]]=1;
			int q=link[P[i]];
			link[P[i]]=x;
			if(q==-1||find(q)) return true;
			link[P[i]]=q;
		}
	}
	return false;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	int n;
	scanf("%d",&n);
	for(int i=0,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,i);add(y,i);
	}
	memset(link,-1,sizeof link);
	bool flag=1;
	for(int i=1;i<=10000;i++){
		while(top>0) cover[stk[--top]]=0;
		if(!find(i)) {
			printf("%d\n",i-1);flag=0;break;
		}
	}
	if(flag) puts("10000");
	return 0 ;
}
