#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int n,l,m;
int trie[105][26],tot;
typedef long double ld;
ld p[105];
char s[15];
int pos[15];
bool end[105];
void insert(int p){
	int id=0;
	for(int i=0;s[i];i++){
		if(trie[id][s[i]-'A']) id=trie[id][s[i]-'A'];
		else id=trie[id][s[i]-'A']=++tot;
	}
	end[id]=1;pos[p]=id;
}
struct Matrix{
	ld a[105][105];
	void clear(){
		memset(a,0,sizeof a);
	}
	friend Matrix operator * (const Matrix&a,const Matrix&b){
		Matrix c;
		c.clear();
		for(int i=0;i<=tot;i++){
			for(int j=0;j<=tot;j++){
				for(int k=0;k<=tot;k++){
					c.a[i][j]+=a.a[i][k]*b.a[k][j];
				}
			}
		}
		return c;
	}
}a,b;
int fail[105];
queue<int> q;
void mk_fail(){
	q.push(0);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<m;i++){
			if(trie[x][i]){
				q.push(trie[x][i]);
				if(x) fail[trie[x][i]]=trie[fail[x]][i];
			}else trie[x][i]=trie[fail[x]][i];
		}
	}
}
bool vis[105];
void dfs(int x){
	vis[x]=1;
	for(int i=0;i<m;i++){
		if(!end[x]){
			a.a[x][trie[x][i]]+=p[i];
		}
		if(!vis[trie[x][i]]) dfs(trie[x][i]);
	}
}
int main(){
	scanf("%d%d%d",&n,&l,&m);
	for(int i=0,x,y;i<m;i++){
		scanf("%d%d",&x,&y);
		p[i]=x/(ld)y;
	}
	for(int i=0;i<n;i++){
		scanf("%s",s);
		insert(i);
	}
	mk_fail();
	dfs(0);
	for(int i=0;i<n;i++) a.a[pos[i]][pos[i]]=1;
	for(int i=1;i<=50;i++) a=a*a;
	b.a[0][0]=1;
	b=b*a;
	for(int i=0;i<n;i++){
		printf("%.2f\n",(double)b.a[0][pos[i]]);
	}
	return 0;
}
/*
3 2 2
1 2
1 2
AB
BA
AA
*/
