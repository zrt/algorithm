#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
//by zrt
//problem:
using namespace std;
int t,m,n,x,y,tmp,cnt;
vector<int> v[201];
int w[201],in[201];
bool vis[201];
priority_queue<int> q;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&t);
	while(t--){
		memset(in,0,sizeof in);
		memset(vis,0,sizeof vis);
		scanf("%d%d",&n,&m);
		cnt=n;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<=m;i++) {
			scanf("%d%d",&x,&y);
			v[y].push_back(x);
			in[x]++;
		}
		for(int i=1;i<=n;i++){
			if(!in[i]){
				q.push(i);vis[i]=1;
			}
		}
		while(!q.empty()){
			tmp=q.top();q.pop();
			w[tmp]=cnt--;
			for(int i=0;i<v[tmp].size();i++){
				if(vis[v[tmp][i]])continue;
				else{
					in[v[tmp][i]]--;
					if(!in[v[tmp][i]]){
						if(!vis[v[tmp][i]]){
							q.push(v[tmp][i]);vis[v[tmp][i]]=1;
						}
					}
				}
			}
		}
		for(int i=n;i>=1;i--){
			if(!vis[i]){
				w[i]=cnt--;vis[i]=1;
			}
		}
		int ok=1;
		for(int i=1;i<=n;i++){
			if(in[i]) {
				ok=0;break;
			}
		}
		
		for(int i=1;i<=n;i++) if(!vis[i]) {
			ok=0;break;
		}
		if(ok){
			int first=1;
		for(int i=1;i<=n;i++){
			if(first) first=0;else putchar(' ');
			printf("%d",w[i]);
		}
		puts("");
		}else{
			puts("-1");
		}
	}
	return 0;
}
