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
int tt;
int n,s,t;
double leng1,leng2,sum;
double x[1005],y[1005];
int d[1005];
queue<int> q;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&tt);
	while(tt--){
		scanf("%d%d%d%lf%lf",&n,&s,&t,&leng1,&leng2);
		sum=leng1+leng2;
		sum=sum*sum;
		for(int i=1;i<=n;i++){
			scanf("%lf%lf",&x[i],&y[i]);
		}
		memset(d,0,sizeof d);
		d[s]=1;
		while(!q.empty()) q.pop();
		q.push(s);
		int u;
		while(!q.empty()){
			u=q.front();q.pop();
			if(u==t) break;
			for(int i=1;i<=n;i++){
				if(!d[i]&&sum>=(x[i]-x[u])*(x[i]-x[u])+(y[i]-y[u])*(y[i]-y[u])){
					d[i]=d[u]+1;
					q.push(i);
					if(i==t) break;
				}
			}
		}
		if(d[t])printf("%d\n",d[t]-1);
		else puts("Impossible");
	}
	
	return 0;
}
