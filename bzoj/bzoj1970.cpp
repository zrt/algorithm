#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int k;
struct N{
	int a[100];
	friend N operator + (const N&a,const N&b){
		N c;
		for(int i=0;i<100;i++) c.a[i]=a.a[i]+b.a[i];
		for(int i=0;i<99;i++) c.a[i+1]+=c.a[i]/10,c.a[i]%=10;
		return c;
	}
	N mul2(){
		N b;
		for(int i=0;i<100;i++) b.a[i]=a[i]*2;
		for(int i=0;i<99;i++) b.a[i+1]+=b.a[i]/10,b.a[i]%=10;
		return b;
	}
	void out(){
		int top=99;
		while(top>0&&a[top]==0){
			top--;
		}
		while(top>=0) printf("%d",a[top--]);
		puts("");
	}
}po2[105],ans;
char s[205];
int p;
void solve(int k){
	if(s[p]=='0') ans=ans+po2[2*k],p++;
	else if(s[p]=='1'){
		p++;
	}else{
		p++;
		solve(k-1);
		solve(k-1);
		solve(k-1);
		solve(k-1);
	}
}
int main(){
	po2[0].a[0]=1;
	for(int i=1;i<=100;i++){
		po2[i]=po2[i-1].mul2();
	}
	scanf("%d",&k);
	scanf("%s",s+1);
	p=1;
	solve(k);
	ans.out();
	return 0;
}
