#include<cstdio>
#include<cmath>
double n,m,y;
int main(){
	scanf("%lf%lf%lf",&n,&m,&y);
	printf("%d\n",(int)(m*pow(1+n/100.0,y)));
	return 0;
}
