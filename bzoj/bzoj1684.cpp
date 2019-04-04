#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,ans1,ans2;
double ans=1e30;
void calc(int x,int y)
{
	if(x*m==y*n)return;
	double tmp=abs((double)x/y-(double)n/m);
	if(tmp<ans)
	{
		ans=tmp;
		ans1=x;ans2=y;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int j=1;j<=32767;j++)
	{
		int i=(double)n/m*j;
		calc(i,j);calc(i+1,j);
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}
