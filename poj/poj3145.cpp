#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long LL;
typedef long double ld;
void read(int&x){scanf("%d",&x);}
void read(long double&x){double xx;scanf("%lf",&xx);x=xx;}
void read(LL&x){scanf("%lld",&x);}
void read(char*s){scanf("%s",s);}

int n,kase;
char s[10];
int mn[500000*4];
int ans[800];
int a[40005];
int to[500005];
inline void add(int o,int l,int r,int pos){
	if(l==r){
		mn[o]=pos;
	}else{
		int mid=(l+r)>>1;
		if(pos<=mid) add(o<<1,l,mid,pos);
		else add(o<<1|1,mid+1,r,pos);
		mn[o]=min(mn[o<<1],mn[o<<1|1]);
	}
}
inline int ask(int o,int l,int r,int L,int R){
	if(l==L&&r==R){
		return mn[o];
	}else{
		int mid=(l+r)>>1;
		if(R<=mid) return ask(o<<1,l,mid,L,R);
		else if(L>mid) return ask(o<<1|1,mid+1,r,L,R);
		else return min(ask(o<<1,l,mid,L,mid),ask(o<<1|1,mid+1,r,mid+1,R));
	}
}
int main(){
	int lim=sqrt(500000);
	while(scanf("%d",&n),n){
		printf("Case %d:\n",++kase);
		memset(ans,-1,sizeof ans);
		memset(mn,0x3f,sizeof mn);
		int tot=0;
		bool ok=0;
		for(int i=0,x;i<n;i++){
			scanf("%s%d",s,&x);
			if(s[0]=='B'){
				ok=1;
				to[x]=++tot;
				add(1,1,500000,x);
				for(int i=1;i<=lim;i++){
					if(ans[i]==-1||x%i<=ans[i]%i){
						ans[i]=x;
					}
				}
			}else{
				if(!ok){
					puts("-1");
					continue;
				}
				if(x<=lim){
					printf("%d\n",to[ans[x]]);
				}else{
					int p=(500000-1)/x+1;
					int ans=-1;
					for(int i=0;i<p;i++){
						int mn=ask(1,1,500000,max(i*x,1),min((i+1)*x,500000));
						if(mn==0x3f3f3f3f) continue;
						if(ans==-1||ans%x>mn%x) ans=mn;
						else if(ans%x==mn%x&&to[ans]<to[mn]) ans=mn;
					}
					printf("%d\n",to[ans]);
				}
			}
		}
		
		puts("");
	}
	return 0;
}
