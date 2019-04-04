#include<cstdio>
#include<cstring>
using namespace std;
int a[10][10],x;
bool nine[3][3][10],hang[10][10],lie[10][10];
bool _ok;
char s[10][15];
inline void nxt(int& x,int& y){
	y++;
	if(y>=9){
		y=0;x++;
	}
}
void dfs(int x,int y){
	if(x==9&&y==0){
		_ok=1;return;
	}
	while(a[x][y]!=0) nxt(x,y);
	if(x==9&&y==0){
		_ok=1;return;
	}
	int xx=x/3,yy=y/3,xp=x,yp=y;
	nxt(xp,yp);
	for(int i=1;i<=9;i++){
		if(_ok) return;
		if(nine[xx][yy][i]||hang[x][i]||lie[y][i]) continue;
		nine[xx][yy][i]=1;hang[x][i]=1;lie[y][i]=1;
		a[x][y]=i;
		dfs(xp,yp);if(_ok) return;
		nine[xx][yy][i]=0;hang[x][i]=0;lie[y][i]=0;a[x][y]=0;
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(nine,0,sizeof nine);
		memset(hang,0,sizeof hang);
		memset(lie,0,sizeof lie);
		_ok=0;
		for(int i=0;i<9;i++) scanf("%s",s[i]);
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				a[i][j]=s[i][j]-'0';
				nine[i/3][j/3][a[i][j]]=1;
				hang[i][a[i][j]]=1;lie[j][a[i][j]]=1;
			}
		}
		dfs(0,0);
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				putchar('0'+a[i][j]);
			}
			putchar('\n');
		}
	}
	return 0;
}