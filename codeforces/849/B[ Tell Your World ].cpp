#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
int n;
LL p[1005];

bool flag;

bool judge(int x1,int y1,int x2,int y2,int x3,int y3){
	LL v1x = x2-x1, v1y = y2-y1, v2x = x3-x1, v2y = y3-y1;
	if(v2x*v1y - v1x*v2y != 0 ) return true;
	return false;
}

bool check_in_line(int x,int a,int b){
	LL v1x = x-a, v1y = p[x]-p[a], v2x = b-a, v2y = p[b]-p[a];
	if(v2x*v1y - v1x*v2y == 0 ) return true;
	return false;
}
bool check_parr(int a,int b,int c,int d){
	LL v1x= b-a,v1y =p[b]-p[a],v2x=d-c,v2y=p[d]-p[c];
	if(v2x*v1y - v1x*v2y == 0 ) return true;
	return false;
}

bool check(int a,int b,int c){
	// a,b in a line  | c in other
	for(int i=1;i<=n;i++){
		if(i == a || i == b || i==c) continue;
		// printf("%d %d %d %d %d %d\n",a,b,c,i,check_in_line(i,a,b),check_parr(i,c,a,b));
		if(check_in_line(i,a,b) || check_parr(i,c,a,b)) continue;
		return false;
	}
	// printf("%d %d %d\n",a,b,c);
	return true;
}

void solve(int a,int b,int c){
	// printf("%d %d %d\n",a,b,c);
	if(check(a,b,c) || check(a,c,b) || check(b,c,a)) flag = 1;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%I64d",&p[i]);
	}
	// printf("# %d\n",check_in_line(1,3,2));
	for(int i=2;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(judge(1,p[1],i,p[i],j,p[j])){
				solve(1,i,j);
				goto ed;
			}
		}
	}
	ed:;

	if(flag) puts("Yes");
	else puts("No");
	return 0;
}