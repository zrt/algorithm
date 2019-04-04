#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int mod=1004535809;
int g=3;
LL pow(LL a,LL b,LL p){
	LL ret=1%p;
	while(b){
		if(b&1) ret=ret*a%p;
		b>>=1;
		a=a*a%p;
	}
	return ret;
}
int jie(int x,int p){
	int mn=p;
	int mod=p;
	p=p-1;
	int lim=sqrt(p+1);
	for(int i=1;i<=lim;i++){
		if(p%i==0){
			if(pow(x,i,mod)==1) mn=min(mn,i);
			if(pow(x,p/i,mod)==1) mn=min(mn,p/i);
		}
	}
	return mn;
}
int yuangen(int p){
	int g;
	for(int i=1;;i++){
		if(jie(i,p)==p-1){
			g=i;
			break;
		}
	}
	return g;
}
int n,m,x,num,G;
int a[8005];
map<int,int> mp;
int bsgs_lim;
int BSGS(int a,int c){
	// solve a^b==c%m
	int tmp=c,step=pow(pow(a,bsgs_lim,m),m-2,m);
	for(int i=0;i<=bsgs_lim;i++){
		if(mp.find(tmp)!=mp.end()) return i*bsgs_lim+mp[tmp];
		tmp=tmp*1LL*step%m;
	}
	return 1/0; 
}
int f[35][40000];
int ans[40000];

// PASTE
//---------
int rev[40000];
int w[40000];
int Rev(int x,int bit){
	int ret=0;
	for(int i=0;i<bit;i++){
		if(x&(1<<i)) ret|=1<<(bit-i-1);
	}
	return ret;
}
void fft(int*f,int bit,int o){
// len=1<<bit
for(int i=0;i<1<<bit;i++) if(rev[i]>i) swap(f[rev[i]],f[i]);
//for(int i=0;i<4;i++) printf("%d\n",f[i]);
for(int i=1;i<=bit;i++){
//Length = 2^i
for(int j=0;j<1<<bit;j+=1<<i){
int W=0;
for(int k=0;k<1<<(i-1);k++){
int tmp=f[j+k];
f[j+k]=(f[j+k]+w[W]*1LL*f[j+k+(1<<(i-1))])%mod;
f[j+k+(1<<(i-1))]=(tmp-w[W]*1LL*f[j+k+(1<<(i-1))]%mod+mod)%mod;
W+=o*(1<<(bit-i));
if(W<0) W+=1<<bit;
}
}
}
if(o==-1){
int ni=pow(1<<bit,mod-2,mod);
for(int i=0;i<1<<bit;i++) f[i]=f[i]*1LL*ni%mod;
}
}


//----------
int main(){
//	freopen("in","r",stdin);
//	freopen("out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&x,&num);
	for(int i=0;i<num;i++) scanf("%d",&a[i]);
	G=yuangen(m);
	bsgs_lim=sqrt(m)+1;
	int tmp=1;
	for(int i=0;i<=bsgs_lim;i++){
		if(mp.find(tmp)==mp.end())mp[tmp]=i;
		tmp=tmp*1LL*G%m;
	}
	for(int i=0;i<num;i++) if(a[i]) a[i]=BSGS(G,a[i]);else a[i]=-1;
	for(int i=0;i<num;i++) if(a[i]>=0)f[0][a[i]]=1;
	int bit=0;
	for(bit=0;1<<bit<=m-1;bit++);
	bit++;
	w[0]=1;w[1]=pow(g,(mod-1)/(1<<bit),mod);
	for(int i=2;i<1<<bit;i++) w[i]=w[i-1]*1LL*w[1]%mod;
	for(int i=0;i<1<<bit;i++) rev[i]=Rev(i,bit);
	bit--;
	for(int i=1;i<30;i++){
		fft(f[i-1],bit+1,1);
		for(int j=0;j<(1<<(bit+1));j++) f[i][j]=f[i-1][j]*1LL*f[i-1][j]%mod;
		fft(f[i],bit+1,-1);
		for(int j=0;j<m-1;j++) f[i][j]=(f[i][j]+f[i][j+m-1])%mod,f[i][j+m-1]=0;
	}
	fft(f[29],bit+1,1);
	ans[0]=1;
	for(int i=0;i<30;i++){
		if(n&(1<<i)){
			fft(ans,bit+1,1);
			for(int j=0;j<1<<(bit+1);j++){
				ans[j]=ans[j]*1LL*f[i][j]%mod;
			}
			fft(ans,bit+1,-1);
			for(int j=0;j<m-1;j++) ans[j]=(ans[j]+ans[j+m-1])%mod,ans[j+m-1]=0;
		}
	}
	printf("%d\n",ans[BSGS(G,x)]);
	return 0;
}
