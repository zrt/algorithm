#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int x,y,n;
double dfs(double x,double y,int n){
	//x>y
	if(x<y) swap(x,y);
	if(n==1) return x/y;
	double ret=1e100;
	for(int i=1;i<=n>>1;i++){
		//左右 
		ret=min(ret,max(dfs(x/n*i,y,i),dfs(x-x/n*i,y,n-i)));
		//上下
		ret=min(ret,max(dfs(x,y/n*i,i),dfs(x,y-y/n*i,n-i)));
	}
	return ret;
}
int main(){
	scanf("%d%d%d",&x,&y,&n);
	printf("%.6f",dfs(x,y,n));
	return 0;
}
