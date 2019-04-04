#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
//by zrt
//problem:
using namespace std;
int n,m,x,y;
int val[100005];
int H[100005],X[1000005],P[1000005],tot;
int ans[100005];
bool out[100005];int in[100005];
inline void add(int x,int y){
	P[++tot]=y;in[y]++;out[x]=1;X[tot]=H[x];H[x]=tot;
}
int t;
queue<int> q;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%d%d",&n,&m)==2&&n){
		memset(H,0,sizeof H);tot=0;
		memset(in,0,sizeof in);
		memset(out,0,sizeof out);
		memset(ans,0xf3,sizeof ans);
		for(int i=1;i<=n;i++) scanf("%d",&val[i]);
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			add(x,y);
		}
		for(int i=1;i<=n;i++){
			if(!in[i]){
				ans[i]=val[i];
				q.push(i);
			}
		}
		int ret=1<<30;;
		ret=-ret;
		while(!q.empty()){
			t=q.front();q.pop();
			if(!out[t]) ret=max(ans[t],ret);
			for(int i=H[t];i;i=X[i]){
				in[P[i]]--;
				if(!in[P[i]]) q.push(P[i]);
				if(ans[P[i]]<ans[t]+val[P[i]]){
					ans[P[i]]=ans[t]+val[P[i]];
				}
			}
		}
		printf("%d\n",ret);
		n=m=0;
	}
	return 0;
}
