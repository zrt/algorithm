#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m; 
int a[1000005];
bool died[1000005];
int ls[1000005],rs[1000005],h[1000005],f[1000005];
int get(int x){
	return f[x]==x?x:f[x]=get(f[x]);
}
int merge(int x,int y){
	if(!x) return y;
	if(!y) return x;
	if(a[x]>a[y]) swap(x,y);
	rs[x]=merge(rs[x],y);
	if(h[ls[x]]<h[rs[x]]) swap(ls[x],rs[x]);
	h[x]=rs[x]?(h[rs[x]]+1):0;
	return x;
}
char s[10];
int x,y;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) f[i]=i;
	scanf("%d",&m);
	while(m--){
		scanf("%s",s);
		if(s[0]=='M'){
			scanf("%d%d",&x,&y);
			if(died[x]||died[y]) continue;
			x=get(x),y=get(y);
			if(x!=y){
				f[x]=f[y]=merge(x,y);
			}
		}else{
			scanf("%d",&x);
			if(died[x]) {
				puts("0");
				continue;
			}
			x=get(x);
			died[x]=1;
			printf("%d\n",a[x]);
			f[x]=merge(ls[x],rs[x]);
			f[f[x]]=f[x];
		}
	}
	
	return 0;
}
