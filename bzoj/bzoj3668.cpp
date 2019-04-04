#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int n,m;
char s[10];
int a[33];//1
int b[33];
int x;
int ans;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=0;i<=30;i++) a[i]=1;
	for(int i=0;i<n;i++){
		scanf("%s%d",s,&x);
		for(int j=0;j<=30;j++){
			if(s[0]=='A'){
				a[j]&=(x>>j)&1;
				b[j]&=(x>>j)&1;
			}else if(s[0]=='O'){
				a[j]|=(x>>j)&1;
				b[j]|=(x>>j)&1;
			}else if(s[0]=='X'){
				a[j]^=(x>>j)&1;
				b[j]^=(x>>j)&1;
			}
		}
	}
	for(int i=30;i>=0;i--){
		if((1<<i)<=m){
			if(b[i]){
				ans|=1<<i;
			}else if(a[i]){
				ans|=1<<i;
				m-=(1<<i);
			}
		}else{
			if(b[i]){
				ans|=1<<i;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
