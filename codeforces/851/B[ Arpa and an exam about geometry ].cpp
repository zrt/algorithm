#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;
LL ax,ay,bx,by,cx,cy;
bool not_in_line(){
	LL vx = ax-bx, vy = ay-by, ux = cx-bx,uy = cy-by;
	return vx*uy - vy*ux != 0;
}
bool equal(){
	LL dis1 = (ax-bx)*(ax-bx)+(ay-by)*(ay-by);
	LL dis2 = (cx-bx)*(cx-bx)+(cy-by)*(cy-by);
	return dis1==dis2;
}
int main(){
	cin>>ax>>ay>>bx>>by>>cx>>cy;
	if(not_in_line() && equal()){
		puts("Yes");
	}else{
		puts("No");
	}
	
	return 0;
}