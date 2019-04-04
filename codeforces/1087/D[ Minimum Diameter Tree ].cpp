#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

int n,s;
int d[100005];
int main(){
	scanf("%d%d",&n,&s);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		d[x]++;
		d[y]++;
	}
	int num = 0;
	for(int i=1;i<=n;i++) num += d[i]==1;
	printf("%.20f\n",s*2./num);

	return 0;
}
