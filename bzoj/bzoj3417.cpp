#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,k;
int H[5005],X[10005],P[10005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int d[5005][2];
struct N{
	int s,t,d,id;
}Q[1000005];
bool cmp(N a,N b){
	return a.s<b.s;
}
int ans[1000005];
queue<int> q;
int cnt;
void bfs(int x){
	memset(d,0,sizeof d);
	d[x][0]=1;cnt=0;
	q.push(x<<1);
	while(!q.empty()){
		x=q.front();q.pop();
		cnt++;
		int t=x&1;x>>=1;
		for(int i=H[x];i;i=X[i]){
			if(!d[P[i]][t^1]){
				d[P[i]][t^1]=d[x][t]+1;
				q.push(P[i]<<1|(t^1));
			}
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0,x,y;i<m;i++){
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	for(int i=0;i<k;i++){
		scanf("%d%d%d",&Q[i].s,&Q[i].t,&Q[i].d);
		Q[i].id=i;
	}
	sort(Q,Q+k,cmp);
	int last=0;
	for(int i=0;i<k;i++){
		if(last==Q[i].s){
			if(cnt==1){
				continue;
			}
			if(d[Q[i].t][Q[i].d&1]&&d[Q[i].t][Q[i].d&1]-1<=Q[i].d) ans[Q[i].id]=1;
		}else{
			bfs(Q[i].s);
			last=Q[i].s;
			i--;
		}
	}
	for(int i=0;i<k;i++) if(ans[i]) puts("TAK");else puts("NIE");
	return 0;
}
