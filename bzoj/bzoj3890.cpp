#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<queue>
using namespace std;
int n,m;
bitset<10005> a[105],b[105];
int H[105],X[10005],P[10005],tot,E1[10005],E2[10005];
int in[105];
inline void add(int x,int y,int z,int k){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E1[tot]=z;E2[tot]=k;in[y]++;
}
queue<int> q;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0,x,y,a,b;i<m;i++){
		scanf("%d%d%d%d",&x,&y,&a,&b);
		add(x,y,a,b);
	}
	for(int i=1;i<=n;i++){
		if(!in[i]) q.push(i);
	}
	a[1][0]=1;b[1][0]=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			in[P[i]]--;
			if(!in[P[i]]) q.push(P[i]);
			a[P[i]]=a[P[i]]|(a[x]<<E1[i]);
			b[P[i]]=b[P[i]]|(b[x]<<E2[i]);
		}
	}
	bool ok=1;
	for(int i=0;i<=10000;i++){
		if(a[n][i]&b[n][i]){
			printf("%d\n",i);
			ok=0;break;
		}
	}
	if(ok){
		puts("IMPOSSIBLE");
	}
	return 0;
}
