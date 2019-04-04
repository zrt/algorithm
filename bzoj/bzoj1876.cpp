#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct NUM{
	int a[2005];//8 bit
	int l;
	bool notzero(){
		return l>=0;
	}
	void div2(){
		int r=0;
		for(int i=l;i>=0;i--){
			r=r*100000000+a[i];
			a[i]=r/2;
			r%=2;
		}
		while(l>=0&&a[l]==0) l--;
	}
	void sub(const NUM&B){
		const int *b=B.a;
		for(int i=0;i<=l;i++){
			a[i]=a[i]-b[i];
			if(a[i]<0) a[i+1]--,a[i]+=100000000;
		}
		while(l>=0&&a[l]==0) l--;
	}
	friend bool operator < (const NUM&a,const NUM&b){
		if(a.l!=b.l) return a.l<b.l;
		for(int i=a.l;i>=0;i--){
			if(a.a[i]<b.a[i]) return 1;
			else if(a.a[i]>b.a[i]) return 0;
		}
		return 0;
	}
	void read(){
		static char s[10005];
		scanf("%s",s);
		int L=strlen(s);
		reverse(s,s+L);
		for(int i=0;i<8;i++) s[i+L]='0';
		for(int i=0;i<L;i+=8){
			reverse(s+i,s+i+8);
			for(int j=0;j<8;j++) a[i/8]=a[i/8]*10+s[i+j]-'0';
		}
		l=2000;
		while(l>=0&&a[l]==0) l--;
	}
	void out(){
		int top=l+1;
		while(top>0&&a[top]==0) top--;
		printf("%d",a[top]);top--;
		while(top>=0) printf("%08d",a[top]),top--;
		puts("");
	}
	void mul2(int k){
		while(k--){
			for(int i=0;i<=l;i++) a[i]*=2;
			for(int i=0;i<=l;i++) a[i+1]+=a[i]/100000000,a[i]%=100000000;
			l=2000;
			while(l>=0&&a[l]==0) l--;
		}
	}
}a,b,c;
NUM gcd(NUM A,NUM B){
	int num=0;//2
	NUM*a=&A;
	NUM*b=&B;
	//printf("%u %u %u %u\n",sizeof(a),sizeof (b),sizeof A,sizeof B);
	//for(int i=0;i<100000;i++) swap(a,b);
//	a->out();
//	b->out();
	if(*a<*b) swap(a,b);
	while(b->notzero()){
	//	a->out();
	//	b->out();
		if((a->a[0]&1)==0&&(b->a[0]&1)==0){
			num++;
			a->div2();
			b->div2();
		}else if((a->a[0]&1)==0){
			a->div2();
		}else if((b->a[0]&1)==0){
			b->div2();
		}else{
			a->sub(*b);
		}
		if(*a<*b) swap(a,b);
	}
	
	(*a).mul2(num);
	return *a;
}
int main(){
	a.read();
	b.read();
	c=gcd(a,b);
	c.out();
	return 0;
}
