#include<iostream>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<algorithm>
//by zrt
//problem:
using namespace std;
inline int scan(){int tmp=0,sign=1;char x;while(((x=getchar())<'0'||x>'9')&&x!='-');if(x=='-') sign=-1;else tmp=x-'0';while((x=getchar())>='0'&&x<='9') tmp*=10,tmp+=x-'0';if(sign==1) return tmp;else return (-tmp);}
long long sq[3162278];
long long a[100005];//num
long long num[100005];
int nxt[100005];
inline int lowbit(int x){
	return x&-x;
}
int n,tmp;
inline void add(int pos,long long k){
	while(pos<=n){
		a[pos]+=k;pos+=lowbit(pos);
	}
}
inline long long sum(int pos){
	long long ret=0;
	while(pos>0){
		ret+=a[pos];pos-=lowbit(pos);
	}
	return ret;
}
int find(int x){
	return x==nxt[x]?x:nxt[x]=find(nxt[x]);
}
int q,x,y,z;
inline long long sqr(long long x){
	int pos=upper_bound(sq+1,sq+3162278,x)-sq;
	return (long long)(pos-1);
}
int main(){
	for(long long i=1;i<=3162277;i++){
		sq[i]=i*i;
	}
	n=scan();
	//scanf("%d",&n);
	for(int i=1;i<=n;i++) //num[i]=a[i]=scan();
	{	
		scanf("%lld",&a[i]);num[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==1) nxt[i]=i+1;
		else nxt[i]=i;
	}
	nxt[n+1]=n+1;
	for(int i=1;i<n;i++){
		if((tmp=i+lowbit(i))<=n){
			a[tmp]+=a[i];
		}
	}
	q=scan();
	//scanf("%d",&q);
	long long temp;
	while(q--){
		scanf("%d%d%d",&z,&x,&y);
		if(x>y) x^=y^=x^=y;
		if(z){
			printf("%lld\n",sum(y)-sum(x-1));
		}else{
			for(int i=find(x);i<=y;i=find(i+1)){
				temp=sqr(num[i]);
				add(i,temp-num[i]);
				num[i]=temp;
				if(num[i]==1){
					nxt[i]=i+1;
				}
			}
		}
	}
	return 0;
}
