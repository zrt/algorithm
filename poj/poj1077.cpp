#include<iostream>
#include<queue>
#include<cstdio>
//by zrt
//problem:
using namespace std;
const int MAXN=1000000;
int fa[MAXN];
char sta[MAXN];
bool cal[MAXN];
int f[]={1,1,2,6,24,120,720,5040,40320,362880};
inline int canto(int x){
	int p=0,c,i,j;
	int a[10];
	for(i=0;i<9;i++){
		a[i]=x%10;x/=10;
	}
	for(i=0;i<9;i++){
		c=0;
		for(j=i+1;j<9;j++){
			if(a[i]>a[j]) c++;
		}
		p+=c*f[9-i-1];
	}
	return p;
}
struct N{
	int x,w;
	int m,n;
	N(int a=0,int b=0,int c=0,int d=0){
		x=a,w=b;m=c,n=d;
	}
}t;
queue<N> q;
int aim=canto(123456780);
int pow[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
vector<char> v;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int x,p=0,k,m,n;
	char s[10];
	for(int i=0;i<9;i++){
		scanf("%s",s);
		if(s[0]=='x'){
			k=0;m=i/3;n=i%3;
		}else k=s[0]-'0';
		p*=10;p+=k;
	}
//	printf("%d\n%d",p,canto(p));
	k=canto(p);
	cal[k]=1;
	fa[k]=-1;
	q.push(N(p,k,m,n));
	while(!q.empty()){
		t=q.front();q.pop();
		int s;m=t.m;n=t.n;
		if(cal[aim]) break;
		if(m-1>=0){
			s=t.x;
			s+=((s/pow[(8-((m-1)*3+n))])%10)*pow[8-(m*3+n)];
			s-=((s/pow[(8-((m)*3+n))])%10)*pow[8-((m-1)*3+n)];
			k=canto(s);
			if(!cal[k]) {
				cal[k]=1;
				fa[k]=t.w;
				sta[k]='u';
				q.push(N(s,k,m-1,n));
			}
		}
		if(m+1<3){
			s=t.x;
			s+=((s/pow[(8-((m+1)*3+n))])%10)*pow[8-(m*3+n)];
			s-=((s/pow[(8-((m)*3+n))])%10)*pow[8-((m+1)*3+n)];
			k=canto(s);
			if(!cal[k]) {
				cal[k]=1;
				fa[k]=t.w;
				sta[k]='d';
				q.push(N(s,k,m+1,n));
			}
		}
		if(n-1>=0){
			s=t.x;
			s+=((s/pow[(8-((m)*3+(n-1)))])%10)*pow[8-(m*3+n)];
			s-=((s/pow[(8-((m)*3+n))])%10)*pow[8-((m)*3+(n-1))];
			k=canto(s);
			if(!cal[k]) {
				cal[k]=1;
				fa[k]=t.w;
				sta[k]='l';
				q.push(N(s,k,m,n-1));
			}
		}
		if(n+1<3){
			s=t.x;
			s+=((s/pow[(8-((m)*3+(n+1)))])%10)*pow[8-(m*3+n)];
			s-=((s/pow[(8-((m)*3+n))])%10)*pow[8-((m)*3+(n+1))];
			k=canto(s);
			if(!cal[k]) {
				cal[k]=1;
				fa[k]=t.w;
				sta[k]='r';
				q.push(N(s,k,m,n+1));
			}
		}
	}
//	printf("HAHAHA");
	if(!cal[aim]){
		puts("unsolvable");
	}else{
		for(int i=aim;fa[i]!=-1;i=fa[i]){
			v.push_back(sta[i]);
		}
		for(size_t i=v.size()-1;i!=0;i--){
			putchar(v[i]);
		}
		putchar(v[0]);
	}
	return 0;
}
