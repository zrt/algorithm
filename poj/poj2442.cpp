#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int T;
int m,n;
struct N{
	int i,j,w;
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
	N(int a=0,int b=0,int c=0){
		i=a,j=b,w=c;
	}
}t;
priority_queue<N> q;
int num[105][2005];
int a[2050],b[2050];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&m,&n);
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&num[i][j]);
			}
		}
		sort(num[0],num[0]+n);
		for(int i=0;i<n;i++) a[i]=num[0][i];
		for(int i=1;i<m;i++){
			while(!q.empty()) q.pop();
			sort(num[i],num[i]+n);
			for(int j=0;j<n;j++){
				q.push(N(j,0,num[i][0]+a[j]));
			}
			for(int j=0;j<n;j++){
				b[j]=(t=q.top()).w;q.pop();
				if(t.j<n-1){
					q.push(N(t.i,t.j+1,a[t.i]+num[i][t.j+1]));
				}
			}
			for(int j=0;j<n;j++) a[j]=b[j];
		}
		printf("%d",a[0]);
		for(int i=1;i<n;i++) printf(" %d",a[i]);
		puts("");
	}
	return 0;
}