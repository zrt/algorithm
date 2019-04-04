#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
int n;
struct N{
	int pos,type;
	friend bool operator < (N a,N b){
		return a.pos<b.pos;
	}
}a[100005];
char s[10];
int sumw[100005];
int sums[100005];
int val[800005];
int zero=120000;
inline void add(int o,int l,int r,int pos,int k){
	if(l==r){
		val[o]=min(val[o],k);
	}else{
		int mid=(l+r)>>1;
		if(pos<=mid) add(o<<1,l,mid,pos,k);
		else add(o<<1|1,mid+1,r,pos,k);
		val[o]=min(val[o<<1],val[o<<1|1]);
	}
	
}
int ask(int o,int l,int r,int L,int R){
	if(L<=l&&r<=R) return val[o];
	else{
		int mid=(l+r)>>1;
		if(R<=mid) return ask(o<<1,l,mid,L,R);
		else if(L>mid) return ask(o<<1|1,mid+1,r,L,R);
		else {
			return min(ask(o<<1,l,mid,L,mid),ask(o<<1|1,mid+1,r,mid+1,R));
		}
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%s",&a[i].pos,s);
		if(s[0]=='W') a[i].type=0;
		else a[i].type=1;
	}
	sort(a+1,a+n+1);
	memset(val,0x3f,sizeof val);
	for(int i=1;i<=n;i++){
		if(a[i].type){
			sums[i]=sums[i-1]+1;
			sumw[i]=sumw[i-1];
		}else{
			sums[i]=sums[i-1];
			sumw[i]=sumw[i-1]+1;
		}
	}
	int X,Y;
	X=Y=0;
	int ans=0;
	add(1,1,zero+zero,zero,0);
	for(int i=1;i<=n;i++){
		if(a[i].type) Y++;else X++;
		int d=X-Y+zero;
		int p=ask(1,1,zero+zero,1,d);
		if(p<n){
			if((sumw[i]-sumw[p]+sums[i]-sums[p])&1) p++;
			if(p+1<i) ans=max(ans,a[i].pos-a[p+1].pos);
		}
		add(1,1,zero+zero,d,i);
	}
	printf("%d\n",ans);
	return 0;
}
