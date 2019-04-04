#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long LL ;
const double eps(1e-10) ;
const int inf(0x3f3f3f3f) ;
int n,t,s,e;
struct N{
	int x,y,z;
}a[105];
int to[1005];
set<int> S;
int siz;
int mul[205][205];
int map[205][205];
void p(int a[][205],int b[][205]){
	static int c[205][205];
	memset(c,0x3f,sizeof c);
	for(int i=1;i<=siz;i++){
		for(int j=1;j<=siz;j++){
			for(int k=1;k<=siz;k++){
				c[i][j]=min(a[i][k]+b[k][j],c[i][j]);
			}
		}
	}
	memcpy(a,c,sizeof map);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d%d%d%d",&n,&t,&s,&e);
	S.insert(s);S.insert(e);
	for(int i=0;i<t;i++){
		scanf("%d%d%d",&a[i].z,&a[i].x,&a[i].y);
		S.insert(a[i].x);S.insert(a[i].y);
	}
	for(set<int>::iterator it=S.begin();it!=S.end();++it){
		to[*it]=++siz;
	}
	memset(map,0x3f,sizeof map);
	for(int i=0;i<t;i++){
		map[to[a[i].y]][to[a[i].x]]=map[to[a[i].x]][to[a[i].y]]=min(map[to[a[i].x]][to[a[i].y]],a[i].z);
	}
	memcpy(mul,map,sizeof map);
	int k=n-1;
	while(k){
		if(k&1) p(map,mul);
		p(mul,mul);
		k>>=1;
	}
	printf("%d\n",map[to[s]][to[e]]);
	return 0 ;
}
