#include<iostream>
#include<cstdio>
//by zrt
//problem:
using namespace std;
//(2*a1+n-1)*n/2==a1*n+n*n/2-n/2==sum
 /* sum = (x+1) + (x+2) + ... + (x+i)
  * sum = x*i + (i+1)*i/2
  * (sum - i*(i+1)/2) % i == 0 */
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int n;
	scanf("%d",&n);
	while(n--){
		int k,sum;
		scanf("%d%d",&k,&sum);
		int ct=0;
		int temp;
		for(int i=2;(temp=sum-i*(i+1)/2)>=0;i++){//确保x大于等于0 
			if(temp%i==0){//x为整数 
				ct++;
			}
		} 
		printf("%d %d\n",k,ct);
	}
	
	return 0;
}
