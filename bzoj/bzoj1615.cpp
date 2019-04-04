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
int n,xt,yt;
int x[1055],y[1055],r[1055];
double s[1055];
int H[1055],X[1000005],P[1000005],tot;
int pre[1055];
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
queue<int> q;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d",&n,&xt,&yt);
	int oo,to;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&x[i],&y[i],&r[i]);
		if(x[i]==0&&y[i]==0){
			oo=i;
			s[oo]=10000;
		}
		if(x[i]==xt&&y[i]==yt){
			to=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])==(r[i]+r[j])*(r[i]+r[j])){
				add(i,j);
				add(j,i);
			}
		}
	}
	memset(pre,-1,sizeof pre);
	q.push(oo);
	int x;
	while(!q.empty()){
		x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			if(pre[P[i]]!=-1) continue;
			pre[P[i]]=x;
			s[P[i]]=s[x]*1LL*r[x]/r[P[i]];
			q.push(P[i]);
		}
	}
	int k=to;
	double ans=0;
	while(k!=oo){
		ans+=s[k];
		k=pre[k];
	}
	printf("%d\n",(int)(ans+s[oo]));
	return 0;
}
