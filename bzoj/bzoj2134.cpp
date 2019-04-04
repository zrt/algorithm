#include<cstdio>
#include<algorithm>
using namespace std;
int a[10000005];
int n,A,B,C;
int main(){
	scanf("%d%d%d%d%d",&n,&A,&B,&C,a+1); for (int i=2;i<=n;i++) a[i] = ((long long)a[i-1] * A + B) % 100000001; for (int i=1;i<=n;i++) a[i] = a[i] % C + 1; 
	double ans=0;
	for(int i=1;i<n;i++)ans+=1/(double)(max(a[i],a[i+1]));
	printf("%.3f\n",ans+1/(double)(max(a[n],a[1])));
	return 0;
}
