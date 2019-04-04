#include<iostream>
#include<cstdio>
#include<cstring>
//by zrt
//problem:
using namespace std;
int f[100][1000];
inline void to(int a,int i){
	char s[10]; 
	sprintf(s,"%d",a);
	int n=strlen(s);
	for(int j=0;j<n;j++){
		f[i][j+1]=s[n-j-1]-'0';
	}
}
inline void add(int i){
	for(int j=1;j<1000;j++){
		f[i][j]=f[i-1][j]+f[i-2][j]+f[i-3][j]+f[i][j-1]/10;
		f[i][j-1]%=10;
	}
}
int main(){

	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c)==3){
		memset(f,0,sizeof f);
		to(a,0);to(b,1);to(c,2);
		for(int i=3;i<100;i++) add(i);
		
	int px=999;
	while(f[99][px]==0)px--;
	for(;px>=1;px--){
		printf("%d",f[99][px]);
	}
	puts("");
	}
	
	return 0;
}
