#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int m,b,H,n;
int c[55][50005];
int a[50005];
int h[55];
int now;
int p[50005];
bool cmp(int x,int y){
	return c[0][x]-c[now][x]<c[0][y]-c[now][y];
}
int calc(int x){
	now=x;
	sort(p+1,p+m+1,cmp);
	int ret=0,tmp=0;
	for(int i=1;i<=m;i++){
		if(tmp<b){
			int r=min(b-tmp,a[p[i]]);
			tmp+=r;
			ret+=r*c[0][p[i]]+(a[p[i]]-r)*c[x][p[i]];
		}else{
			ret+=a[p[i]]*c[x][p[i]];
		}
	}
	return ret+H+h[x];
}
int main(){
	scanf("%d%d%d%d",&m,&b,&H,&n);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&h[i]);
	}
	for(int i=0;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&c[i][j]);
		}
	}
	for(int i=1;i<=m;i++) p[i]=i;
	int ans=0x3f3f3f3f,tmp,pos;
	for(int i=1;i<=n;i++){
		tmp=calc(i);
		if(tmp<ans){
			pos=i;ans=tmp;
		}
	}
	printf("%d\n%d\n",pos,ans);
	return 0;
}
