#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q;
char s[10];
const int mod=19940417;
int a[50005];
int c[50005<<2][21];
int add[50005<<2];
bool rev[50005<<2];
int C[50005][25];
void up(int o){
	c[o][0]=1;
	for(int i=1;i<=20;i++){
		c[o][i]=0;
		for(int j=0;j<=i;j++){
			c[o][i]+=c[o<<1][j]*1LL*c[o<<1|1][i-j]%mod;
			c[o][i]%=mod;
		}
	}
}
void bd(int o,int l,int r){
	if(l==r){
		c[o][0]=1;
		c[o][1]=a[l];
	}else{
		int mid=(l+r)>>1;
		bd(o<<1,l,mid);
		bd(o<<1|1,mid+1,r);
		up(o);
	}
}
void do_rev(int o){
	rev[o]^=1;
	add[o]*=-1;
	for(int i=1;i<=20;i+=2) if(c[o][i]) c[o][i]=-c[o][i];
}
void do_add(int o,int w,int l,int r){
	int a[21];
	int pw[21];
	add[o]+=w;
	memcpy(a,c[o],sizeof a);
	c[o][0]=1;
	pw[0]=1;
	int len=r-l+1;
	for(int i=1;i<=20;i++) pw[i]=pw[i-1]*1LL*w%mod;
	for(int i=1;i<=20;i++){
		c[o][i]=0;
		for(int j=0;j<=i;j++){
			c[o][i]+=C[len-(i-j)][j]*1LL*pw[j]%mod*a[i-j]%mod;
			c[o][i]%=mod;
		}
		//c[o][i]=(c[o][i]+pw[i])%mod;
	}
}
void down(int o,int l,int r){
	if(rev[o]){
		do_rev(o<<1);
		do_rev(o<<1|1);
		rev[o]=0;
	}
	if(add[o]){
		int mid=(l+r)>>1;
		do_add(o<<1,add[o],l,mid);
		do_add(o<<1|1,add[o],mid+1,r);
		add[o]=0;
	}
}
int ans[21];
void do_ask(int o){
	int a[21];
	memcpy(a,ans,sizeof ans);
	ans[0]=1;
	for(int i=1;i<=20;i++){
		ans[i]=0;
		for(int j=0;j<=i;j++){
			ans[i]+=a[j]*1LL*c[o][i-j]%mod;
			ans[i]%=mod;
		}
	}
}
void ask(int o,int l,int r,int L,int R){
	if(l==L&&r==R){
		do_ask(o);
	}else{
		int mid=(l+r)>>1;
		down(o,l,r);
		if(R<=mid){
			ask(o<<1,l,mid,L,R);
		}else if(L>mid){
			ask(o<<1|1,mid+1,r,L,R);
		}else{
			ask(o<<1,l,mid,L,mid);
			ask(o<<1|1,mid+1,r,mid+1,R);
		}
	}
}
void Rev(int o,int l,int r,int L,int R){
	if(l==L&&r==R){
		do_rev(o);
	}else{
		int mid=(l+r)>>1;
		down(o,l,r);
		if(R<=mid){
			Rev(o<<1,l,mid,L,R);
		}else if(L>mid){
			Rev(o<<1|1,mid+1,r,L,R);
		}else{
			Rev(o<<1,l,mid,L,mid);
			Rev(o<<1|1,mid+1,r,mid+1,R);
		}
		up(o);
	}
}
int w;
//1 3 4 4 5
void Add(int o,int l,int r,int L,int R){
	if(l==L&&r==R){
		do_add(o,w,l,r);
	}else{
		int mid=(l+r)>>1;
		down(o,l,r);
		if(R<=mid){
			Add(o<<1,l,mid,L,R);
		}else if(L>mid){
			Add(o<<1|1,mid+1,r,L,R);
		}else{
			Add(o<<1,l,mid,L,mid);
			Add(o<<1|1,mid+1,r,mid+1,R);
		}
		up(o);
	}
}
int main(){
	C[0][0]=1;
	for(int i=1;i<=50005;i++){
		C[i][0]=1;
		for(int j=1;j<=20;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	bd(1,1,n);
	while(q--){
		int a,b,c;
		scanf("%s",s);
		if(s[0]=='I'){
			scanf("%d%d%d",&a,&b,&c);
			w=c;
			Add(1,1,n,a,b);
		}else if(s[0]=='R'){
			scanf("%d%d",&a,&b);
			Rev(1,1,n,a,b);
		}else{
			scanf("%d%d%d",&a,&b,&c);
			memset(ans,0,sizeof ans);
			ans[0]=1;
			ask(1,1,n,a,b);
			printf("%d\n",(ans[c]+mod)%mod);
		}
	}
	return 0;
}
