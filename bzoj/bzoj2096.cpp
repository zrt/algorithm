#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps(1e-10);
int n,k,a[3000005];
int ans;
//4 5 6
//3
int read(){
	static char x;
	static int num;
	while(x=getchar(),x<'0'||x>'9');
	num=x-'0';
	while(x=getchar(),x>='0'&&x<='9') num*=10,num+=x-'0';
	return num;
}
struct dddl{
	int q[3000005],pos[3000005],h,t;
	inline void pop_front(int p){
		if(pos[h]==p) h++;
	}
	inline void add(int x,int p){
		while(h!=t&&q[t-1]>x){
			t--;
		}
		q[t++]=x;pos[t-1]=p;
	}
	inline int get(){
		return q[h];
	}
}mx,mn;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	k=read();n=read();
	for(int i=1;i<=n;i++) a[i]=read();
//	a[n+1]=a[n]-k-1;n++;
	int can=0;
	for(int i=1;i<=n;i++){
		if(can<i){
			mx.add(-a[i],i);
			mn.add(a[i],i);
			can++;
		}
		while(can<=n&& -mx.get()-(ll)mn.get()<=k) {
			can++;
			mx.add(-a[can],can);
			mn.add(a[can],can);
		}
		ans=max(ans,can-i);
		mx.pop_front(i);mn.pop_front(i);
	}
	printf("%d\n",ans);
	return 0;
}
