#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,r;
int fa[1005],t[1005],c[1005];
double w[1005];
long long ans;
int main(){
	while(scanf("%d%d",&n,&r),n|r){
		memset(w,0,sizeof w);
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&c[i]);
			ans+=c[i];
			t[i]=1;
			w[i]=c[i];
		}
		memset(fa,0,sizeof fa);
		for(int i=1,x,y;i<n;i++){
			scanf("%d%d",&x,&y);
			fa[y]=x;
		}
		for(int tt=1;tt<n;tt++){
			int pos=0;
			double mx=-1;
			for(int i=1;i<=n;i++){
				if(i==r) continue;
				if(w[i]>mx){
					mx=w[i];
					pos=i;
				}
			}
			ans+=t[fa[pos]]*c[pos];
			w[pos]=0;
			c[fa[pos]]+=c[pos];
			t[fa[pos]]+=t[pos];
			w[fa[pos]]=c[fa[pos]]*1.0/t[fa[pos]];
			for(int i=1;i<=n;i++){
				if(fa[i]==pos){
					fa[i]=fa[pos];
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
