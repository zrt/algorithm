#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
struct N{
	int x,y,to;
	N(int a=0,int b=0,int c=0){
		x=a,y=b,to=c;
	}
};
queue<N> q;
int n;
char s[105][105];
int d[105][105][4];
//    0
//  1   2
//    3
int xk[]={-1,0,0,1};
int yk[]={0,-1,1,0};
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s[i]);
	}
	N start,end;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(s[i][j]=='A'){
				start.x=i;
				start.y=j;
				s[i][j]='.';
			}else if(s[i][j]=='B'){
				end.x=i;end.y=j; 
				s[i][j]='.';
			}
		}
	}
	memset(d,0x3f,sizeof d);
	for(int i=0;i<4;i++) q.push(N(start.x,start.y,i)),d[start.x][start.y][i]=0;
	while(!q.empty()){
		N t=q.front();q.pop();
		for(int i=0;i<4;i++){
			if(d[t.x][t.y][i]>d[t.x][t.y][t.to]+1){
				d[t.x][t.y][i]=d[t.x][t.y][t.to]+1;
				q.push(N(t.x,t.y,i));
			}
		}
		int x=xk[t.to]+t.x;
		int y=yk[t.to]+t.y;
		if(x>=0&&x<n&&y>=0&&y<n){
			if(s[x][y]=='x') continue;
			if(d[x][y][t.to]>d[t.x][t.y][t.to]){
				d[x][y][t.to]=d[t.x][t.y][t.to];
				q.push(N(x,y,t.to));
			}
		}
		
	}
	int ans=inf;
	for(int i=0;i<4;i++){
		ans=min(ans,d[end.x][end.y][i]);
	}
	printf("%d\n",ans);
	return 0;
}
