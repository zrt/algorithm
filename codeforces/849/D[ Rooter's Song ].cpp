#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n,w,h;
int g[100005],p[100005],t[100005];
int w10=100000;
vector<int> v1[200005],v2[200005];
int ansx[100005],ansy[100005];
int tmpx[100005],tmpy[100005],tot;
bool cmp(int a,int b){
	return p[a]<p[b];
}
int main(){
	scanf("%d%d%d",&n,&w,&h);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&g[i],&p[i],&t[i]);
		if(g[i] == 1) v1[p[i]-t[i]+w10].push_back(i);
		else v2[p[i]-t[i]+w10].push_back(i);
	}
	for(int i=0;i<=200000;i++){
		if(v1[i].size()>0 || v2[i].size()>0){
			sort(v1[i].begin(),v1[i].end(),cmp);
			sort(v2[i].begin(),v2[i].end(),cmp);
			reverse(v2[i].begin(),v2[i].end());
			tot=0;
			for(int j=0;j<v1[i].size();j++){
				tmpx[tot] = p[v1[i][j]];
				tmpy[tot] = h;
				tot++;
			}
			for(int j=0;j<v2[i].size();j++){
				tmpx[tot] = w;
				tmpy[tot] = p[v2[i][j]];
				tot++;
			}
			int tot2=0;
			for(int j=0;j<v2[i].size();j++){
				ansx[v2[i][j]] = tmpx[tot2];
				ansy[v2[i][j]] = tmpy[tot2];
				tot2++;
			}
			for(int j=0;j<v1[i].size();j++){
				ansx[v1[i][j]] = tmpx[tot2];
				ansy[v1[i][j]] = tmpy[tot2];
				tot2++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d %d\n",ansx[i],ansy[i]);
	}





	return 0;
}