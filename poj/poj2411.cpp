#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int H[6000],X[5000000],P[5000000],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int _x;int n,m;
/*
void dfs(int x,int nw){
	if(x==n){
		add(_x,nw);
	}
	if(x>n) return;
	int q=_x>>x;
	if((q&1)==0) dfs(x+1,nw+1<<(x));
	if((q&3)==0) dfs(x+2,nw);
	if((q&1)!=0) dfs(x+1,nw);
}*/
void find(int p,int x,int now,int t)
{
	if(x==n+1)
	{
		add(p,t);
		return;
	}
	if(x>n) return;
	if((now&1)==0) find(p,x+1,now>>1,t+(1<<(x-1)));
	if((now&3)==0) find(p,x+2,now>>2,t);
	if((now&1)!=0) find(p,x+1,now>>1,t);
}
long long f[13][6000];
int main(){
	while(scanf("%d%d",&n,&m)&&(n||m)){
		if(n>m) swap(n,m);
		memset(f,0,sizeof f);
		memset(H,0,sizeof H);tot=0;
		for(int i=0;i<1<<n;i++){
			find(i,1,i,0);
		}
		f[0][0]=1;
		for(int i=0;i<m;i++){
			for(int j=0;j<1<<n;j++){
				if(f[i][j]){
					for(int k=H[j];k;k=X[k]){
						f[i+1][P[k]]+=f[i][j];
					}
				}
			}
		}
		printf("%lld\n",f[m][0]);
	}
	return 0;
}
//1699 1038