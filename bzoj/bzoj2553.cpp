#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,len,N,tot,nn;
int trie[80][26];
bool end[80];
int fail[80];
char s[80];
void insert(){
	int id=0;
	for(int i=0;s[i];i++){
		if(trie[id][s[i]-'a']) id=trie[id][s[i]-'a'];
		else id=trie[id][s[i]-'a']=++tot;
	}
	end[id]=1;
}
queue<int> q;
struct Matrix{
	long double a[80][80];
	void clear(){
		memset(a,0,sizeof a);
	}
	friend Matrix operator * (const Matrix&a,const Matrix&b){
		Matrix c;
		c.clear();
		for(int i=0;i<=nn;i++){
			for(int j=0;j<=nn;j++){
				for(int k=0;k<=nn;k++){
					c.a[i][j]+=a.a[i][k]*b.a[k][j];
				}
			}
		}
		return c;
	}
}a,b;
long double p;
bool vis[80];
void dfs(int x){
	vis[x]=1;
	for(int i=0;i<N;i++){
		if(end[trie[x][i]]){
			a.a[x][0]+=p;
			a.a[x][nn]+=p;
		}else{
			a.a[x][trie[x][i]]+=p;
			if(!vis[trie[x][i]])dfs(trie[x][i]);
		}
	}
}
void pow(int n){
	if(n==0) return;
	n--;
	b=a;
	while(n){
		if(n&1) b=b*a;
		n>>=1;
		a=a*a;
	}
}
int main(){
	scanf("%d%d%d",&n,&len,&N);
	for(int i=1;i<=n;i++) scanf("%s",s),insert();
	q.push(0);
	while(!q.empty()){
		int x=q.front();q.pop();
		end[x]|=end[fail[x]];
		for(int i=0;i<N;i++){
			if(trie[x][i]){
				q.push(trie[x][i]);
				if(x) fail[trie[x][i]]=trie[fail[x]][i];
			}else trie[x][i]=trie[fail[x]][i];
		}
	}
	p=1/(long double)N;
	nn=tot+1;
	dfs(0);
	a.a[nn][nn]=1;
//	for(int i=0;i<=nn;i++){
//		for(int j=0;j<=nn;j++){
//			printf("%.3f ",(double)a.a[i][j]);
//		}
//		puts("");
//	}
	pow(len);
	printf("%.10f\n",(double)b.a[0][nn]);
	return 0;
}
