/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//óà??×?×??o?á×?μ?ìa?íóà???1ê??-à′μ??ù×ó
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps=1e-9;
int n;
int H[100005],P[200005],X[200005],E[200005],tot;
inline void add(int x,int y,int z){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;
}
int Xor[100005];int ans=0;
void dfs(int x,int fa){
	for(int i=H[x];i;i=X[i]){
		if(fa==P[i]) continue;
		Xor[P[i]]=Xor[x]^E[i];
		ans=max(ans,Xor[P[i]]);
		dfs(P[i],x);
	}
}
int cnt,trie[100005*31][2];
int main(){
	while(~scanf("%d",&n)){
		memset(H,0,sizeof H);
		memset(trie,0,sizeof trie);
		cnt=0;
		tot=1;
		int x,y,z;
		ans=0;
		for(int i=1;i<n;i++){
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);add(y,x,z);
			ans=max(ans,z);
		}
		dfs(n,-1);
		for(int i=1;i<n;i++){
			int idx=0;
			for(int j=30;j>=0;j--){
				if(!(trie[idx][Xor[i]>>j&1])){
					idx=trie[idx][Xor[i]>>j&1]=++cnt;
				}else idx=trie[idx][Xor[i]>>j&1];
			}
		}
		for(int i=1;i<n;i++){
			int p=0;
			int idx=0;
			for(int j=30;j>=0;j--){
				if(!(trie[idx][(Xor[i]>>j&1)^1])){
					idx=trie[idx][Xor[i]>>j&1];
				}else idx=trie[idx][(Xor[i]>>j&1)^1],p+=1<<j;
			}
			ans=max(ans,p);
		}
		printf("%d\n",ans);
	}
	return 0;
}
