#include<iostream>
#include<cstdio>
#include<algorithm>
//by zrt
//problem:
using namespace std;
inline int scan(){int tmp=0,sign=1;char x;while(((x=getchar())<'0'||x>'9')&&x!='-');if(x=='-') sign=-1;else tmp=x-'0';while((x=getchar())>='0'&&x<='9') tmp*=10,tmp+=x-'0';if(sign==1) return tmp;else return (-tmp);}
int n,m;
int a[10005],b[10005];
int hang=1,lie=1;
bool cmp(int a,int b){
	return a>b;
}
int ha,hb;
long long ans;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	n--;m--;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<m;i++){
		scanf("%d",&b[i]);
	}
	sort(a,a+n,cmp);sort(b,b+m,cmp);
	while(1){
		if(b[hb]>a[ha]){
		ans+=hang*b[hb];
		lie++;
		hb++;
		if(hb==m) break;
	}else{
		ans+=lie*a[ha];
		hang++;
		ha++;
		if(ha==n) break;
	}
	}
	for(;hb<m;hb++){
		ans+=hang*b[hb];
//		lie++;
	}
	for(;ha<n;ha++){
		ans+=lie*a[ha];
//		hang++;
	}
	printf("%lld\n",ans);
	return 0;
}
