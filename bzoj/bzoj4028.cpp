#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!LLD
int n,q;
int a[100005];
int SIZE;
int block_num;
char s[105];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
bool ok;
struct BLOCK{
	int g,xs;
	int H[357],X[357],P[357],tot;
	void clear(){
		tot=0;
		memset(H,0,sizeof H);
	}
	void add(int x,int y){
		P[++tot]=y;X[tot]=H[x];H[x]=tot;
	}
	void insert(int x){
		int p=x%357;
		add(p,x);
	}
	void ask(int x){
		int p=x%357;
		for(int i=H[p];i;i=X[i]){
			if(P[i]==x){
				ok=1;
			}
		}
	}
}b[405];
void bd(int x){
	int l=(x-1)*SIZE+1;
	int r=x*SIZE;
	r=min(r,n);
	b[x].g=0;
	for(int i=l;i<=r;i++) b[x].g=gcd(b[x].g,a[i]);
	b[x].clear();
	int xs=0;
	for(int i=l;i<=r;i++) xs^=a[i],b[x].insert(xs);
	b[x].xs=xs;
}
LL p;
int ans;
void ask1(int x,int xs,int g){
	int l=(x-1)*SIZE+1;
	int r=x*SIZE;
	r=min(r,n);
	for(int i=l;i<=r;i++){
		xs^=a[i];
		g=gcd(g,a[i]);
		if(xs*1LL*g==p){
			ok=1;
			ans=i;
			break;
		}
	}
}
void ask2(int x,int p){
	b[x].ask(p);
}
int main(){
//	freopen("gcdxor.in","r",stdin);
//	freopen("gcdxor.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	SIZE=sqrt(n+1)+1;
	block_num=(n-1)/SIZE+1;
	for(int i=1;i<=block_num;i++) bd(i);
	scanf("%d",&q);
	while(q--){
		scanf("%s",s);
		if(s[0]=='M'){
			int x;
			scanf("%d",&x);
			x++;
			scanf("%d",&a[x]);
			int num=(x-1)/SIZE+1;
			bd(num);
		}else{
			scanf("%lld",&p);
			ok=0;ans=n+1;
			int xs=0;
			int g=0;
			for(int i=1;i<=block_num;i++){
				int nxtg=gcd(g,b[i].g);
				if(nxtg!=g){
					ask1(i,xs,g);
					if(ok) break;
				}else if(p%g==0){
					if(p/g<=2147483647)	ask2(i,(p/g)^xs);
					if(ok){
						ask1(i,xs,g);
						break;
					}
				}
				xs^=b[i].xs;
				g=nxtg;
			}
			if(!ok) puts("no");
			else printf("%d\n",ans-1);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
