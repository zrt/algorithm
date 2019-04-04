#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
const int inf=(1<<30);
typedef long long LL;
const double eps=1e-8;
int start,finish;
int c[40][40];
int calc(int bit,int one,int zero){
	if(!one) return 0;
	int ret=0;
	for(int i=0;i<=bit;i++){//one
		if(i+one<=zero+bit-i) ret+=c[bit][i];
	}
	return ret;
}
int solve(int k){
	if(k==0) return 0;
	int high;
	int ret=0;
	for(high=30;high>=0&&(k&(1<<high))==0;high--);
	for(int i=0;i<high;i++){
		ret+=calc(i,1,0);
	}
	int x=0,y=0;
	
	for(int i=high;i>=0;i--){
		if(k&(1<<i)) x++,ret+=calc(i,x-1,y+1);else y++;
	}
	return ret;
}

int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&start,&finish);
	c[0][0]=1;
	for(int i=1;i<=40;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
	printf("%d\n",solve(finish+1)-solve(start));	
	return 0;
}
