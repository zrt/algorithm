#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps(1e-10);
int n,m;
int H[1005],X[2010],P[2010],tot;
void add(int x,int y){
	P[++tot]=y,X[tot]=H[x],H[x]=tot;
}
int link[1005];bool cover[1005];
bool f(int x){
	for(int i=H[x];i;i=X[i]){
		if(!cover[P[i]]){
			int q=link[P[i]];
			link[P[i]]=x;
			cover[P[i]]=1;
			if(q==-1){
				return 1;
			}
			if(f(q)) return 1;
			link[P[i]]=q;
		}
	}
	return 0;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(x!=y) add(i,x),add(i,y);
		else add(i,x);
	}
	int cnt=0;
	memset(link,-1,sizeof link);
	for(int i=1;i<=m;i++){
		memset(cover,0,sizeof cover);
		if(f(i)){
			cnt++;
		}else break;
	}
	printf("%d\n",cnt);
	return 0;
}
