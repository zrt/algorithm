#include<iostream>
#include<cstdio>
#include<cstring>
//by zrt
//problem:cfB
using namespace std;
char s[5010];
int cnt,l=-1,ls;
int main(){
	scanf("%s",s);
	int n=strlen(s);
	for(int i=0;i<n-3;i++){
		if(s[i]=='b'&&s[i+1]=='e'&&s[i+2]=='a'&&s[i+3]=='r') {
			ls=i;
			cnt+=(ls-l)*(n-ls-3);
			l=ls;
		}
	}
	printf("%d",cnt);
	return 0;
}

