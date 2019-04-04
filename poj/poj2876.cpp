#include<iostream>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<cstring>
using namespace std;
char b[540000];
inline void f(int i,int j){
	if(i==j) return;
	int x=(j-i)/3+1+i,q=((j-i)<<1)/3+i;
	for(int k=x;k<=q;k++){
		b[k]=' ';
	}
	f(i,i+(j-i)/3);int p=((j-i+1)<<1)/3;
	for(int k=q+1;k<=j;k++){
		b[k]=b[k-p];
	}
}
inline int powd(int a,int b){
	if(!b) return 1;
	int k=powd(a,(b>>1));
	k*=k;
	if(b&1){
		k*=a;
	}
	return k;
}
int main(){
	int n;
	while(scanf("%d",&n)==1){
		int last;
		last=powd(3,n);
		for(int i=1;i<=last;i++) b[i]='-';
		f(1,last);
		b[last+1]='\0';
		puts(b+1);
	}
	return 0;
}
