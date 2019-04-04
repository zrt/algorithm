#include<cstdio>
#include<algorithm>

using namespace std;
int n;
int a[100005];
int b[100005];
int c[100005];
int f[100005];
int lowbit(int x){
	return x&-x;
}
void change(int pos,int w){
	while(pos<=n){
		a[pos]=max(a[pos],w);
		pos+=lowbit(pos);
	}
}
int ask(int pos){
	int ret=0;
	while(pos>0){
		ret=max(ret,a[pos]);
		pos-=lowbit(pos);
	}
	return ret;
}

int main(){
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++) a[i]=0;
		for(int i=1;i<=n;i++) scanf("%d",&b[i]),c[i]=b[i];
		// 离散化
		sort(b+1,b+n+1);
		int tot=unique(b+1,b+n+1)-(b+1);
		for(int i=1;i<=n;i++) c[i]=lower_bound(b+1,b+tot+1,c[i])-b;
		for(int i=1;i<=n;i++){
			f[i]=1+ask(c[i]-1);
			change(c[i],f[i]);
		}
		int mx=0;
		for(int i=1;i<=n;i++) mx=max(mx,f[i]);
		printf("%d\n",mx);
	}
	
	
	return 0;
} 