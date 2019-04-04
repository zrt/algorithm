#include<cstdio>
#include<algorithm>
using namespace std;

int n,m;
int ans;
int b[25];
// V剩余体积 R最大的半径 H最大的高度 Q已经计算的表面积 M剩余层数 
void dfs(int V,int R,int H,int Q,int M){
	if(Q+V*1.0/(R*R)*2*R>=ans) return;//最优性剪枝
	//可行性剪枝
	int sum=0;
	for(int i=0;i<M;i++){
		sum+=(R-i)*(R-i)*(H-i);
	}
	if(sum<V) return;
	
	if(V<b[M]) return;
	
	if(V==0&&M==0){
		ans=min(ans,Q);
		return;
	}else{
		for(int i=R;i>=1;i--){
			for(int j=H;j>=1;j--){
				if(V-i*i*j>=0)
					dfs(V-i*i*j,i-1,j-1,Q+2*j*i,M-1);
			}
		}	
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) b[i]=b[i-1]+i*i*i;
	ans=100000000;
	for(int i=100;i>=1;i--){
		for(int j=10000;j>=1;j--){
			if(n-i*i*j>=0)
				dfs(n-i*i*j,i-1,j-1,i*i+2*j*i,m-1);
		}
	}
	printf("%d\n",ans);
	return 0;
	
}