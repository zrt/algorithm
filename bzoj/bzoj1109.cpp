#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int a[100005];
int p[100005];
int cc;
bool cmp(int x,int y){
	if(a[x]-x!=a[y]-y) return a[x]-x>a[y]-y;
	else return a[x]<a[y];
}
int stk[100005],top;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<=i) p[++cc]=i;
	}
	sort(p+1,p+cc+1,cmp);
	for(int i=1;i<=cc;i++){
		if(top==0||a[p[i]]>stk[top-1]) stk[top++]=a[p[i]];
		else *lower_bound(stk,stk+top,a[p[i]])=a[p[i]];
	}
	printf("%d\n",top);
	return 0;
}
