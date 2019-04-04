/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
int trie[1000005][10],tot;
bool pass[1000005],end[1000005];
int T,n;
char s[14];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&T);
	while(T--){
		tot=0;
		memset(trie,0,sizeof trie);
		memset(pass,0,sizeof pass);memset(end,0,sizeof end);
		scanf("%d",&n);
		bool ok=0;
		while(n--){
			scanf("%s",s);
			if(ok) continue;
			int l=strlen(s);
			int idx=0;
			for(int i=0;i<l&&(!ok);i++){
				if(trie[idx][s[i]-'0']){
					idx=trie[idx][s[i]-'0'];
				}else{
					idx=trie[idx][s[i]-'0']=++tot;
				}
				if(end[idx]) ok=1;
				if(i!=l-1){
					pass[idx]=1;
				}else{
					if(pass[idx]) ok=1;
					end[idx]=1;
				}
			}
		}
		if(ok) puts("NO");
		else puts("YES");
	}
	return 0;
}
