#include<cstdio>
using namespace std;
int a[20];
int sum[40];
void build(int o,int l,int r){
	if(l==r){
		sum[o]=a[l];
	}else{
		int m=(l+r)>>1;
		build(o<<1,l,m);
		build(o<<1|1,m+1,r);
		sum[o]=sum[o<<1]+sum[o<<1|1];
	}
}
int _l,_r,c;
void ask(int o,int l,int r){
	if(_l<=l&&r<=_r){
		c+=sum[o];
	}else{
		int m=(l+r)>>1;
		if(_l<=m)ask(o<<1,l,m);
		if(_r>m) ask(o<<1|1,m+1,r);
	}
}
int main(){
	scanf("%d%d",&a[1],&a[2]);
	build(1,1,2);
	_l=1,_r=2,c=0;
	ask(1,1,2);
	printf("%d\n",c);
	return 0;
}
