#include<cstdio>
#include<cstring>
#define MOD(x) {if((x)>=mod) (x) %= mod ;}
using namespace std;
const int MAX = 100005;
long long _l,k,_r,_c,addv[MAX*3],cheng[MAX*3],x[MAX*3],a[MAX],n,L[MAX*3],R[MAX*3];
int w,m;
long long mod;
//    if(x[o]>=mod) x[o]%=mod;
void mk(int o,int l,int r){
	L[o]=l;R[o]=r;
	cheng[o]=1;
	if(l!=r){
		int m=(l+r)>>1;
		mk(o<<1,l,m);mk((o<<1)+1,m+1,r);
	}
	x[o]=(l==r)?a[l]:(x[o<<1]+x[(o<<1)+1]);
	MOD(x[o]);
}
void pushdown(int o){
	//cheng
	if(cheng[o]!=1){
		//left
		x[o<<1]*=cheng[o];MOD(x[o<<1]);
		cheng[o<<1]*=cheng[o];MOD(cheng[o<<1]);
		addv[o<<1]*=cheng[o];MOD(addv[o<<1]);
		//right
		x[(o<<1)+1]*=cheng[o];MOD(x[(o<<1)+1]);
		cheng[(o<<1)+1]*=cheng[o];MOD(cheng[(o<<1)+1]);
		addv[(o<<1)+1]*=cheng[o];MOD(addv[(o<<1)+1]);
		cheng[o]=1;
	}
	if(addv[o]!=0){
		//left
		x[o<<1]+=addv[o]*(R[o<<1]-L[o<<1]+1);MOD(x[o<<1]);
		addv[o<<1]+=addv[o];MOD(addv[o<<1]);
		//right
		x[(o<<1)+1]+=addv[o]*(R[(o<<1)+1]-L[(o<<1)+1]+1);MOD(x[(o<<1)+1]);
		addv[(o<<1)+1]+=addv[o];MOD(addv[(o<<1)+1]);
		addv[o]=0;
	}
}
void c(int o){
	if(_l<=L[o]&&_r>=R[o]){
		x[o]*=_c;MOD(x[o]);
		cheng[o]*=_c;MOD(cheng[o]);
		addv[o]*=_c;MOD(addv[o]);
	}else{
		pushdown(o);
		int m=(L[o]+R[o])>>1;
		if(_l<=m) c(o<<1);
		if(_r>m) c((o<<1)+1);
		x[o]=x[o<<1]+x[(o<<1)+1];
		MOD(x[o]);
	}
}
void j(int o){
	if(_l<=L[o]&&_r>=R[o]){
		x[o]+=_c*(R[o]-L[o]+1);MOD(x[o]);
		addv[o]+=_c;MOD(addv[o]);
	}else{
		pushdown(o);
		int m=(L[o]+R[o])>>1;
		if(_l<=m) j(o<<1);
		if(_r>m) j((o<<1)+1);
		x[o]=x[o<<1]+x[(o<<1)+1];
		MOD(x[o]);
	}
}
long long ask(int o){
	long long ans=0;
	if(_l<=L[o]&&_r>=R[o]){
		return x[o];
	}else{
		pushdown(o);
		int m=(L[o]+R[o])>>1;
		if(_l<=m) ans+=ask(o<<1);
		MOD(ans);
		if(_r>m) ans+=ask((o<<1)+1);
		MOD(ans);
		x[o]=x[o<<1]+x[(o<<1)+1];MOD(x[o]);
		return ans;
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	scanf("%lld%lld",&n,&mod);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	mk(1,1,n);
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%lld%lld%lld",&k,&_l,&_r);
		if(k==1) {
			scanf("%lld",&_c);
			c(1);
		}
		else if(k==2) {
			scanf("%lld",&_c);
			j(1);
		}
		else printf("%lld\n",ask(1)); 
	}
	return 0;
}
