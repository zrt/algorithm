#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
char s[2005][10];
int dis[2005][2005];
int ans;
struct N{
	int x,w;
	N(int a=0,int b=0){
		x=a,w=b;
	}
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
}t;
bool vis[2005];
int d[2005];
priority_queue<N> q;
int main(){
	int n;
	while(scanf("%d",&n)==1&&n){
		memset(vis,0,sizeof vis);
		memset(d,0x7f,sizeof d);
		for(int i=0;i<n;i++) scanf("%s",s[i]);
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int c=0;
				for(int k=0;k<7;k++){
					if(s[i][k]!=s[j][k]) c++;
				}
				dis[i][j]=dis[j][i]=c;
			}
		}
		ans=0;
		q.push(N(0,0));
		while(!q.empty()){
			t=q.top();q.pop();
			if(vis[t.x]) continue;
			else vis[t.x]=1;
			ans+=t.w;
			for(int i=0;i<n;i++){
				if(!vis[i]){
					if(dis[t.x][i]<d[i]){
						d[i]=dis[t.x][i];
						q.push(N(i,dis[t.x][i]));
					}
				}
			}
		}
		printf("The highest possible quality is 1/%d.\n",ans);
	}
	
	return 0;
}