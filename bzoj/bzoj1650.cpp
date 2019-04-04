#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
long long  pos[50005];
long long  L,n,m;
bool judge(long long  lim){
	long long  sum=0;
	long long  c=0;
	for(int i=1;i<=n;i++){
		if(pos[i]-pos[i-1]+sum<lim) c++,sum+=pos[i]-pos[i-1];
		else sum=0;
	}
	return c<=m;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	
	scanf("%lld%lld%lld",&L,&n,&m);
	pos[0]=0;
	for(int i=1;i<=n;i++) scanf("%lld",&pos[i]);
	n++;
	pos[n]=L;
	sort(pos+1,pos+n+1);
	long long  l=-1,r=L+1;
	while(r-l>1){
		int m=l+(r-l)/2;
		if(judge(m)){
			l=m;
		} else{
			r=m;
		}
	}
	printf("%lld\n",l);
	return 0;
}
