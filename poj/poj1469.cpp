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
typedef long long ll;
const double eps=1e-9;
bool cover[305];
int to[105][305],num[105];
int link[305];
bool find(int k){
	for(int i=0;i<num[k];i++){
		if(!cover[to[k][i]]){
			int q=link[to[k][i]];
			link[to[k][i]]=k;
			cover[to[k][i]]=1;
			if(q==-1||find(q)) return 1;
			else link[to[k][i]]=q;
		}
	}
	return 0;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int tt;
	scanf("%d",&tt);
	while(tt--){
		int p,n;
		scanf("%d%d",&p,&n);
		for(int i=0;i<p;i++){
			scanf("%d",&num[i]);
			for(int j=0;j<num[i];j++){
				scanf("%d",&to[i][j]);
			}
		}
		memset(link,-1,sizeof link);
		for(int i=0;i<p;i++){
			memset(cover,0,sizeof cover);
			find(i);
		}
		int tot=0;
		for(int i=1;i<=n;i++){
			if(link[i]!=-1) tot++;
		}
		if(tot>=p) puts("YES");
		else puts("NO");
	}
	
	return 0;
}
