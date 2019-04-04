#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps=1e-9;
int H[505],P[10005],X[10005],tot;
int n,k;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
bool cover[505];
int link[505];
int ans;
bool find(int k){
	for(int i=H[k];i;i=X[i]){
		if(!cover[P[i]]){
			int q=link[P[i]];
			link[P[i]]=k;
			cover[P[i]]=1;
			if(q==-1){
				ans++;return true;
			}
			if(find(q)) return true;
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
	scanf("%d%d",&n,&k);
	for(int i=0,x,y;i<k;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	memset(link,-1,sizeof link);
	for(int i=1;i<=n;i++){
		memset(cover,0,sizeof cover);
		find(i);
	}
	printf("%d\n",ans);
	return 0;
}
