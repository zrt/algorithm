#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n;
struct N{
	int x,y;
	friend bool operator < (const N&a,const N&b){
		return a.y<b.y;
	}
}a[150005];
priority_queue<int> q;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	sort(a,a+n);
	int now=0,ans(0);
	for(int i=0;i<n;i++){
		if(now+a[i].x<=a[i].y){
			now+=a[i].x;ans++;
			q.push(a[i].x);
		}else if(q.size()&&a[i].x<q.top()){
			now-=q.top()-a[i].x;
			q.pop();
			q.push(a[i].x);
		}
	}
	printf("%d\n",ans);
	return 0;
}
