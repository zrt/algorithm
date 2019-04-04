#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int rank[27][27];//nv
int merg[27];//nv
int last[27];//nan
int now[27];//nan
int to[27][27];
int tt;
int n;
char s[100];
queue<int> q;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&tt);
	while(tt--){
		memset(now,0,sizeof now);
		memset(last,-1,sizeof last);
		memset(merg,-1,sizeof merg);
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%*s");
		for(int i=0;i<n;i++) scanf("%*s");
		for(int i=0;i<n;i++){
			scanf("%s",s);
			int x=s[0]-'a';
			q.push(x);
			for(int i=0;i<n;i++){
				to[x][i]=s[i+2]-'A';
			}
		}
		for(int i=0;i<n;i++){
			scanf("%s",s);
			int x=s[0]-'A';
			for(int i=0;i<n;i++){
				rank[x][s[i+2]-'a']=i;
			}
		}
		int x,y;
		while(!q.empty()){
			x=q.front();q.pop();
			y=to[x][now[x]++];
			if(merg[y]==-1){
				merg[y]=x;
				last[x]=y;
				continue;
			}else{
				if(rank[y][x]<rank[y][merg[y]]){
					last[merg[y]]=-1;
					q.push(merg[y]);
					merg[y]=x;
					last[x]=y;
				}else{
					q.push(x);
					continue;
				}
			}
		}
		for(int i=0;i<26;i++){
			if(last[i]!=-1){
				printf("%c %c\n",i+'a',last[i]+'A');
			}
		}
		puts("");
	}
	
	return 0;
}
