#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps(1e-10);
int R,C,n;
char s[60][60];
int link[1005];
int cover[1005];
int H[1005],X[1000050],P[1000050],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
bool find(int x){
	for(int i=H[x];i;i=X[i]){
		if(cover[P[i]]) continue;
		cover[P[i]]=1;
		int q=link[P[i]];
		link[P[i]]=x;
		if(q==-1||find(q)) return 1;
		link[P[i]]=q;
	}
	return 0;
}
int xn,yn;
int a[60][60],b[60][60];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	memset(link,-1,sizeof link);
	scanf("%d%d",&R,&C);
	for(int i=0;i<R;i++){
		scanf("%s",s[i]);
	}
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(s[i][j]=='*'){
				if(j>0&&s[i][j-1]=='*'){
					a[i][j]=a[i][j-1];
				}else a[i][j]=++yn;
				if(i>0&&s[i-1][j]=='*'){
					b[i][j]=b[i-1][j];
				}else b[i][j]=++xn;
			}
		}
	}
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(s[i][j]=='*'){
					add(a[i][j],b[i][j]);
			}
		}
	}
	n=yn;
	int ans(0);
	for(int i=1;i<=n;i++){
		memset(cover,0,sizeof cover);
		if(find(i)) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
