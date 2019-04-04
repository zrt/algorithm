#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;
int n;
struct N{
	int x[5];
}p[1005];

bool ok[1005];

int count(){
	int ret =0;
	for(int i=1;i<=n;i++) if(ok[i]) ret++;
	return ret;
}
int dis(int x,int y){
	int ret=0;
	for(int i=0;i<5;i++){
		ret+=(p[x].x[i]-p[y].x[i])*(p[x].x[i]-p[y].x[i]);
	}
	return ret;
}
bool out_cir(int x,int y,int z){
	// z out x,y
	return dis(z,x)+dis(z,y) > dis(x,y);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		ok[i] = 1;
		for(int j=0;j<5;j++) cin>>p[i].x[j];
	}
	while(count()>2){
		// printf("#%d\n",count());
		int x,y;
		for(int i=1;i<=n;i++){
			if(ok[i]){
				x = i;
				break;
			}
		}
		for(int i=n;i>=1;i--){
			if(ok[i]){
				y=i;
				break;
			}
		}
		// printf("# %d %d\n",x,y);
		for(int i=1;i<=n;i++){
			if(i==x || i==y) continue;
			if(!ok[i]) continue;
			if(out_cir(x,y,i)){
				// printf("##  %d",i);
				ok[i] =0;
			}else{
				ok[x] = 0;
				ok[y] = 0;
			}
		}
	}
	// printf("# %d\n",count());
	for(int i=1;i<=n;i++){
		if(ok[i]){
			for(int j=1;j<=n;j++){
				if(i!=j){
					for(int k=j+1;k<=n;k++){
						if(k==i) continue;
						if(out_cir(j,k,i)){
							// printf("# %d %d %d\n",j,k,i);
							ok[i] = 0;
							goto ed;
						}
					}
				}
			}
			ed:;
		}
	}
	printf("%d\n",count());
	for(int i=1;i<=n;i++){
		if(ok[i]){
			printf("%d\n",i);
		}
	}
	


	return 0;
}