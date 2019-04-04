#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
queue<int> q;
int n,ml,md;
int H[1005],X[40005],P[40005],E[40005],tot;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
int d[1005];
int l[1005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d",&n,&ml,&md);
	for(int i=1;i<n;i++) add(i+1,i,0);
	for(int i=0,x,y,z;i<ml;i++){
		scanf("%d%d%d",&x,&y,&z);
		if(x>y) swap(x,y);
		add(x,y,z);
	}
	for(int i=0,x,y,z;i<md;i++){
		scanf("%d%d%d",&x,&y,&z);
		if(x>y) swap(x,y);
		add(y,x,-z);
	}
	bool circle=0;
	memset(d,0x3f,sizeof d);
	d[1]=0;
	q.push(1);
	while(!q.empty()){
		int x=q.front();q.pop();
		if(l[x]>n){
			circle=1;break;
		}
		for(int i=H[x];i;i=X[i]){
			if(d[P[i]]>d[x]+E[i]){
				d[P[i]]=d[x]+E[i];
				l[P[i]]=l[x]+1;
				q.push(P[i]);
			}
		}
	}
	if(circle){
		puts("-1");
	}else if(d[n]==0x3f3f3f3f){
		puts("-2");
	}else printf("%d\n",d[n]);
	return 0;
}
