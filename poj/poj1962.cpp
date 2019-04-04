#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
//by zrt
//problem:
using namespace std;
int tt;
int f[20005];
int dis[20005];
char s[10];
int get(int x){
	if(x==f[x]) return x;
	int root=get(f[x]);
	dis[x]=dis[f[x]]+dis[x];
	return f[x]=root;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&tt);
	while(tt--){
		int n,x,y;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) f[i]=i;
		memset(dis,0,sizeof dis);
		while(scanf("%s",s),s[0]!='O'){
			if(s[0]=='E'){
				scanf("%d",&x);
				get(x);
				printf("%d\n",dis[x]);
			}else{
				scanf("%d%d",&x,&y);
				get(x);
				get(y);
				f[x]=y;
				dis[x]=abs(x-y)%1000;
			}
		}
	}
	
	return 0;
}
