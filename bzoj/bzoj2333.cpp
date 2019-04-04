#include<bits/stdc++.h>
using namespace std;
int f[300005];
int n;
int get(int x){
	return f[x]==x?x:f[x]=get(f[x]);
}
int w[300005];
int ls[300005],rs[300005],mx[300005];
int add[300005];
bool del[300005];
int t[300005];
int fa[300005];
int _add;
struct N{
	int x,t,w;
	N(int a=0,int c=0,int b=0){
		x=a,w=b;t=c;
	}
	friend bool operator < (const N&a,const N&b){
		return a.w<b.w;
	}
};
priority_queue<N> MAX;
char s[10];
int lis[300005],tot;
void up(int x){
	mx[x]=max(w[x],max(mx[ls[x]],mx[rs[x]]));
}
void down(int x){
	if(add[x]){
		//ls
		if(ls[x]){
			add[ls[x]]+=add[x];
			w[ls[x]]+=add[x];
			mx[ls[x]]+=add[x];
		}
		//rs
		if(rs[x]){
			add[rs[x]]+=add[x];
			w[rs[x]]+=add[x];
			mx[rs[x]]+=add[x];
		}
		add[x]=0;
	}
}
int merge(int x,int y){
	if(!x) return y;
	if(!y) return x;
	if(rand()&1) swap(x,y);
	// y-> x
	down(x);
	if(rand()&1){
		ls[x]=merge(ls[x],y);
		fa[ls[x]]=x;
	}else{
		rs[x]=merge(rs[x],y);
		fa[rs[x]]=x;
	}
	up(x);
	return x;
}
int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	srand(401794301);
	scanf("%d",&n);
	mx[0]=-0x3f3f3f3f;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=n;i++) scanf("%d",&w[i]),mx[i]=w[i];
	for(int i=1;i<=n;i++){
		MAX.push(N(i,0,mx[i]));
	}
	int q;
	scanf("%d",&q);
	while(q--){
		scanf("%s",s);
		int u,v,x;
		if(s[0]=='A'){
			if(s[1]=='1'){
				scanf("%d%d",&x,&v);
				tot=0;
				while(x) lis[tot++]=x,x=fa[x];
				for(int i=tot-1;i>=0;i--) down(lis[i]);
				x=lis[0];
				w[x]+=v;
				for(int i=0;i<tot;i++) up(lis[i]);
				x=lis[tot-1];
				t[x]++;
				MAX.push(N(x,t[x],mx[x]));
			}else if(s[1]=='2'){
				scanf("%d%d",&v,&x);
				v=get(v);
				mx[v]+=x;
				add[v]+=x;
				w[v]+=x;
				t[v]++;
				MAX.push(N(v,t[v],mx[v]));
			}else{
				scanf("%d",&x);
				_add+=x;
			}
		}else if(s[0]=='F'){
			if(s[1]=='1'){
				scanf("%d",&x);
				tot=0;
				while(x) lis[tot++]=x,x=fa[x];
				for(int i=tot-1;i>=0;i--) down(lis[i]);
				printf("%d\n",w[lis[0]]+_add);
			}else if(s[1]=='2'){
				scanf("%d",&x);
				x=get(x);
				printf("%d\n",mx[x]+_add);
			}else{
				while(del[MAX.top().x]||t[MAX.top().x]!=MAX.top().t) MAX.pop();
				printf("%d\n",MAX.top().w+_add);
			}
		}else{
			scanf("%d%d",&u,&v);
			if(get(u)==get(v)) continue;
			u=get(u);
			v=get(v);
			if(rand()&1) swap(u,v);
			f[u]=v;
			del[u]=1;
			down(v);
			if(rand()&1) ls[v]=merge(u,ls[v]),fa[ls[v]]=v;
			else rs[v]=merge(u,rs[v]),fa[rs[v]]=v;
			up(v);
			t[v]++;
			MAX.push(N(v,t[v],mx[v]));
		}
	}
	return 0;
}
