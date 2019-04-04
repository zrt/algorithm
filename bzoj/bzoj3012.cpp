#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
char s[300005];
int trie[300005][26];
int tot;
int fa[300005];
int num[300005];
bool fail[300005];
bool ok[300005];
bool map[26][26];
int ch[300005];
void print(int x){
	if(!x) return;
	print(fa[x]);
	putchar(ch[x]+'a');
}
bool vis[26];
bool dfs(int now,int aim){
	vis[now]=1;
	for(int i=0;i<26;i++){
		if(map[now][i]){
			if(i==aim) return 1;
			if(!vis[i]&&dfs(i,aim)) return 1;
		}
	}
	return 0;
}
int main(){

	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s);
		int id=0;
		for(int i=0;s[i];i++){
			if(trie[id][s[i]-'a']) id=trie[id][s[i]-'a'];
			else fa[tot+1]=id,id=trie[id][s[i]-'a']=++tot,ch[id]=s[i]-'a';
		}
		fail[id]=1;
		num[i]=id;
	}
	for(int i=0;i<n;i++){
		ok[i]=1;
		memset(map,0,sizeof map);
		int id=num[i];
		while(id){
			int f=fa[id];
			if(fail[f]) {
                ok[i]=0;break;
			}
			for(int i=0;i<26;i++){
				if(i==ch[id]) continue;
				if(trie[f][i]){
					map[ch[id]][i]=1;
				}
			}
			id=f;
		}
		for(int j=0;j<26;j++){
			memset(vis,0,sizeof vis);
			if(dfs(j,j)){
				ok[i]=0;break;
			}
		}

	}
	int ans=0;
	for(int i=0;i<n;i++) if(ok[i]) ans++;
	printf("%d\n",ans);
	for(int i=0;i<n;i++){
		if(ok[i]) print(num[i]),puts("");;
	}

	return 0;
}
