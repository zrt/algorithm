/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//永远做自己会做的题就永远还是原来的样子
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<complex>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps=1e-9;
typedef complex<int> Point;
typedef Point Vector;
Point read_point(){
	int x,y;
	scanf("%d%d",&x,&y);
	return Point(x,y);
}
int n,l;
Point P[1005];
Point tubao[1005];
bool cmp(const Point& x,const Point& y){
	if(real(x)!=real(y)) return real(x)<real(y);
	else return imag(x)<imag(y);
}
int Cross(Vector A,Vector B){
	return imag(conj(A)*B);
}
int stk[1005];int top;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&l);
	for(int i=0;i<n;i++){
		P[i]=read_point();
	}
	sort(P,P+n,cmp);
	top=0;
	double ans=(double)l*3.1415926535758*2;
	for(int i=0;i<n;i++){
		while(top>1&&Cross(P[stk[top-1]]-P[stk[top-2]],P[i]-P[stk[top-1]])<0)top--;
		stk[top++]=i;
	}
	int k=top;
	for(int i=n-2;i>=0;i--){
		while(top>k&&Cross(P[stk[top-1]]-P[stk[top-2]],P[i]-P[stk[top-1]])<0)top--;
		stk[top++]=i;
	}
	for(int i=1;i<top;i++){
		ans+=sqrt((double)(norm(P[stk[i]]-P[stk[i-1]])));
	}
	printf("%.0f",ans);
	return 0;
}
