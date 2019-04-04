#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int n,m;
int H[100005];
int X[200005];
int P[200005];
bool vis[200005];
int tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
priority_queue<int, vector<int>, greater<int> > pq;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0,x,y;i<m;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	vis[1]=1;
	pq.push(1);
	while(!pq.empty()){
		int x=pq.top();pq.pop();
		printf("%d ",x);
		for(int i=H[x];i;i=X[i]){
			if(!vis[P[i]]){
				vis[P[i]] = 1;
				pq.push(P[i]);
			}
		}
	}
	
	return 0;
}
