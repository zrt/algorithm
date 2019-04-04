#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int H[300005],X[600005],P[600005],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int f[300005];
int k;
void dfs(int x,int fa){
	f[x]=0;
	for(int i=H[x];i;i=X[i]){
		if(P[i]!=fa){
			dfs(P[i],x);
			f[x]+=f[P[i]];
		}
	}
	
//	printf("%d %d\n",x,f[x]);
	f[x]=max(f[x]-k,0);
	f[x]++;
//	printf("%d %d\n",x,f[x]);
}
bool judge(int x){
	k=x;
//	printf("### %d\n",x);
	dfs(1,0);
	if(f[1]==1) return 1;
	else return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	int l=-1,r=n+1;
	while(r-l>1){
		int mid=(l+r)>>1;
		if(judge(mid)) r=mid;
		else l=mid;
	}
	printf("%d\n",r);
	return 0;
}
