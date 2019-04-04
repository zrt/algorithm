/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps=1e-9;
int H[130],P[10005],X[10005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int ans;
bool cover[130];
int link[130];
bool find(int k){
	for(int i=H[k];i;i=X[i]){
		if(!cover[P[i]]){
			int q=link[P[i]];
			link[P[i]]=k;
			cover[P[i]]=1;
			if(q==-1){
				ans++;return 1;
			}
			if(find(q)) return 1;
			link[P[i]]=q;
		}
	}
	return false;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int tt;
	scanf("%d",&tt);
	while(tt--){
		int n,m;
		memset(H,0,sizeof H);
		ans=tot=0;
		scanf("%d%d",&n,&m);
		for(int i=0,x,y;i<m;i++){
			scanf("%d%d",&x,&y);
			add(x,y);
		}
		memset(link,-1,sizeof link);
		for(int i=1;i<=n;i++) {
			memset(cover,0,sizeof cover);
			find(i);
		}
		printf("%d\n",n-ans);
	}
	
	return 0;
}
