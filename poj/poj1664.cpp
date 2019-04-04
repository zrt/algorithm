#include<iostream>
#include<cstdio>
using namespace std;
int count;
int m,n;
inline void dfs(int sum,int i,int last){
	if(i==n){
		if(sum==m) count++;
		return;
	}
	else{
		for(int p=last;p<=(m-sum);p++){
			dfs(sum+p,i+1,p);
		}
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int x;
	scanf("%d",&x);
	while(x--){
		count=0;
		scanf("%d%d",&m,&n);
		dfs(0,0,0);
		printf("%d\n",count);
	}
	return 0;
}
