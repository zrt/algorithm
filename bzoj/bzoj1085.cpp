/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
#include<algorithm>
//by zrt
//problem:
using namespace std;
char s[5][10];
int T;
int _max;
int xk[]={1,1,-1,-1,2,2,-2,-2};
int yk[]={2,-2,2,-2,1,-1,1,-1};
int possible(){
	int cnt=0;
	for(int i=0;i<2;i++){
		for(int j=i;j<5;j++){
			if(s[i][j]!='1') cnt++;
		}
		for(int j=0;j<i;j++){
			if(s[i][j]!='0') cnt++;
		}
	}
	for(int i=2;i<4;i++){
		for(int j=i+1;j<5;j++){
			if(s[i][j]!='1') cnt++;
		}
		for(int j=0;j<=i;j++){
			if(s[i][j]!='0') cnt++;
		}
	}
	if(s[2][2]=='*') cnt--;
	for(int j=0;j<5;j++) if(s[4][j]!='0') cnt++;
	return cnt;
}
bool dfs(int X,int px,int py){
//	printf("%d %d %d\n",X,px,py);
	if(X==_max&&px==2&&py==2){
		for(int i=0;i<2;i++){
			for(int j=i;j<5;j++){
				if(s[i][j]!='1') goto fas;
			}
		}
		for(int i=2;i<4;i++){
			for(int j=i+1;j<5;j++){
				if(s[i][j]!='1') goto fas;
			}
		}
		return true;
	}
	fas:;
	if(X!=_max){
		int x,y;
		for(int i=0;i<8;i++){
			x=px+xk[i];
			y=py+yk[i];
			if(x>=0&&y>=0&&x<5&&y<5){
				swap(s[x][y],s[px][py]);
				if(possible()+X<=_max){
					if(dfs(X+1,x,y)) return true;
				}
				swap(s[x][y],s[px][py]);
			}
		}
	}
	return false;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&T);
	while(T--){
		for(int i=0;i<5;i++) scanf("%s",s[i]);
		int sx,sy;
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				if(s[i][j]=='*'){
					sx=i;sy=j;break;
				}
			}
		}
		for(int i=0;i<=15;i++){
			_max=i;
			if(dfs(0,sx,sy)){
				printf("%d\n",i);goto ed;
			}
		}
		puts("-1");
		ed:;
	}
	return 0;
}
