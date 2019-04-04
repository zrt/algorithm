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
int H[20005],X[100005],P[100005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int n,m;
int d[20005];
queue<int> q;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=0,x,y;i<m;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	d[1]=1;
	q.push(1);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			if(!d[P[i]]){
				d[P[i]]=d[x]+1;
				q.push(P[i]);
			}
		}
	}
	int num,mx=-1,pos;
	for(int i=1;i<=n;i++){
		if(d[i]>mx){
			mx=d[i];
			num=1;
			pos=i;
		}else if(d[i]==mx){
			num++;
		}
	}
	printf("%d %d %d\n",pos,mx-1,num);
	return 0;
}
