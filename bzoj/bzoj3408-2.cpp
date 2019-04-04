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
queue<int> q;
int H[2505],X[13000],P[13000],E[13000],tot;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
int n,m,s,t;
int d[2505];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=0,x,y,z;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);add(y,x,z);
	}
	memset(d,0x3f,sizeof d);
	d[s]=0;
	q.push(s);
	int x;
	while(!q.empty()){
		x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			if(d[P[i]]>d[x]+E[i]){
				d[P[i]]=d[x]+E[i];
				q.push(P[i]);
			}
		}
	}
	printf("%d\n",d[t]);
	return 0;
}
