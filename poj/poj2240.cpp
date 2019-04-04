#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<map>
//by zrt
//problem:
using namespace std;
string a,b,s;
map<string,int> m;
int n,cnt;
double z;
int tot,M,T;
double d[40][40];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%d",&n)==1&&n){
		printf("Case %d: ",++T);
		memset(d,0,sizeof d);
		for(int i=1;i<=n;i++){
			cin>>s;m[s]=i;
		}
		scanf("%d",&M);
		for(int i=1;i<=n;i++ ) d[i][i]=1.0;//这个千万不能放到后面，否则对于  usdollar 1.9 usdollar 完蛋。。。。 
		for(int i=0;i<M;i++){
			cin>>a>>z>>b;
			d[m[a]][m[b]]=z;
		}
//		for(int i=1;i<=n;i++ ) d[i][i]=1.0;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(d[i][j]<d[i][k]*d[k][j]){
						d[i][j]=d[i][k]*d[k][j];
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(d[i][i]>1.0){
				goto yes;
			}
		}
		if(1){
			puts("No");
		}else{
			yes:; puts("Yes");
		}
	}
	return 0;
}
