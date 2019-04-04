#include<iostream>
#include<cstdio>
#include<cstring>
//by zrt
//problem:
using namespace std;
int H[104],P[10005],X[10005],E[10005],tot;
bool vis[104];
int d[104],T,x,y,z,cnt[104];
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&T);
	while(T--){
		memset(H,0,sizeof H);tot=0;memset(d,0x7f,sizeof d);
		memset(vis,0,sizeof vis);
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);add(y,x,z);
		}
		int ans=0;
		d[1]=0;cnt[1]=1;
		for(int i=0;i<n;i++){
			int minn=0x7f7f7f7f,minx,_cnt;
			for(int i=1;i<=n;i++){
				if(vis[i]) continue;
				if(d[i]<minn){
					minn=d[i];minx=i;_cnt=cnt[i];
				}
			}
			if(_cnt>1) goto fas;
			ans+=minn;
			for(int i=H[minx];i;i=X[i]){
				if(vis[P[i]]) continue;
				if(d[P[i]]>E[i]){
					d[P[i]]=E[i];
					cnt[P[i]]=1;
				}else if(d[P[i]]==E[i]){
					cnt[P[i]]++;
				}
			}
			vis[minx]=1;
		}
		if(0){
			fas:;puts("Not Unique!");
		}else printf("%d\n",ans);
	}
	return 0;
}
