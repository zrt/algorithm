/*
ID: zrtdrea1
PROG:
LANG: C++
*/
#include<cstdio>
//by zrt
//problem:
using namespace std;
struct N{
	int x,y;
	N(int a=0,int b=0){
		x=a,y=b;
	}
};
N f[100005][2];
int T,n,x,y,m;
N get(N x){
	if(x.x==f[x.x][x.y].x){
		return x;
	}else{
		return f[x.x][x.y]=get(f[x.x][x.y]);
	}
}
char s[10];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) f[i][0].x=i,f[i][0].y=0,f[i][1].x=i,f[i][1].y=1;
		for(int i=0;i<m;i++){
			scanf("%s%d%d",s,&x,&y);
			if(s[0]=='A'){
				N tmpa,tmpb;
				tmpa=get(N(x,0));
				tmpb=get(N(y,0));
				if(tmpa.x==tmpb.x){
					if(tmpa.y==tmpb.y){
						puts("In the same gang.");
					}else puts("In different gangs.");
				}else{
					puts("Not sure yet.");
				}
			}else{
				N tmpa,tmpb;
				tmpa=get(N(x,0));
				tmpb=get(N(y,1));
				f[tmpa.x][tmpa.y]=N(tmpb.x,tmpb.y);
				tmpa=get(N(x,1));
				tmpb=get(N(y,0));
				f[tmpa.x][tmpa.y]=N(tmpb.x,tmpb.y);
			}
		}
		
	}
	return 0;
}
