#include<cstdio>
using namespace std;
#define lowbit(x) ((x)&-(x))
int c[100];
int n;
void add(int pos,int a){
	while(pos<=n){
		c[pos]+=a;pos+=lowbit(pos);
	}
}
int ask(int pos){
	int ret=0;
	while(pos>0){
		ret+=c[pos];pos-=lowbit(pos);
	}
	return ret;
}
int main(){
	int a,b;
	n=2;
	scanf("%d%d",&a,&b);
	add(1,a);
	add(2,b);
	printf("%d\n",ask(2));
	return 0;
}
