#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[1000005];
int l;
int nxt[1000005];
int main(){
	scanf("%d%s",&l,s);
	nxt[0]=-1;
	int j=-1;
	for(int i=1;i<l;i++){
		while(~j&&s[j+1]!=s[i]) j=nxt[j];
		if(s[j+1]==s[i]) j++;
		nxt[i]=j;
	}
	printf("%d\n",l-1-nxt[l-1]);
	return 0;
}
