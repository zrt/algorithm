#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int d[100005];
queue<int> q;
int main(){
	memset(d,0,sizeof d);
	int n,k;
	scanf("%d%d",&n,&k);
	d[n]=1;
	q.push(n);
	int t;
	while(!q.empty()){
		t=q.front();q.pop();
		if(t-1>=0&&d[t-1]==0){
			d[t-1]=d[t]+1;
			q.push(t-1);
		}
		if(t+1<=100000&&d[t+1]==0){
			d[t+1]=d[t]+1;
			q.push(t+1);
		}
		if(t<<1<=100000&&d[t<<1]==0){
			d[t<<1]=d[t]+1;
			q.push(t<<1);
		}
		if(d[k]) break;
	}
	printf("%d\n",d[k]-1);
	return 0;
}
