#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#include<cmath>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int t,k; 
int y,z,p;
void exgcd(int a,int b,LL& x,LL& y,int& d){
	if(!b){
		d=a;x=1;y=0;
	}else{
		exgcd(b,a%b,x,y,d);
		x-=y*(a/b);
		swap(x,y);
	}
}
set<int> s;
int pw(int y,int z){
	int t=1;
	while(z){
		if(z&1) t=t*1LL*y%p;
		y=y*1LL*y%p;
		z>>=1;
	}
	return t;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&t,&k);
	while(t--){
		scanf("%d%d%d",&y,&z,&p);
		
		if(k==1){
			printf("%d\n",pw(y,z));
		}else if(k==2){
			z%=p;y%=p;
			// Yx == Z %p
			// Yx0+py0==Z
			LL x2,y2;int d;
			exgcd(y,p,x2,y2,d);
			if(z%d){
				puts("Orz, I cannot find x!");
			}else{
				printf("%d\n",(int)((z/d*x2%p+p)%p));
			}
		}else{
			z%=p;y%=p;
			int sqr=sqrt(p);while(sqr*sqr<p) sqr++;
			int sqrp=pw(y,sqr),zz,t,niyuan;
			bool ok=0;
			if(y==0){
				if(z==0){
					puts("1");
					ok=1;
				}
				goto ed;
			}
			s.clear();
			zz=z;
			niyuan=pw(y,p-2);
			for(int i=0;i<=sqr;i++){
				s.insert(zz);
				zz=zz*1LL*y%p;
			}
			t=sqrp;
			for(int i=1;i<=sqr;i++){
				if(*s.lower_bound(t)==t){
					int k=1;
					for(int j=0;j<=sqr;j++){
						if(t*1LL*k%p==z){
							printf("%d\n",i*sqr-j);
							ok=1;break;
						}
						k=k*1LL*niyuan%p;
					}
					ok=1;break;
				}
				t=t*1LL*sqrp%p;
			}
			ed:
			if(!ok){
				puts("Orz, I cannot find x!");
			}
		}
	}
	
	return 0;
}
