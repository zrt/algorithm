#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
bool meet[87654322];
struct N{
	int x,w;
	N(int a=0,int b=0){
		x=a,w=b;
	}
};
queue<N> q;
int a[8];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int chushi=12348765;
	int ans;
	meet[chushi]=1;
	q.push(N(chushi,0));
	int aim=0;
	for(int i=0;i<8;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<4;i++) aim=aim*10+a[i];
	for(int i=7;i>=4;i--) aim=aim*10+a[i];
	int x,c;
	while(!q.empty()){
		x=q.front().x,c=q.front().w;q.pop();
		if(x==aim) break;
		int to=x/10000+x%10000*10000;
		if(!meet[to]){
			meet[to]=1;
			if(to==aim){
				ans=c+1;
				break;
			}
			q.push(N(to,c+1));
		}
		to=x/10000%10*10000000+x/100000*10000+x%10*1000+x/10%1000;
		if(!meet[to]){
			meet[to]=1;
			if(to==aim){
				ans=c+1;
				break;
			}
			q.push(N(to,c+1));
		}
		to=x/10000000*10000000+x/100%10*1000000+x/1000000%10*100000+x/1000%100*1000+x/10%10*100+x/100000%10*10+x%10;
		if(!meet[to]){
			meet[to]=1;
			if(to==aim){
				ans=c+1;
				break;
			}
			q.push(N(to,c+1));
		}
	}
	printf("%d\n",ans);
	return 0;
}
