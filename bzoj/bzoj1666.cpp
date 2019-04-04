/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//永远做自己会做的题就永远还是原来的样子
#include<cstdio>
//by zrt
//problem:
using namespace std;
unsigned long long n;
unsigned long long fen;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%llu",&n);
	while(n!=1){
		fen++;
		if(n&1){
			n=n*3+1;
		}else n>>=1;
	}
	printf("%llu",fen);
	return 0;
}
