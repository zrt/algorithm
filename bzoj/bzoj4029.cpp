#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int tt;
int l,r;
int pw[10];
int ask(int l,int r,int num){
	int p=l/pw[num];
	long long k=(p/10*10+5)*1LL*pw[num];
	if(k>=l&&k<=r) return k;
	if(l%pw[num]==0) return l;
	return ((l/pw[num]+1)*pw[num]);
}
bool check(int l,int r,int num){
	if(pw[num]>r) return 0;
	if(l%pw[num]==0) return 1;
	if(((l/pw[num])+1)*pw[num]<=r) return 1;
	return 0;
}
char s[100];
int calc(int x){
	while(x%10==0)x/=10;
	sprintf(s,"%d",x);
	int L=strlen(s);
	if(s[L-1]=='5') return 2*L-1;
	else return 2*L;
}
int solve(int l,int r){
	int mn=0x3f3f3f3f,p;
	for(int i=9;i>=0;i--){
		if(check(l,r,i)){
			int tmp=ask(l,r,i);
			int tmpp=calc(tmp);
			if(tmpp<mn) p=tmp,mn=tmpp;
			else if(tmpp==mn&&tmp<p) p=tmp;
		}
	}
	return p;
}
int main(){
//	freopen("absurd.in","r",stdin);
//	freopen("absurd.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<=9;i++) pw[i]=pw[i-1]*10;
	scanf("%d",&tt);
	while(tt--){
		scanf("%d%d",&l,&r);
		printf("%d\n",solve(l,r));
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
