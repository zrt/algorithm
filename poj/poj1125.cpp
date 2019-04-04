#include<iostream>
#include<cstdio>
#include<vector>
//by zrt
//problem:
using namespace std;
int n,d[101][101],k,x,y; 
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%d",&n)==1&&n){
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) d[i][j]=2000;
		for(int i=1;i<=n;i++) d[i][i]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&k);
			for(int j=0;j<k;j++){
				scanf("%d%d",&x,&y);
				d[i][x]=y;
			}
		}
		for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
			d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		int minn=1<<30,maxx,pos;
		for(int i=1;i<=n;i++){
			maxx=0;
			for(int j=1;j<=n;j++){
				maxx=max(maxx,d[i][j]);
			}
			if(maxx<minn){
				pos=i;minn=maxx;
			}
		}
		printf("%d %d\n",pos,minn);
	}
	
	return 0;
}
