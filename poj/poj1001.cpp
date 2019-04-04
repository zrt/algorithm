#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
struct N{int a[205];};
N operator * (N a,N b){
	static N c;
	memset(c.a,0,sizeof c.a);
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			c.a[i+j-1]+=a.a[i]*b.a[j];
		}
	}
	for(int i=1;i<=200;i++){
		c.a[i+1]+=c.a[i]/10;
		c.a[i]%=10;
	}
	return c;
}
char s[15];
int k;
char stk[205];int top;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(~scanf("%s%d",s,&k)){
		N ans;
		memset(ans.a,0,sizeof ans.a);
		ans.a[1]=1;
		N p;
		memset(p.a,0,sizeof p.a);
		int pos=0,t;
		for(int i=5;i>=0;i--){
			if(s[i]=='.'){
				t=5-i;
			}else{
				p.a[++pos]=s[i]-'0';
			}
		}
		t*=k;
		while(k){
			if(k&1) ans=ans*p;
			p=p*p;
			k>>=1;
		}
		top=0;
		for(int i=1;i<=200;i++){
			stk[top++]=ans.a[i]+'0';
			if(i==t){
				stk[top++]='.';
			}
		}
		int h=0;t=top-1;
		while(h<=t&&stk[t]=='0') t--;
		while(h<=t&&stk[h]=='0') h++;
		if(stk[h]=='.') h++;
		if(h>t) t++;
		for(int i=t;i>=h;i--){
			putchar(stk[i]);
		}
		puts("");
	}
	return 0;
}
