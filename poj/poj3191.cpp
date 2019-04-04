#include<iostream>
#include<cstdio>
#include<stack>
//by zrt
//problem:
using namespace std;
int x,p;
stack<int> s;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&x);
	if(x==0){
		putchar('0');
	}
	while(x){
		p=x%-2;
		if(p<0){
			p+=2;
		}
		s.push(p);
		x-=p;
		x/=-2;
	}
	while(!s.empty()){
		p=s.top();s.pop();
		putchar('0'+p); 
	}
	return 0;
}
