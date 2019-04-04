#include <cstdio>
#include <cstring>
#include <algorithm>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long ll ;
const double eps(1e-10) ;
const int inf(0x3fffffff) ;
int r,c,D;
char s[25][25];
char has[25][25];
int H[62500],X[625000],P[625000],flow[625000],tot;
int S,T;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;flow[tot]=z;
}
int d[62500];
int cur[62500];
#include<queue>
queue<int> q;
bool bfs(){
	memset(d,0,sizeof d);
	d[S]=1;q.push(S);
	int k;
	while(!q.empty()){
		k=q.front();q.pop();
		for(int i=H[k];i;i=X[i]){
			if(flow[i]>0&&!d[P[i]]){
				d[P[i]]=d[k]+1;
				q.push(P[i]);
			}
		}
	}
	return d[T];
}
int dfs(int x,int a){
	if(x==T||a==0) return a;
	int f=a,tmp;
//	if(cur[x]==-1) cur[x]=H[x];
	for(int i=H[x];i;i=X[i]){
		if(d[P[i]]==d[x]+1&&flow[i]>0){
			tmp=dfs(P[i],min(a,flow[i]));
			flow[i]-=tmp;
			flow[i^1]+=tmp;
			a-=tmp;
			if(!a) break;
		}
	}
	if(f==a) d[x]=-1;
	return f-a;
}
int Dinic(){
	int f=0;
	while(bfs()){
//		memset(cur,-1,sizeof cur);
		f+=dfs(S,inf);
	}
	return f;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	S=62499,T=62488;
	tot=1;
	scanf("%d%d%d",&r,&c,&D);
	for(int i=0;i<r;i++){
		scanf("%s",s[i]);
	}
	for(int i=0;i<r;i++){
		scanf("%s",has[i]);
	}
	int k=0;
	int sum=0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(s[i][j]!='0'){
				add(k<<1,k<<1|1,s[i][j]-'0');
				add(k<<1|1,k<<1,0);
				if(min(min(i+1,r-i),min(j+1,c-j))<=D){
					add(k<<1|1,T,inf);
					add(T,k<<1|1,0);
				}
			}
			if(has[i][j]=='L'){
				add(S,k<<1,1);
				add(k<<1,S,0);
				sum++;
			}
			
			k++;
		}
	}
	int d2=D*D;
	k=0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(s[i][j]=='0'){
				k++;continue;
			}
			int k2=0;
			for(int i2=0;i2<r;i2++){
				for(int j2=0;j2<c;j2++){
					if((i==i2&&j==j2)||s[i][j]=='0'){
						k2++;
						continue;
					}
					if((i-i2)*(i-i2)+(j-j2)*(j-j2)<=d2){
						add(k<<1|1,k2<<1,inf);
						add(k2<<1,k<<1|1,0);
			//			add(k2<<1|1,k<<1,inf);
			//			add(k<<1,k2<<1|1,0);
					}
					k2++;
				}
			}
			k++;
		}
	}
	printf("%d",sum-Dinic());
	return 0 ;
}
