#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
char s[30005];
int nxt[30005][2];
int fail[30005];
int mark[30005];
int in[30005];
int tot,n;
queue<int> q;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s);
		int id=0;
		for(int j=0;s[j];j++){
			id=nxt[id][s[j]-'0']?nxt[id][s[j]-'0']:(nxt[id][s[j]-'0']=++tot);
		}
		mark[id]=1;
	}
	q.push(0);
	while(!q.empty()){
		int x=q.front();q.pop();
		mark[x]|=mark[fail[x]];
		for(int i=0;i<=1;i++){
			if(nxt[x][i]){
				q.push(nxt[x][i]);
				if(x) fail[nxt[x][i]]=nxt[fail[x]][i];
			}else nxt[x][i]=nxt[fail[x]][i];
		}
	}
	for(int i=1;i<=tot;i++){
		if(mark[i]) continue;
		for(int j=0;j<=1;j++){
			if(nxt[i][j]&&!mark[nxt[i][j]]){
				in[nxt[i][j]]++;
			}
		}
	}
	for(int i=1;i<=tot;i++){
		if(!mark[i]&&!in[i]) q.push(i);
	}
	while(!q.empty()){
		int x=q.front();q.pop();
		
		for(int j=0;j<=1;j++){
			if(nxt[x][j]&&!mark[nxt[x][j]]){
				in[nxt[x][j]]--;
				if(!in[nxt[x][j]]){
					q.push(nxt[x][j]);
				}
			}
		}
	}
	bool ok=0;
	for(int i=1;i<=tot;i++){
		if(!mark[i]&&in[i]){
			ok=1;
		}
	}
	if(ok) puts("TAK");
	else puts("NIE");
	return 0;
}
