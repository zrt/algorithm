//逗比题
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q;
int w[100005];
int H[100005],X[200005],P[200005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int fa[100005];
int dep[100005];
void dfs(int x){
	dep[x]=dep[fa[x]]+1;
	for(int i=H[x];i;i=X[i]){
		if(P[i]!=fa[x]){
			fa[P[i]]=x;
			dfs(P[i]);
		}
	}
}
int list[60],num;
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	dfs(1);
	for(int i=0,t,a,b;i<q;i++){
		scanf("%d%d%d",&t,&a,&b);
		if(t){
			w[a]=b;
		}else{
			num=0;
			bool ok=0;
			if(dep[a]<dep[b]) swap(a,b);
			while(dep[a]>dep[b]){
				list[num++]=w[a];
				a=fa[a];
				if(num>47){
					ok=1;goto ed;
				}
			}
			while(a!=b){
				list[num++]=w[a];
				list[num++]=w[b];
				a=fa[a];b=fa[b];
				if(num>47){
					ok=1;goto ed;
				}
			}
			list[num++]=w[a];
			ed:;
			if(!ok){
				sort(list,list+num);
				for(int i=2;i<num;i++){
					if(list[i-2]+0LL+list[i-1]>list[i]){
						ok=1;break;
					}
				}
			}
			if(ok) puts("Y");else puts("N");
		}
	}
	
	
	return 0;
}
