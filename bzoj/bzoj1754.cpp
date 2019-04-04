#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
char a[105],b[105];
int c[105];
int la,lb;
int cc;
int stk[105],top;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%s%s",a,b);
	la=strlen(a);
	lb=strlen(b);
	for(int i=0;i<la;i++) a[i]-='0';
	for(int i=0;i<lb;i++) b[i]-='0';
	for(int i=0;i<la/2;i++) swap(a[i],a[la-i-1]);
	for(int i=0;i<lb/2;i++) swap(b[i],b[lb-i-1]);
	for(int i=0;i<la;i++){
		for(int j=0;j<lb;j++){
			c[i+j]+=a[i]*b[j];
		}
	}
	for(int i=0;i<=100;i++){
		stk[top++]=(c[i]+cc)%10;
		cc=(c[i]+cc)/10;
	}
	while(stk[top-1]==0) top--;
	while(top){
		printf("%d",stk[--top]);
	}
	puts("");
	return 0;
}
