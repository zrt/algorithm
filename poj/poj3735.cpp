#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
#define int long long 
int n,m,k;
struct M{
	int a[120][120];
	void set0(){
		memset(a,0,sizeof a);
	}
	void setI(){
		memset(a,0,sizeof a);
		for(int i=0;i<n;i++) a[i][i]=1;
	}
	friend M operator * (M& a,M& b){
		static M ret;
		ret.set0();
		for(int i=0;i<n;i++){
			for(int k=0;k<n;k++){
				if(a.a[i][k]){
					for(int j=0;j<n;j++){
						ret.a[i][j]+=a.a[i][k]*b.a[k][j];
					}
				}
			}
		}
		return ret;
	}
};
M a,b,c;
int x,y;
char s[10];
M pow(M a,int b){
	static M ret;
	ret.setI();
	while(b){
		if(b&1) ret=ret*a;
		a=a*a;
		b>>=1;
	}
	return ret;
}
#undef int
int main(){
	#define int long long 
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%lld%lld%lld",&n,&m,&k),n|m|k){
		n++;
		a.setI();
		while(k--){
			scanf("%s",s);
			if(s[0]=='g'){
				scanf("%lld",&x);
				a.a[0][x]++;
			}else if(s[0]=='s'){
				scanf("%lld%lld",&x,&y);
				for(int i=0;i<n;i++){
					swap(a.a[i][x],a.a[i][y]);
				}
			}else{
				scanf("%lld",&x);
				for(int i=0;i<n;i++){
					a.a[i][x]=0;
				}
			}
		}
		b.set0();
		b.a[0][0]=1;
		c=pow(a,m);
		b=b*c;
		for(int i=1;i<n;i++){
			printf("%lld ",b.a[0][i]);
		}
		puts("");
	}
	
	return 0;
}