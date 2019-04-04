#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;
typedef long long LL;

const LL mod = 1e9+7;

int n,k;
const LL MAX = 7000;
bitset<7005> a[100005];
bitset<7005> init[7005];
bitset<7005> mobi[7005];

int mu[7005];int tt;
int mindiv[7005],prime[7005],tot;

void print(bitset<7005> b){
	for(int i=0;i<10;i++){
		printf("# %d %d\n",i,b[i]==1);
	}
}
int main(){
	for(int y = 1; y<=MAX;y++){
		for(int i = y;i<=MAX;i+=y){
			init[i][y] = 1;
		}
	}
	mu[1]=1;
	for(int i=2;i<=MAX;i++){
		if(!mindiv[i]) mindiv[i]=i,prime[tot++]=i,mu[i]=-1;
		for(int j=0;prime[j]*i<=MAX;j++){
			mindiv[prime[j]*i]=prime[j];
			if(prime[j]==mindiv[i]){
				mu[prime[j]*i]=0;
				break;
			}
			mu[prime[j]*i]=-1*mu[i];
		}
	}
	for(int i=1;i<=MAX;i++){
		for(int j=1;i*j<=MAX;j++){
			if(mu[j]){
				mobi[i][i*j] = 1;
			}
		}
	}

	scanf("%d%d",&n,&k);
	while(k--){
		int t,x,y,z;
		scanf("%d",&t);
		if(t == 1){
			scanf("%d%d",&x,&y);
			a[x] = init[y];
		}else if(t==2){
			scanf("%d%d%d",&x,&y,&z);
			a[x] = a[y]^a[z];
		}else if(t==3){
			scanf("%d%d%d",&x,&y,&z);
			a[x] = a[y]&a[z];
		}else if(t==4){
			scanf("%d%d",&x,&y);
			// print(a[x]);
			// print(mobi[y]);
			int cnt = (mobi[y] & a[x]).count();
			if(cnt&1) putchar('1');
			else putchar('0');
		}
	}

	return 0;
}
