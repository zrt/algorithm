#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int H[1100005],X[2100005],P[2100005],E[2100005],tot;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
int n;
LL ans;
int top;
int circle[2100005];
bool incircle[1100005];
bool vis[1100005];
int pre[1100005];
LL prew[1100005];
LL D[1100005];
LL w[2100005];
int now[2100005];
queue<int> q;
int stk[2100005],tp;
int to[1100005];
void stkdfs(int x,int fa){
//	printf("%d\n",x);
	stk[tp++]=x;
	to[x]=fa;
	st:;
	while(tp>0){
		x=stk[--tp];
		vis[x]=1;
		for(int& i=now[x];i;i=X[i]){
			if(i==to[x]) continue;
			if(!vis[P[i]]){
				pre[P[i]]=x;to[P[i]]=i^1;prew[P[i]]=E[i];
				stk[tp++]=x;stk[tp++]=P[i];
				i=X[i];
				goto st;
			}else{
				if(incircle[x]) continue;
				int k=x;
				top=0;
				while(k!=P[i]){
					w[top]=prew[k];
					circle[top++]=k;
					incircle[k]=1;
					k=pre[k];
				}
				circle[top++]=P[i];
				incircle[P[i]]=1;
				w[top-1]=E[i];
			}
		}
	}
}
void dfs(int x,int fa){
	vis[x]=1;
	for(int i=H[x];i;i=X[i]){
		if(i==fa) continue;
		if(!vis[P[i]]){
			pre[P[i]]=x;prew[P[i]]=E[i];
			dfs(P[i],i^1);
		}else{
			if(incircle[x]) continue;
			int k=x;
			top=0;
			while(k!=P[i]){
				w[top]=prew[k];
				circle[top++]=k;
				incircle[k]=1;
				k=pre[k];
			}
			circle[top++]=P[i];
			incircle[P[i]]=1;
			w[top-1]=E[i];
		}
	}
}
LL _ans;
void solve(int x,int fa){
	for(int i=H[x];i;i=X[i]){
		if(P[i]==fa||incircle[P[i]]) continue;
		solve(P[i],x);
		_ans=max(_ans,D[x]+D[P[i]]+E[i]);
		D[x]=max(D[x],D[P[i]]+E[i]);
	}
	_ans=max(_ans,D[x]);
}
int fa[1100005],in[1100005];
queue<int> tuopu;
void bfs_solve(int x,int ff){
	q.push(x);
	in[0]=-1;
	while(!q.empty()){
		x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			if(P[i]==fa[x]||incircle[P[i]]) continue;
			fa[P[i]]=x;
			q.push(P[i]);
			in[x]++;
		}
		if(!in[x]) tuopu.push(x);
	}
	while(!tuopu.empty()){
		x=tuopu.front();tuopu.pop();
		for(int i=H[x];i;i=X[i]){
			if(P[i]==fa[x]||incircle[P[i]]) continue;
			_ans=max(_ans,D[x]+D[P[i]]+E[i]);
			D[x]=max(D[x],D[P[i]]+E[i]);
		}
		_ans=max(_ans,D[x]);
		in[fa[x]]--;
		if(!in[fa[x]]) tuopu.push(fa[x]);
	}
}

struct dddl{
	int q[2100005];LL w[2100005];
	int h,t;
	void pop(int pos){
		if(h==t) return;
		if(q[h]==pos){
			h++;
		}
		return;
	}
	void insert(int pos,LL val){
		while(h!=t&&w[t-1]<=val) t--;
		q[t]=pos;w[t]=val;
		t++;
		return;
	}
	LL ask(){
		if(h==t) return 0;
		return w[h];
	}
	void clr(){
		h=t=0;
	}
}dddl;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	#endif
	tot=1;
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;i++){
		scanf("%d%d",&x,&y);
		add(i,x,y);
		add(x,i,y);
	}
	memcpy(now,H,sizeof H);
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			pre[i]=-1;
			stkdfs(i,-1);
			_ans=0;
			for(int i=0;i<top;i++){
				bfs_solve(circle[i],-1);
			}
			LL sum=0;
			dddl.clr();
			for(int i=0;i<top;i++){
				w[i+top]=w[i];
				circle[i+top]=circle[i];
			}
			top<<=1;
			dddl.insert(0,D[circle[0]]);
			sum+=w[0];
			for(int i=1;i<top;i++){
				dddl.pop(i-(top>>1));
				_ans=max(_ans,sum+dddl.ask()+D[circle[i]]);
				dddl.insert(i,D[circle[i]]-sum);
				sum+=w[i];
			}
			ans+=_ans;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
