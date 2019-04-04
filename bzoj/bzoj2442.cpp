#include<cstdio>
using namespace std;
long long sum[100005];
long long f[100005];
long long n,k;
struct N{
	int x;long long w;
	N(int a=0,long long b=0){
		x=a,w=b;
	}
};
struct dddl{
	int h,t;
	N q[100005];
	void insert(N a){
		while(h!=t&&q[t-1].w<=a.w) t--;
		q[t++]=a;
	}
	void pop(int x){
		if(q[h].x==x) h++;
	}
	long long ask(){
		return q[h].w;
	}
}dddl;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&sum[i]);
	}
	k++;
	for(int i=1;i<=n;i++) sum[i]+=sum[i-1];
	dddl.insert(N(0,0));
	for(int i=1;i<=n+1;i++){
		dddl.pop(i-k-1);
		f[i]=dddl.ask()+sum[i-1];
		dddl.insert(N(i,f[i]-sum[i]));
	}
	printf("%lld\n",f[n+1]);
	return 0;
}
