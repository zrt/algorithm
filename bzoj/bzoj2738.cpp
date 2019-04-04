#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n,q;
int a[505][505];
struct Q{
    int x1,y1,x2,y2,k;
}Q[65000];
bool solved[65000];
int ans[65000];
struct N{
    int x,y,w;
    friend bool operator < (N a,N b){
        return a.w<b.w;
    }
}b[505*505];
int c[505][505];
int sum[505][505];
int main(){
    scanf("%d%d",&n,&q);
    int size=2.0*n*n/sqrt(q);
    for(int i=1,t;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&t);
            b[(i-1)*n+j].x=i;
            b[(i-1)*n+j].y=j;
            b[(i-1)*n+j].w=t;
        }
    }
    for(int i=0;i<q;i++){
        scanf("%d%d%d%d%d",&Q[i].x1,&Q[i].y1,&Q[i].x2,&Q[i].y2,&Q[i].k);
    }
    sort(b+1,b+n*n+1);
    for(int i=1;i<=n*n;i+=size){
		for(int j=0;j<size;j++){
			if(i+j>n*n) continue;
			c[b[i+j].x][b[i+j].y]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+c[i][j];
			}
		}
		for(int j=0;j<q;j++){
			if(!solved[j]){
			if(sum[Q[j].x2][Q[j].y2]-sum[Q[j].x1-1][Q[j].y2]-sum[Q[j].x2][Q[j].y1-1]+sum[Q[j].x1-1][Q[j].y1-1]>=Q[j].k){
					
					solved[j]=1;
					int num=sum[Q[j].x2][Q[j].y2]-sum[Q[j].x1-1][Q[j].y2]-sum[Q[j].x2][Q[j].y1-1]+sum[Q[j].x1-1][Q[j].y1-1]-Q[j].k;
					for(int k=size-1;k>=0;k--){
						if(i+k>n*n) continue;
						if(b[i+k].x>=Q[j].x1&&b[i+k].x<=Q[j].x2&&b[i+k].y>=Q[j].y1&&b[i+k].y<=Q[j].y2){
							num--;
							if(num<0){
								ans[j]=b[i+k].w;
								break;
							}
						}
					}
				}
			}
		}
    }
    for(int i=0;i<q;i++){
		printf("%d\n",ans[i]);
    }
    return 0;
}
