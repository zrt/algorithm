#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
typedef unsigned long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int n,m,top;
LL a[150050];
int H[50005],X[200005],P[200005],tot,from[200005];
LL E[200005];
inline void add(int x,int y,LL z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;from[tot]=x;
}
bool vis[50005];
LL Xor[50005];
bool chose[200005];
void dfs(int x){
	vis[x]=1;
	for(int i=H[x];i;i=X[i]){
		if(!vis[P[i]]){
			chose[i]=1;
			chose[i^1]=1;
			Xor[P[i]]=Xor[x]^E[i];
			dfs(P[i]);
		}
	}
}
int pos[64];
void gaosixiaoyuan(){
	memset(pos,-1,sizeof pos);
	for(int i=0;i<top;i++){
		for(int j=i+1;j<top;j++){
			if(a[j]>a[i]) swap(a[j],a[i]);
		}
		if(!a[i]) break;
		for(int j=63;j>=0;j--){
			if(a[i]>>j&1){
				pos[j]=i;
				for(int k=0;k<top;k++){
					if(i!=k&&(a[k]>>j&1)) a[k]^=a[i];
				}
				break;
			}
		}
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	tot=1;
	for(int i=0,x,y;i<m;i++){
		LL z;
		scanf("%d%d%llu",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	dfs(1);
	for(int i=2;i<=tot;i+=2){
		if(!chose[i]){
			a[top++]=Xor[from[i]]^E[i]^Xor[P[i]];
		}
	}
	gaosixiaoyuan();
	LL aim=Xor[n];
	for(int i=63;i>=0;i--){
		if(!(aim>>i&1)&&~pos[i]){
			aim^=a[pos[i]];
		}
	}
	printf("%llu\n",aim);
	return 0;
}
