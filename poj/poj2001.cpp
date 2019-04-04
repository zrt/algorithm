#include<cstdio>
#include<cstring>
using namespace std;
char str[1005][25];
int n;
int trie[20005][26];
int a[20005];
int tot;
int main(){
//	freopen("in.txt","r",stdin);
	while(scanf("%s",str[n++])==1);
//	n--;
	int idx;
	for(int i=0;i<n;i++){
		int l=strlen(str[i]);
		idx=0;
		for(int j=0;j<l;j++){
			if(trie[idx][str[i][j]-'a']){
				idx=trie[idx][str[i][j]-'a'];a[idx]++;
			}else{
				idx=trie[idx][str[i][j]-'a']=++tot;a[idx]++;
			}
		}
	}
	for(int i=0;i<n;i++){
		printf("%s ",str[i]);
		int l=strlen(str[i]);
		idx=trie[0][str[i][0]-'a'];
		for(int j=1;j<l;j++){
			if(a[idx]==1){
				str[i][j]='\0';
				puts(str[i]);goto end;
			}else{
				idx=trie[idx][str[i][j]-'a'];
			}
		}
		puts(str[i]);
		end:;
	}
	return 0;
}