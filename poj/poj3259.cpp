#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
//by zrt
//problem:
using namespace std;
int H[505],P[5505],X[5505],E[5505],tot;
int d[505];
int T;
int n,m,w,x,y,z;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
struct N{
	int x,w,num;
	friend bool operator < (N a,N b){
		return a.w>b.w;
	} 
	N(int a=0,int b=0,int c=0){
		x=a,w=b,num=c;
	}
}t;
priority_queue<N> q;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&T);
	while(T--){
		memset(H,0,sizeof H);
		memset(d,0x7f,sizeof d);tot=0;
		while(!q.empty()) q.pop(); 
		scanf("%d%d%d",&n,&m,&w);
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);add(y,x,z);
		}
		for(int i=0;i<w;i++){
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,-z);
		}
		d[1]=0;
		q.push(N(1,0,0));
		bool _ok=1;
		while(!q.empty()){
			t=q.top();q.pop();
			if(t.num>=n) {
				_ok=0;
				break;
			}
			if(t.w!=d[t.x]) continue;
			for(int i=H[t.x];i;i=X[i]){
				if(d[P[i]]>d[t.x]+E[i]){
					d[P[i]]=d[t.x]+E[i];
					q.push(N(P[i],d[P[i]],t.num+1));
				}
			}
		}
		if(_ok) puts("NO");
		else puts("YES");
	}
	
	return 0;
}
