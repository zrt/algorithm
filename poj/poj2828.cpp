/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//永远做自己会做的题就永远还是原来的样子
#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
struct Ask{
	int x,n;
}; 
Ask a[200005];
int n;
int c[200005];
int o[200005];
int ans[200005];
#define lowbit(x) (x&-x)
int ask(int pos){
	int ret=0;
	while(pos>0){
		ret+=c[pos];
		pos-=lowbit(pos);
	}
	return ret;
}
int getpos(int x){// get x-1 pos x ge yi
	int l=0,r=n,mid;//l xia jie r shang jie
	while(l!=r){
		mid=(l+r)>>1;
		int tmp=ask(mid);
		if(tmp<x){
			l=mid+1;
		}else if(tmp>x){
			r=mid-1;
		}else if(tmp==x){
			r=mid;
		}
	}
	l++;
	while(o[l]==0) l++;
	return l;
}
void add(int pos,int x){
	o[pos]+=x;
	while(pos<=n){
		c[pos]+=x;
		pos+=lowbit(pos);
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			scanf("%d%d",&a[i].x,&a[i].n);
		}
		for(int i=1;i<=n;i++) c[i]=1,o[i]=1;
		for(int i=1;i<n;i++){
			if(i+lowbit(i)<=n){
				c[i+lowbit(i)]+=c[i];
			}
		}
		for(int i=n-1;i>=0;i--){
			int pos=getpos(a[i].x);
			ans[pos]=a[i].n;
			add(pos,-1);
		}
		printf("%d",ans[1]);
		for(int i=2;i<=n;i++){
			printf(" %d",ans[i]);
		}
		puts("");
	}
	
	return 0;
}
