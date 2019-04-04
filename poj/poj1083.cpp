#include<iostream>
#include<cstdio>
#include<bitset>
#include<algorithm>
//by zrt
//problem:
using namespace std;
struct nod{
	int l,r;
};
nod a[200];
bitset<200> b;
bool cmp(nod a,nod b){
	if(a.l!=b.l) return a.l<b.l;
	else return a.r<b.r;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T,n,x,y;
	scanf("%d",&T);
	while(T--){
		b.reset();
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d",&x,&y);
			if(x>y) x^=y^=x^=y;
			a[i]=(nod){(x+1)>>1,(y+1)>>1};
		}
		sort(a,a+n,cmp);
		int ans=0;
		while(b.count()<n){
			ans++;
			int rig=-1;
			for(int i=0;i<n;i++){
				if(b[i]) continue;
				if(a[i].l>rig){
					b[i]=1;
					rig=a[i].r;
				}
			}
		}
		printf("%d\n",ans*10);
	}
	
	return 0;
}
