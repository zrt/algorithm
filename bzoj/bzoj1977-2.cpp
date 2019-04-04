#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include<queue>
//by zrt
//problem:
using namespace std;
const long long inf(0x3f3f3f3f3f3f3f3f) ;
const double eps(1e-10) ;
typedef long long LL;
LL n,m;
struct N{
	LL x,y,z;
}a[300005];
LL f[100005];
bool cmp(N a,N b){
	return a.z<b.z;
}
LL get(LL x){
	return f[x]==x?x:f[x]=get(f[x]);
}
bool mark[300005];
struct P{
	LL x,w;
	P(LL a=0,LL b=0){
		x=a,w=b;
	}
};
queue<LL> q;
vector<P> v[100005];
bool vis[100005];
LL anc[100005][25];
LL log;
LL dep[100005];
LL maxx[100005][25];
LL max2[100005][25];
void dfs(){
	LL x;
	q.push(1);
	while(!q.empty()){
		x=q.front();q.pop();
		vis[x]=1;
		LL siz=v[x].size();
		for(LL i=0;i<siz;i++){
			if(!vis[v[x][i].x]){
				anc[v[x][i].x][0]=x;
				dep[v[x][i].x]=dep[x]+1;
				maxx[v[x][i].x][0]=v[x][i].w;
				q.push(v[x][i].x);
			}
		}
	}
}
LL ask(LL x,LL y){
	if(dep[x]>dep[y]) swap(x,y);
	//dep[x]<dep[y]
	LL ans=0;
	for(LL i=log;i>=0;i--){
		if(dep[y]-(1<<i)>=dep[x]){
			ans=max(ans,maxx[y][i]);
			y=anc[y][i];
		}
	}
	if(x==y) return ans;
	for(LL i=log;i>=0;i--){
		if(anc[x][i]!=anc[y][i]){
			ans=max(ans,max(maxx[x][i],maxx[y][i]));
			x=anc[x][i];y=anc[y][i];
		}
	}
	return max(ans,max(maxx[x][0],maxx[y][0]));
}
LL askcida(LL x,LL y,LL max1){
	if(dep[x]>dep[y]) swap(x,y);
	//dep[x]<dep[y]
	LL ans=0;
	for(LL i=log;i>=0;i--){
		if(dep[y]-(1<<i)>=dep[x]){
			LL tmp=ans;
			ans=max(ans,maxx[y][i]);
			if(ans==max1) ans=tmp;
			tmp=ans;
			ans=max(ans,max2[y][i]);
			if(ans==max1) ans=tmp;
			y=anc[y][i];
		}
	}
	if(x==y) return ans;
	for(LL i=log;i>=0;i--){
		if(anc[x][i]!=anc[y][i]){
			LL tmp=ans;
			ans=max(ans,maxx[y][i]);
			if(ans==max1) ans=tmp;
			tmp=ans;
			ans=max(ans,max2[y][i]);
			if(ans==max1) ans=tmp;
			tmp=ans;
			ans=max(ans,maxx[x][i]);
			if(ans==max1) ans=tmp;
			tmp=ans;
			ans=max(ans,max2[x][i]);
			if(ans==max1) ans=tmp;
			x=anc[x][i];y=anc[y][i];
		}
	}
	LL tmp=ans;
	ans=max(ans,maxx[y][0]);
	if(ans==max1) ans=tmp;
	tmp=ans;
	ans=max(ans,max2[y][0]);
	if(ans==max1) ans=tmp;
	tmp=ans;
	ans=max(ans,maxx[x][0]);
	if(ans==max1) ans=tmp;
	tmp=ans;
	ans=max(ans,max2[x][0]);
	if(ans==max1) ans=tmp;
	return ans;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%lld%lld",&n,&m);
//	memset(max2,0x3f,sizeof max2);
	for(log=0;1<<log<=n;log++);log--;
	for(LL i=1;i<=n;i++) f[i]=i;
	for(LL i=0;i<m;i++){
		scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
	}
	LL tot=1;
	sort(a,a+m,cmp);
	LL sum=0;
	for(LL i=0;i<m;i++){
		if(get(a[i].x)!=get(a[i].y)){
			mark[i]=1;
			sum+=a[i].z;
			tot++;
			v[a[i].x].push_back(P(a[i].y,a[i].z));
			v[a[i].y].push_back(P(a[i].x,a[i].z));
			f[get(a[i].x)]=get(a[i].y);
			if(tot==n) break;
		}
	}
	dep[1]=1;
	dfs();
//	for(LL i=1;i<=n;i++){
//		printf("%d ",anc[i][0]);
//	}
//	printf("%d\n",sum);
	for(LL i=0;i<=log;i++){
		for(LL j=1;j<=n;j++){
			if(anc[j][i]&&anc[anc[j][i]][i]){
				anc[j][i+1]=anc[anc[j][i]][i];
				LL tmp= max(maxx[j][i],maxx[anc[j][i]][i]);
				LL tmp2;
				tmp2=min(maxx[j][i],maxx[anc[j][i]][i]);
				if(tmp2==tmp) tmp2=inf;
				tmp2=max(tmp2,max(max2[j][i],max2[anc[j][i]][i]));
				maxx[j][i+1]=tmp;
				max2[j][i+1]=tmp2;
			}
		}
	}
	LL ret=inf;
	for(LL i=0;i<m;i++){
		if(!mark[i]){
			LL kkkk=ask(a[i].x,a[i].y);
			LL tmp=sum+a[i].z-kkkk;
			if(tmp>sum&&tmp<ret) ret=tmp;
			tmp=sum+a[i].z-askcida(a[i].x,a[i].y,kkkk);
			if(tmp>sum&&tmp<ret) ret=tmp;
	//		ret=min(ret,max(,sum));
		}
	}
	printf("%lld\n",ret);
	return 0;
}
