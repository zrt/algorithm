#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
double a,b,c,d,e,f;
double xa[200020],ya[200020],xb[200020],yb[200020];
double A,B,C,F,X,Y;
int o,i,j,x,n;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	while(n--){
		scanf("%d",&o);
		if(o==0){
			i++;j++;
			scanf("%lf%lf%lf%lf",&xa[i],&ya[i],&xb[i],&yb[i]);
			A=ya[i]-yb[i];
			B=xb[i]-xa[i];
			C=xa[i]*yb[i]-xb[i]*ya[i];
			F=A*A+B*B;
			a+=A*A/F;
			b+=2*A*B/F;
			c+=B*B/F;
			d+=2*A*C/F;
			e+=2*B*C/F;
			f+=C*C/F;
		}else if(o==1){
			j--;
			scanf("%d",&x);
			A=ya[x]-yb[x];
			B=xb[x]-xa[x];
			C=xa[x]*yb[x]-xb[x]*ya[x];
			F=A*A+B*B;
			a-=A*A/F;
			b-=2*A*B/F;
			c-=B*B/F;
			d-=2*A*C/F;
			e-=2*B*C/F;
			f-=C*C/F;
		}else{
			if(!j) puts("0.00");
			else{
				if(fabs(b*b-4*a*c)>eps){
					X=(2*c*d-e*b)/(b*b-4*a*c);
					Y=(2*a*e-d*b)/(b*b-4*a*c);
				}else{
					X=Y=0;	
					if(fabs(2*a+b)>eps){
						X=-(d+e)/(2*a+b);
					}else if(fabs(2*c+b)>eps){
						Y=-(d+e)/(2*c+b);
					}else{
						Y=-d/b;
					}
				}
				printf("%.2f\n",a*X*X+b*X*Y+c*Y*Y+d*X+e*Y+f);
			}
		}
	}
	
	return 0;
}
