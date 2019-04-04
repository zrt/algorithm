#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Num{
	int a[400];
	void print(){
		int top=399;
		while(top>0&&a[top]==0) top--;
		while(top>=0)putchar('0'+a[top]),top--;
		puts("");
	}
}ten,two,ans,one;
Num operator + (const Num&a,const Num&b){
	Num c;
	memset(c.a,0,sizeof c.a);
	for(int i=0;i<400;i++){
		c.a[i]=a.a[i]+b.a[i];
	}
	for(int i=0;i<399;i++){
		c.a[i+1]+=c.a[i]/10;
		c.a[i]%=10;
	}
	return c;
}
Num operator * (const Num&a,const Num&b){
	Num c;
	memset(c.a,0,sizeof c.a);
	for(int i=0;i<200;i++){
		for(int j=0;j<200;j++){
			c.a[i+j]+=a.a[i]*b.a[j];
		}
	}
	for(int i=0;i<399;i++){
		c.a[i+1]+=c.a[i]/10;
		c.a[i]%=10;
	}
	return c;
}
Num pow2(int x){
	Num ret,a;
	memset(a.a,0,sizeof a);
	memset(ret.a,0,sizeof ret);
	ret.a[0]=1;a.a[0]=2;
	while(x){
		if(x&1) ret=ret*a;
		a=a*a;
		x>>=1;
	}
	return ret;
}
char s[400];
int div2(){
	int r=0;
	for(int i=399;i>=0;i--){
		r=r*10+ten.a[i];
		ten.a[i]=r/2;
		r%=2;
	}
	return r;
}
int main(){
	scanf("%s",s);
	int l=strlen(s);
	reverse(s,s+l);
	for(int i=0;i<l;i++) ten.a[i]=s[i]-'0';
	one.a[0]=1;
//	ten=ten+one;
//	ten.print();
	for(int i=0;i<400;i++) two.a[i]=div2();
//	two.print();
	int L=399;
	while(L>=0&&two.a[L]==0) L--;
	L++;
	int lim=(L-1)/2;
	for(int i=1;i<L;i++) ans=ans+pow2((i-1)/2);
	bool ok=0,okk=1;
	for(int i=0;i<=lim;i++){
		if(two.a[L-i-1]){
			if(!ok){
				ok=1;continue;
			}
			ans=ans+pow2(lim-i);
		}
	}
	for(int i=lim;i>=0;i--){
		if(two.a[L-i-1]){
			if(!two.a[i]){
				okk=0;break;
			}
		}else{
			if(two.a[i]){
				break;
			}
		}
	}
	if(okk) ans=ans+one;
	ans.print();
	return 0;
}
