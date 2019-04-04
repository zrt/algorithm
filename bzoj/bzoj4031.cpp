#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
char s[15][15];
int tot;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int num[15][15];
int a[105][105];
const int mod=1000000000;
int Det(int n){
	int ret=1;
	for(int i=1;i<=n;i++){
		int p=-1;
		for(int j=i;j<=n;j++){
			if(a[j][i]){
				p=j;
				break;
			}
		}
		if(p==-1) return 0;
		if(p!=i){
			ret=mod-ret;
			for(int j=i;j<=n;j++) swap(a[i][j],a[p][j]);
		}
		
		for(int j=i+1;j<=n;j++){
			while(a[j][i]){
				int t=a[i][i]/a[j][i];
				for(int k=i;k<=n;k++){
					a[i][k]=(a[i][k]+(mod-t)*1LL*a[j][k])%mod;
					swap(a[i][k],a[j][k]);
				}
				ret=mod-ret;
			}
		}
		ret=ret*1LL*a[i][i]%mod;
	}
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(s[i][j]=='.') num[i][j]=++tot;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(num[i][j]) for(int k=0;k<4;k++){
		int x=i+dx[k],y=j+dy[k];
		if(num[x][y]){
			a[num[i][j]][num[x][y]]--;
			a[num[i][j]][num[i][j]]++;	
		}
	}
	for(int i=1;i<=tot;i++) for(int j=1;j<=tot;j++) if(a[i][j]<0) a[i][j]=mod+a[i][j];
	printf("%d\n",Det(tot-1));
	return 0;
}
