#include<iostream>
#include<cstring> 
#include<cstdio>
//by zrt
//problem:
using namespace std;
inline int f(int a){
	char x[10];
	while(a>=10){
		sprintf(x,"%d",a);
		int n=strlen(x);
		int sum=0;
		for(int i=0;i<n;i++){
			sum+=x[i]-'0';
		}
		a=sum;
	}
	return a;
} 
int input(){
	char s[3000];
	scanf("%s",s);
	int n=strlen(s),sum=0;
	for(int i=0;i<n;i++) sum+=s[i]-'0';
	return sum;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int n;
	while(n=input()){	
		printf("%d\n",f(n));
	}
	return 0;
}
