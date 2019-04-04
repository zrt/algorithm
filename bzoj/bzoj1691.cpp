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
struct N{
	int a,b;//qian xian
	friend bool operator < (N a,N b){
		return a.a<b.a;
	}
}a[100005],b[100005];
bool cmp(N a,N b){
	return a.b>b.b;
}
multiset<int> s;
multiset<int>::iterator it;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a[i].a,&a[i].b);
	}
	for(int i=0;i<m;i++){
		scanf("%d%d",&b[i].a,&b[i].b);
	}
	sort(a,a+n,cmp);
	sort(b,b+m,cmp);
	int j=0;
	bool ok=1;
	LL ans=0;
	for(int i=0;i<n;i++){
		while(j<m&&b[j].b>=a[i].b) s.insert(b[j].a),j++;
		it=s.lower_bound(a[i].a);
		if(it==s.end()){
			ok=0;break;
		}else{
			ans+=*it;
			s.erase(it);
		}
	}
	if(ok)printf("%lld\n",ans);
	else puts("-1");
	return 0;
}
