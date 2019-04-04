#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
struct point{
	int x,y;
	friend bool operator < (const point&a,const point&b){
		if(a.x!=b.x) return a.x<b.x;
		return a.y<b.y;
	}
}p,a[100006],a0,b0;
int n,m,q,Q[200005][2];
bool del[200005];
char s[15];
set<point> t;
double dis(const point&a,const point&b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double ans;
set<point>::iterator it,it2;
bool judge(const point &a,const point &b,const point &c){
	return (a.x-b.x)*(c.y-b.y)-(a.y-b.y)*(c.x-b.x)>0;
}
bool judge2(const point &a,const point &b,const point &c){
	return (a.x-b.x)*(c.y-b.y)-(a.y-b.y)*(c.x-b.x)>=0;
}
bool test(const point &a){
	it=t.begin();
	++it;
	for(;it!=t.end();++it){
		it2=it;
		it2--;
		if(!judge2(*it2,*it,a)) return 1;
	}
	return 0;
}
void ins(int x){
	//insert a[x]
	it2=it=t.upper_bound(a[x]);
	--it2;
	ans-=dis(*it,*it2);
	point b;
	while(1){
		it=t.upper_bound(a[x]);
		b=*it;
		++it;
		if(it==t.end()) break;
		if(judge(a[x],b,*it)) break;
		else{
			ans-=dis(b,*it);
			--it;
			t.erase(it);
		}
	}
	while(1){
		it=t.upper_bound(a[x]);
		--it;
		b=*it;
		if(it==t.begin()) break;
		--it;
		if(judge(*it,b,a[x])) break;
		else{
			ans-=dis(b,*it);
			++it;
			t.erase(it);
		}
	}
	it=t.upper_bound(a[x]);
	ans+=dis(a[x],*it);
	--it;
	ans+=dis(a[x],*it);
	t.insert(a[x]);
}
double Ans[200005];
int main(){
	scanf("%d%d%d",&n,&p.x,&p.y);
	b0.x=n;
	t.insert(a0);
	t.insert(b0);
	t.insert(p);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d",&Q[i][0]);
		if(Q[i][0]==1){
			scanf("%d",&Q[i][1]);
			del[Q[i][1]]=1;
		}
	}
	ans=dis(p,a0)+dis(p,b0);
	for(int i=1;i<=m;i++){
		if(!del[i]){
			if(test(a[i]))
			ins(i);
		}
	}
	for(int i=q;i>=1;i--){
		if(Q[i][0]==2){
			Ans[i]=ans;
		}else{
			if(test(a[Q[i][1]]))
			ins(Q[i][1]);
		}
	}
	for(int i=1;i<=q;i++){
		if(Q[i][0]==2){
			printf("%.2f\n",Ans[i]);
		}
	}
	return 0;
}
