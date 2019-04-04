/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//永远做自己会做的题就永远还是原来的样子
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<deque>
//by zrt
//problem:
using namespace std;
int n,p,k;
int H[1005],X[20005],P[20005],tot,E[20005];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot; E[tot]=z;
}
int L,R,mid,x,y,z;
int _E[20005];
deque<int> q;
int d[1005];
bool vis[1005]; 
bool judge(int w){
	memset(d,0x3f,sizeof d);
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++){
		for(int j=H[i];j;j=X[j]){
			if(E[j]>w){
				_E[j]=1;
			}else{
				_E[j]=0;
			}
		}
	}
	//0 ..1 bfs
	q.clear();
	d[1]=0;
	q.push_front(1);
	int t;
	while(!q.empty()){
		t=q.front();q.pop_front();
		if(vis[t])continue;else vis[t]=1;
		for(int i=H[t];i;i=X[i]){
		//	if(d[P[i]]) continue;
			if(_E[i]==0){
				d[P[i]]=min(d[P[i]],d[t]);
				q.push_front(P[i]);
			}else{
				d[P[i]]=min(d[P[i]],d[t]+1);
				q.push_back(P[i]);
			}
		}
	}
	if(d[n]>k) return false;
	return true;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d",&n,&p,&k);
	for(int i=0;i<p;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,x,z);
		if(z>R) R=z;
	}
	//R ok L not ok
	if(!judge(R)){
		puts("-1");return 0;
	}
	if(judge(L)){
		puts("0");return 0;
	}
	while(R-L>1){
		mid=L+((R-L)>>1);
		if(judge(mid)){
			R=mid;
		}else L=mid;
	}
	printf("%d\n",R);
	return 0;
}
