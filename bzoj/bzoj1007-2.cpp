/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//永远做自己会做的题就永远还是原来的样子
#include<cstdio>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int n;
struct N{
	int num;
	int k,b;
	N(int c=0,int a=0,int B=0){
		num=c;k=a,b=B;
	}
};
N a[50000];
int k,b;
bool cmp(N a,N b){
	if(a.k!=b.k)return a.k<b.k;
	return a.b>b.b;
}
struct P{
	int num;
	int Num;
	double x;
	P(int a=0,double b=0,int c=0){
		num=a,x=b;Num=c;
	}
};
P stk[50000];int top;
double Jiao(int i,int j){
	return (double)(a[j].b-a[i].b)/(double)(a[i].k-a[j].k);
}
const double eps=1e-8;
int sc[50000],tot;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&k,&b);
		a[i]=N(i+1,k,b);
	}
	sort(a,a+n,cmp);
	int klast=1<<30;
	for(int i=0;i<n;i++){
		if(a[i].k==klast) continue;
	//	printf("Num:%d k:%d b:%d lastk:%d\n",a[i].num,a[i].k,a[i].b,klast);
		if(top==0){
			stk[top++]=P(i,-1e250,a[i].num);
		}else{
			double px=Jiao(stk[top-1].num,i);
		//	printf("num:%d px:%f\n",a[i].num,px);
			if(px>stk[top-1].x){
				stk[top++]=P(i,px,a[i].num);
			}else{
				top--;i--;continue;
			}
		}
		klast=a[i].k;
	}
	
	for(int i=0;i<top;i++){
		sc[tot++]=stk[i].Num;
	}
	sort(sc,sc+tot);
	for(int i=0;i<tot;i++){
		printf("%d ",sc[i]);
	}
	return 0;
}
