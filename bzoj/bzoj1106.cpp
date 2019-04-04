#include<cstdio>
#include<cstring>
#include<algorithm>
#define lowbit(x) (x&-x)
//by zrt
//problem:
//似乎有些不懂 
using namespace std;
typedef long long ll;
const double eps(1e-10);
int n;
int c[100005];
void add(int pos,int k){
	for(;pos<=n;pos+=lowbit(pos)){
		c[pos]+=k;
	}
}
int ask(int pos){
	int ret=0;
	for(;pos;pos-=lowbit(pos)){
		ret+=c[pos];
	}
	return ret;
}
int last[100005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	n<<=1;
	int ans=0;
	for(int i=1,k;i<=n;i++){
		scanf("%d",&k);
		if(!last[k]) add(i,1),last[k]=i;
		else ans+=ask(i)-ask(last[k]),add(last[k],-1);
	}
	printf("%d\n",ans);
	return 0;
}
