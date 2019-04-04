#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
//f[i]=(f[i-2]*3-f[i-1]+2)
//f[1]=1 f[2]=5
struct N{
	int a[205];
	friend N operator + (const N&a,const N&b){
		N c;
		memset(c.a,0,sizeof c.a);
		for(int i=1;i<=200;i++) c.a[i]+=a.a[i]+b.a[i],c.a[i+1]+=c.a[i]/10,c.a[i]%=10;
		return c;
	}
	friend N operator - (const N&a,const N&b){
		N c;
		memset(c.a,0,sizeof c.a);
		for(int i=1;i<=200;i++) c.a[i]=a.a[i]-b.a[i];
		for(int i=1;i<=200;i++){
			while(c.a[i]<0) c.a[i+1]--,c.a[i]+=10;
		}
		return c;
	}
}f[105];
int n;
N mul3(const N&a){
	N c;
	memset(c.a,0,sizeof c);
	for(int i=1;i<=200;i++) c.a[i]+=a.a[i]*3,c.a[i+1]+=c.a[i]/10,c.a[i]%=10;
	return c;
}
N two;
int main(){
	scanf("%d",&n);
	f[1].a[1]=1;f[2].a[1]=5;
	two.a[1]=2;
	for(int i=3;i<=n;i++){
		f[i]=mul3(f[i-1])+two-f[i-2];
	}
	int top=200;
	while(top>0&&f[n].a[top]==0) top--;
	for(int i=top;i>0;i--){
		printf("%d",f[n].a[i]);
	}
	puts("");
	return 0;
}
