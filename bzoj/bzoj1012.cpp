#include<iostream>
#include<cstdio>
//by zrt
//problem:
using namespace std;
const int MAX= 200005;
const int n=200005;
int mod;
int tail=1,_l,_r,_c,t,y,m,x[MAX*3],pos[MAX],_max;
char s[5]; 
void mk(int o,int l,int r){
	if(l==r){
		pos[l]=o;
	}else{
		int m=(l+r)>>1;
		mk(o<<1,l,m);
		mk((o<<1)+1,m+1,r);
	}
}
void update(int o){
	if((o>>1)>0&&x[o>>1]<x[o]){
		x[o>>1]=x[o];
		update(o>>1);
	}
}
void ask(int o,int l,int r){
	if(_l<=l&&r<=_r){
		if(_max<x[o]) _max=x[o];
	}else{
		int m=(l+r)>>1;
		if(_l<=m) ask(o<<1,l,m);
		if(_r>m) ask((o<<1)+1,m+1,r);
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&m,&mod);
	mk(1,1,n);
	for(int i=0;i<m;i++){
		scanf("%s%d",s,&y);
		if(s[0]=='Q'){
			_max=0;
			_l=tail-y;_r=tail-1;
			ask(1,1,n);
			printf("%d\n",_max);
			t=_max;
		}else{
			_c=t+y;
			_c%=mod;
			x[pos[tail]]=_c;
			update(pos[tail]);
			tail++;
		}
	}
	return 0;
}
