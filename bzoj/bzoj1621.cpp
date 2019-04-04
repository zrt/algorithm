/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
#include<queue>
//by zrt
//problem:
using namespace std;
int n,k;long long tot=1;
queue<int> q;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&k);
	q.push(n);
	int x;
	while(!q.empty()){
		x=q.front();q.pop();
		if(x>k&&(!((x-k)&1))){
			tot++;
			q.push((x-k)>>1);
			q.push(((x-k)>>1)+k);
		}
	}
	printf("%lld\n",tot);
	return 0;
}
