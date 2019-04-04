#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int f[100005];
int n,c;
struct N{
	int x,y,id;
	friend bool operator < (N a,N b){
		if(a.y!=b.y) return a.y<b.y;
		return a.id<b.id;
	}
}a[100005];
int get(int x){
	return x==f[x]?x:f[x]=get(f[x]);
}
int sum[100005];
bool root[100005];
set<N> s;
bool cmp(N a,N b){
	return a.x<b.x;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&c);
	for(int i=1,x,y;i<=n;i++){
		scanf("%d%d",&x,&y);
		a[i].x=x+y;a[i].y=x-y;
		a[i].id=i;
	}
	for(int i=1;i<=n;i++) f[i]=i,sum[i]=1;
	sort(a+1,a+n+1,cmp);
	int j=1;
	set<N>::iterator it;
	for(int i=1;i<=n;i++){
		while(abs(a[j].x-a[i].x)>c) s.erase(a[j]),j++;
		s.insert(a[i]);
		it=s.upper_bound(a[i]);
		if(it!=s.end()){
			if(abs((*it).y-a[i].y)<=c){
				if(get((*it).id)!=get(a[i].id)){
					sum[get((*it).id)]+=sum[get(a[i].id)];
					f[get(a[i].id)]=get((*it).id);
				}
			}
		}
		--it;
		if(it!=s.begin()){
			--it;
			if(abs((*it).y-a[i].y)<=c){
				if(get((*it).id)!=get(a[i].id)){
					sum[get((*it).id)]+=sum[get(a[i].id)];
					f[get(a[i].id)]=get((*it).id);
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++) root[get(i)]=1;
	c=0;
	int maxx=-inf;
	for(int i=1;i<=n;i++){
		if(root[i]){
			c++;
			maxx=max(maxx,sum[i]);
		}
	}
	printf("%d %d\n",c,maxx);
	return 0;
}
