#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int n,m,cost[30];
char s[2100];
int f[2100][2100];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1,x,y;i<=n;i++){
		char tmp[5];
		scanf("%s%d%d",tmp,&x,&y);
		cost[tmp[0]-'a']=min(x,y);
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=m;i++) s[i]-='a',f[i][i]=0,f[i+1][i]=0;
	for(int l=1;l<=m;l++){
		for(int i=1;i<=m;i++){
			int j=i+l;
			if(j>m) break;
			f[i][j]=min(f[i][j-1]+cost[s[j]],f[i+1][j]+cost[s[i]]);
			if(s[i]==s[j]) f[i][j]=min(f[i][j],f[i+1][j-1]);
		}
	}
	printf("%d\n",f[1][m]);
	return 0;
}
