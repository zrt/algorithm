#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
typedef long long LL;
LL n,m,r,k;
map<pair<int,int>,bool> mp;
struct N{
	int x,y;
	LL p;
	friend bool operator < (N a,N b){
		return a.p<b.p;
	}
};
priority_queue<N> q;
LL calc_p(int x,int y){
	int lux = max(x-r+1,1LL);
	int luy = max(y-r+1,1LL);
	int rdx = min(x*1LL, n-r+1);
	int rdy = min(y*1LL,m-r+1);
	return (rdx-lux+1)*1LL*(rdy-luy+1);
}
LL ans =0;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main(){
	cin>>n>>m>>r>>k;
	q.push((N){n/2+1,m/2+1,calc_p(n/2+1,m/2+1)});
	mp[make_pair(n/2+1,m/2+1)] = 1;
	while(k>0){
		N t = q.top();q.pop();
		k--;
		ans+= t.p;
		for(int i=0;i<4;i++){
			int nx = t.x+dx[i];
			int ny = t.y+dy[i];
			if(nx>=1 && nx<= n && ny>=1 && ny<=m && mp.find(make_pair(nx,ny))==mp.end()){
				mp[make_pair(nx,ny)] = 1;
				q.push((N){nx,ny,calc_p(nx,ny)});
			}
		}
	}
	printf("%.20f\n",ans/((n-r+1)*1.*(m-r+1)));

	return 0;
}