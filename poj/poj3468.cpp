#include<iostream>
#include<cstdio>
//by zrt
//problem:POJ 3468 BIT
using namespace std;
//∑(a[i])=∑{d[i]*(x-i+1)}=∑{ d[i]*(x+1) - d[i]*i }=(x+1)*∑(d[i])-∑(d[i]*i)
long long n,q,d[100001],tmp,di[100001],l,r;
char x;
inline long long lowbit(long long x){ return x&(-x);} 
long long sum(long long x,long long* d){
	long long ret=0;
	while(x>0) ret+=d[x],x-=lowbit(x);
	return ret;
}
void pls(long long pos,long long x,long long* d){
	while(pos<=n) d[pos]+=x,pos+=lowbit(pos);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%lld%lld%lld",&n,&q,&tmp);
	d[1]=di[1]=tmp;
	for(long long i=2;i<=n;i++){
		scanf("%lld",&d[i]);d[i]-=tmp;tmp+=d[i];di[i]=d[i]*i;
	}
	for(long long i=1;i<n;i++)
		if((tmp=i+lowbit(i))<=n){
			d[tmp]+=d[i];di[tmp]+=di[i];
		}
	for(long long i=0;i<q;i++){
		scanf(" %c",&x);
		if(x=='Q'){
			scanf("%lld%lld",&l,&r);
			printf("%lld\n",(r+1)*sum(r,d)-sum(r,di)-l*sum(l-1,d)+sum(l-1,di));
		}else{
			scanf("%lld%lld%lld",&l,&r,&tmp);
			pls(l,tmp,d);pls(l,tmp*l,di);
			pls(r+1,-tmp,d);pls(r+1,-tmp*(r+1),di);
		}
	}
	return 0;
}
