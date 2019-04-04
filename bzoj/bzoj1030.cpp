#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,m;
int trie[10005][26],fail[10005],tot,end[10005];
int dp[105][10005];
const int mod=10007;
char s[105];
queue<int> q;
void insert(char*s){
	int id=0;
	for(int i=0;s[i];i++){
		if(trie[id][s[i]-'A']) id=trie[id][s[i]-'A'];
		else id=trie[id][s[i]-'A']=++tot;
	}
	end[id]=1;
}
void mk_fail(){
	q.push(0);
	while(!q.empty()){
		int x=q.front();q.pop();
		end[x]|=end[fail[x]];
		for(int i=0;i<26;i++){
			if(trie[x][i]){
				if(x) fail[trie[x][i]]=trie[fail[x]][i];
				q.push(trie[x][i]);
			}else{
				trie[x][i]=trie[fail[x]][i];
			}
		}
	}
}
int ans=1;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",s);
		insert(s);
	}
	mk_fail();
	dp[0][0]=1;
	for(int i=0;i<m;i++){
		ans=ans*26%mod;
		for(int j=0;j<=tot;j++){
			if(end[j]) continue;
			for(int k=0;k<26;k++){
				if(!(end[trie[j][k]])){
					dp[i+1][trie[j][k]]+=dp[i][j];
					dp[i+1][trie[j][k]]%=mod;
				}
			}
		}
	}
	for(int i=0;i<=tot;i++){
		ans=((ans-dp[m][i])%mod+mod)%mod;
	}
	printf("%d\n",ans);
	return 0;
}
