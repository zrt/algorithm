#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long LL;

int H[1005],X[2005],P[2005],tot;
int du[1005];
bool ok[1005];
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int n;
bool okk;
void dfs(int x){
	du[x]=1;
	int t=0;
	for(int i=H[x];i;i=X[i]){
		dfs(P[i]);
		du[x]++;
		if(du[P[i]]  == 1){
			t++;
		}
	}
	if(du[x]==1 || (du[x]>1 && t>=3)){
		ok[x]=1;
	}else okk=0;

}
int main(){
	cin>>n;
	for(int i=2,tmp;i<=n;i++){
		cin>>tmp;
		add(tmp,i);
	}
	okk=1;
	dfs(1);
	if(okk) puts("Yes");
	else puts("No");
	return 0;
}