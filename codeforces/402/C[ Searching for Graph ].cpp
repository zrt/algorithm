#include<iostream>
#include<cstdio>
#include<vector>
//by zrt
//problem:
using namespace std;
int T,n,p,m;
vector<int> v[30];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&p);
		m=2*n+p;
		int d=1;
		while(m>0){
			for(int i=1;i<=n;i++){
				if(i+d>n) break;
				m--;
				printf("%d %d\n",i,i+d);
				if(m<=0) break;
			}
			d++;
		}
	}
	return 0;
}

