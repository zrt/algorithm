#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int l[1005][1005],r[1005][1005],b[1005][1005];
int mxl[1005][1005],mxr[1005][1005];
long long ans;
int c[2005][2005];
#define lowbit(x) ((x)&-(x))
void add(int x,int y,int d){
	for(int i=x;i>0;i-=lowbit(i)) for(int j=y;j>0;j-=lowbit(j)) c[i][j]+=d;
}
int ask(int x,int y){
	int ret=0;
	if(x<=0) x=1;
	if(y<=0) y=1;
	for(int i=x;i<=2*n;i+=lowbit(i)){
		for(int j=y;j<=2*n;j+=lowbit(j)){
			ret+=c[i][j];
		}
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			scanf("%d%d%d",&l[i][j],&r[i][j],&b[i][j]);
		}
	}
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=i;j++){
			mxl[i][j]=l[i-1][j]?(mxl[i-1][j]+1):0;
			mxr[i][j]=r[i-1][j-1]?(mxr[i-1][j-1]+1):0;
		}
	}
	for(int i=2;i<=n+1;i++){
		int last=1;
		for(int j=1;j<=i;j++){
			if(b[i-1][j-1]==0){
				while(last<j){
					add(last,last+mxl[i][last],-1);last++;
				}
			}
			ans+=ask(j-mxr[i][j],j);
			add(j,j+mxl[i][j],1);
		}
		while(last<=i) add(last,last+mxl[i][last],-1),last++;
	}
	memset(mxl,0,sizeof mxl);
	memset(mxr,0,sizeof mxr);
	for(int i=n;i>=1;i--){
		for(int j=1;j<=i;j++){
			mxl[i][j]=r[i][j]?(mxl[i+1][j+1]+1):0;
			mxr[i][j]=l[i][j]?(mxr[i+1][j]+1):0;
		}
	}
	for(int i=2;i<=n+1;i++){
		int last=1;
		for(int j=1;j<=i;j++){
			if(b[i-1][j-1]==0){
				while(last<j){
					add(last,last+mxl[i][last],-1);last++;
				}
			}
			ans+=ask(j-mxr[i][j],j);
			add(j,j+mxl[i][j],1);
		}
		while(last<=i) add(last,last+mxl[i][last],-1),last++;
	}
	printf("%lld\n",ans);	
	return 0;
}
