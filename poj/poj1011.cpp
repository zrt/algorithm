
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int a[100],vis[100],temp,aim;

bool dfs(int remain,int tot,int pos){
	if(tot==temp)
		return true;
	for(int i=pos+1;i<=n;i++){
		if(vis[i]) continue;
		if(remain-a[i]==0){
			vis[i]=1;
			if(dfs(aim,tot+1,0)) return true;
			vis[i]=0;
			return false;
		}
		else if(remain-a[i]>0){
			vis[i]=1;
			if(dfs(remain-a[i],tot,i)) return true;
			vis[i]=0;
			if(remain==aim) return false;
			while(i<n&&a[i]==a[i+1]) i++;
		}
	}
	return false;
}

inline bool cmp(int x,int y){
	return x>y;
}

int main(){
	while(scanf("%d",&n),n){	
		int sum=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		sort(a+1,a+n+1,cmp);
		for(int i=a[1];i<=sum;i++)
	 	if(sum%i==0){
			memset(vis,0,sizeof vis);
			temp=sum/i;
			aim=i;
			if(!dfs(i,0,0)) continue;
			else {printf("%d\n",i);break;}
		}
	}
	return 0;
}
