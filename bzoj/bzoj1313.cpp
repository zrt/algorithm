#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
int H[105*3],X[10005*4],P[10005*4],tot=1,flow[10005*4];
int floww[10005*4];
int in[105*3];
void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
int d[105*3];
int S,T,SS,TT;
queue<int> q;
const double eps(1e-8);
bool bfs(){
	memset(d,0,sizeof d);
	d[SS]=1;
	q.push(SS);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			if(!d[P[i]]&&flow[i]>0){
				d[P[i]]=d[x]+1;
				q.push(P[i]);
			}
		}
	}
	return d[TT];
}
int hs,ht;
int dfs(int x,int a){
	if(x==TT||a==0) return a;
	int tmp,f=a;
	for(int i=H[x];i;i=X[i]){
		if(d[P[i]]==d[x]+1&&flow[i]>0){
			tmp=dfs(P[i],min(flow[i],a));
			a-=tmp;
			flow[i]-=tmp;
			flow[i^1]+=tmp;
			if(!a) break;
		}
	}
	if(f==a) d[x]=-1;
	return f-a;
}
double Matrix[105][105];
int n,tott;
int Sum;
int Dinic(){
	int ff=0;
	while(bfs()){
		ff+=dfs(SS,2000000000);
	}
	return ff;
}

bool judge(int lim){
	in[T]-=lim;
	in[S]+=lim;
	int tmp=Sum;
	if(in[S]>0)add(SS,S,in[S]),add(S,SS,0),tmp+=in[S];
	else add(S,TT,-in[S]),add(TT,S,0);
	if(in[T]>0)add(SS,T,in[T]),add(T,SS,0),tmp+=in[T];
	else add(T,TT,-in[T]),add(TT,T,0);
	in[T]+=lim;
	in[S]-=lim;
	if(Dinic()==tmp){
		return 1;
	}else return 0;
}

int main(){
	S=300,T=301;
	SS=298,TT=299;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%lf",&Matrix[i][j]);
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			Matrix[i][j]+=1000;
		}
		Matrix[i][n]+=1000*(n-1);
		Matrix[n][i]+=1000*(n-1);
	}

	add(T,S,200000500);
	add(S,T,0);
	for(int i=1;i<n;i++){
		in[S]-=floor(Matrix[i][n]-eps);
		in[i<<1]+=floor(Matrix[i][n]-eps);
		add(S,i<<1,1);add(i<<1,S,0);
		in[T]+=floor(Matrix[n][i]-eps);
		in[i<<1|1]-=floor(Matrix[n][i]-eps);
		add(i<<1|1,T,1);add(T,i<<1|1,0);
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			in[i<<1]-=floor(Matrix[i][j]-eps);
			in[j<<1|1]+=floor(Matrix[i][j]-eps);
			add(i<<1,j<<1|1,1);
			add(j<<1|1,i<<1,0);
		}
	}
	for(int i=1;i<n;i++){
		if(in[i<<1]>0) add(SS,i<<1,in[i<<1]),add(i<<1,SS,0),Sum+=in[i<<1];
		else add(i<<1,TT,-in[i<<1]),add(TT,i<<1,0);
		if(in[i<<1|1]>0) add(SS,i<<1|1,in[i<<1|1]),add(i<<1|1,SS,0),Sum+=in[i<<1|1];
		else add(i<<1|1,TT,-in[i<<1|1]),add(TT,i<<1|1,0);
	}
	hs=H[S],ht=H[T];
	int hss,htt;
	hss=H[SS],htt=H[TT];
	memcpy(floww,flow,sizeof flow);
	tott=tot;
	int l=0,r=200000100;
	while(r-l>1){
		int mid=(l+r)>>1;
		memcpy(flow,floww,sizeof flow);
		tot=tott;
		H[S]=hs;H[T]=ht;H[SS]=hss;H[TT]=htt;
		if(judge(mid)){
			l=mid;
		}else{
			r=mid;
		}
	}
	printf("%d\n",(l-1000*(n-1)*(n-1))*3);
	return 0;
}
