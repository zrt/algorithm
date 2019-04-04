#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef long long LL;

int n;
struct N{
	int x,y;
}a[1005],b[1005];

map<pair<int,int> ,int> mp;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	for(int i=1;i<=n;i++){
		scanf("%d%d",&b[i].x,&b[i].y);
		mp[make_pair(b[i].x,b[i].y)] = 1;
	}
	for(int i=1;i<=n;i++){
		int tx = a[1].x+b[i].x;
		int ty = a[1].y+b[i].y;
		bool flag = 1;
		for(int j=1;j<=n;j++){
			int ttx = tx-a[j].x;
			int tty = ty-a[j].y;

			if( mp.find(make_pair(ttx,tty)) == mp.end()){
				flag = 0;
			}
		}
		if(flag){
			printf("%d %d\n",tx,ty);
			break;
		}
	}

	return 0;
}

