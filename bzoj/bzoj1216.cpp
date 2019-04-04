#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
struct N{
	int id,arrive,use,val;
	friend bool operator < (const N&a,const N&b){
		if(a.val!=b.val) return a.val<b.val;
		return a.arrive>b.arrive;
	}
	N(int a=0,int b=0,int c=0,int d=0){
		id=a;
		arrive=b;
		use=c;
		val=d;
	}
	
}t;
priority_queue<N> q;
int tim;
int id,arrive,use,val;
void work_until(int x){
	while(!q.empty()){
		t=q.top();q.pop();
	//	printf("### %d %d %d %d\n",t.id,t.arrive,t.use,t.val);
		tim=max(tim,t.arrive);
		if(tim+t.use>x){
			t.use-=x-tim;
		//	printf("# %d %d\n",x,tim);
		//	printf("$IN %d %d %d %d\n",t.id,t.arrive,t.use,t.val);
			tim=x;
			q.push(N(t.id,t.arrive,t.use,t.val));
			break;
		}else{
			tim+=t.use;
			printf("%d %d\n",t.id,tim);
		}
	}
}
int main(){
	while(~scanf("%d%d%d%d",&id,&arrive,&use,&val)){
		work_until(arrive);
		q.push(N(id,arrive,use,val));
	}
	work_until(0x7fffffff);
	return 0;
}
