#include<iostream>
#include<cstdio>
using namespace std;
int n,x;
int h[80050];
unsigned long long sum;
int stack[80050],top;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&h[i]);
	h[n]=0x7fffffff;
	for(int i=0;i<=n;i++){
		while(top>0&&stack[top-1]<=h[i]){
			sum+=top-1;top--;
		}
		stack[top++]=h[i];
	}
	printf("%llu",sum);	
	return 0;
}