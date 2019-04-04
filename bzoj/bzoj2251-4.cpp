#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int tot,idx;
int trie[9000005][2];
int a[9000005];
void add(char* str){
	idx=0;
	for(int j=0;str[j];j++){
		idx=trie[idx][str[j]-'0']=trie[idx][str[j]-'0']?trie[idx][str[j]-'0']:(++tot);
		a[idx]++;
	}
}
char s[3500];
void dfs(int idx){
	if(a[idx]>1) printf("%d\n",a[idx]);
	if(trie[idx][0]) dfs(trie[idx][0]);
	if(trie[idx][1]) dfs(trie[idx][1]);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int l;
	scanf("%d",&l);
	scanf("%s",s);
	for(int i=0;i<l;i++) add(s+i);
	dfs(0);
	return 0;
}
