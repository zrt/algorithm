#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
//by zrt
//problem:
using namespace std;
char s[300];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(gets(s)){
		if(!gets(s)){
			break;
		}
		int n=strlen(s);
		for(int i=0;i<n;i++){
			if(isalpha(s[i])){
				s[i]-=5;
				if(s[i]<'A'){
					s[i]+=26;
				}
			}
		}
		puts(s);
		gets(s);
	}
	
	return 0;
}
