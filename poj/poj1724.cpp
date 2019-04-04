#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int d[105][10005];// i dian shi w hua fei shi de zui duan lu
struct N{
	int x,y,w;// aim dis cost
	N(int a=0,int b=0,int c=0){
		x=a,y=b,w=c;
	}
	friend bool operator < (N a,N b){
		return a.y>b.y;
	}
}t;
priority_queue<N> q;
const int inf=0x3f3f3f3f;
int H[105],X[10006],P[10005],L[10005],W[10005];
int tot;
int add(int x,int y,int l,int w){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
	L[tot]=l;W[tot]=w;
}
int main(){
	int k,n,m;
	scanf("%d%d%d",&k,&n,&m);
	memset(d,0x3f,sizeof d);
	int x,y,w,l;
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d",&x,&y,&l,&w);
		add(x,y,l,w);
	}
	for(int i=0;i<10005;i++) d[1][i]=0;
	q.push(N(1,0,0));
	while(!q.empty()){
		t=q.top();q.pop();
		if(d[t.x][t.w]!=t.y) continue;
		for(int i=H[t.x];i;i=X[i]){
			if(t.w+W[i]>k) continue;
			if(d[P[i]][t.w+W[i]]>d[t.x][t.w]+L[i]){
				d[P[i]][t.w+W[i]]=d[t.x][t.w]+L[i];
				q.push(N(P[i],d[P[i]][t.w+W[i]],t.w+W[i]));
			}
		}
	}
	int minn=inf;
	for(int i=0;i<=k;i++){
		if(minn>d[n][i]){
			minn=d[n][i];
		}
	}
	if(minn!=inf)	printf("%d\n",minn);
	else puts("-1");
	return 0;
}