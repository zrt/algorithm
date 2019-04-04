#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
using namespace std;
char s[250]; 
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%s",s);
	int l=strlen(s);
	sort(s,s+l);
	do{
		printf("%s\n",s);
	}while(next_permutation(s,s+l));
	return 0;
}
