#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,B;
int H[1005],X[2005],P[2005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int stk[1005],top;
int last;
int num;
int a[1005],b[1005];
void dfs(int x,int fa){
	int bottom=top;
	for(int i=H[x];i;i=X[i]){
		if(fa==P[i]) continue;
		dfs(P[i],x);
		if(top-bottom>=B){
			b[++num]=x;
			while(top!=bottom){
				a[stk[top--]]=num;
			}
		}
	}
	stk[++top]=x;
}
int main(){
	scanf("%d%d",&n,&B);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	if(B>n){
		puts("0");
		return 0;
	}
	dfs(1,0);
	while(top){
		int x=stk[top--];
		a[x]=num;
	}
	printf("%d\n",num);
	bool f=1;
	for(int i=1;i<=n;i++){
		if(f) f=0;else putchar(' ');
		printf("%d",a[i]);
	}
	puts("");
	f=1;
	for(int i=1;i<=num;i++){
		if(f) f=0;else putchar(' ');
		printf("%d",b[i]);
	}
	puts("");
	return 0;
}
