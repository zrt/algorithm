#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;

int n,x,y;
int a[105];

int main(){
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(x>y){
		cout<<n;
	}else{
		int num = 0;
		int l = 1;
		int r = n;
		for(int i=1;i<=n;i++){
			if(a[i]<=x){
				num ++;
			}
			while(r>1 && a[r]>x) r--;
			a[r] += y;
		}
		cout<<num;
	}

	return 0;
}
