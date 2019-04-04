#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int i,j,n;
typedef long long LL;
LL ans_num,ans_sum;
int prime[]={0,2,3,5,7,11,13,17,19,23,29};
void dfs(LL sum,LL num,LL now_pri,LL now_sum,LL now_num){
	LL newsum=sum*now_sum;if(newsum>n) return;
	LL newnum=num/now_num*(now_num+1);
	if(newnum>ans_num){
		ans_num=newnum;ans_sum=newsum;
	}else if(newnum==ans_num&&newsum<ans_sum) ans_sum=newsum;
	dfs(newsum,newnum,now_pri,now_sum,now_num+1);
	for(int i=now_pri+1;i<=10;i++)
		dfs(newsum,newnum,i,prime[i],1);
}
int main(){
	scanf("%d",&n);ans_sum=1;
	if(n>1) dfs(1,1,1,2,1);
	printf("%lld\n",ans_sum);
	return 0;
}
