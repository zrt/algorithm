#include<cstdio>
#include<cmath>
using namespace std;
double n,p;
int main(){
	while(scanf("%lf%lf",&n,&p)==2){
		printf("%.0f\n",pow(p,1.0/n));
	}
	return 0;
}