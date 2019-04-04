/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
//by zrt
//problem:
using namespace std;
const int maxn=100005;
int _l,_r,_c;
int siz[3*maxn],kai[3*maxn],an[3*maxn];
int n,m;
void mk(int o,int l,int r){
	int m=(l+r)>>1;
	siz[o]=r-l+1;
	if(l==r) return;
	mk(o<<1,l,m);
	mk((o<<1)+1,m+1,r);
}
int opt;
inline void pushdown(int o){
	if(an[o]){
		an[o]=0;
		an[o<<1]^=1;
		an[(o<<1)+1]^=1;
		kai[o<<1]=siz[o<<1]-kai[o<<1];
		kai[(o<<1)+1]=siz[(o<<1)+1]-kai[(o<<1)+1];
	}
}
void change(int o,int l,int r){
	if(_l<=l&&r<=_r){
		an[o]^=1;
		kai[o]=siz[o]-kai[o];
	}else{
		pushdown(o);
		int m=(l+r)>>1;
		if(_l<=m) change(o<<1,l,m);
		if(_r>m) change((o<<1)+1,m+1,r);
		kai[o]=kai[o<<1]+kai[(o<<1)+1];
	}
}
void ask(int o,int l,int r){
	if(_l<=l&&r<=_r){
		_c+=kai[o];
	}else{
		pushdown(o);
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
	scanf("%d%d",&n,&m);
	mk(1,1,n);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&opt,&_l,&_r);
		if(opt&1){
			_c=0;ask(1,1,n);
			printf("%d\n",_c);
		}else{
			change(1,1,n);
		}
	}
	return 0;
}
