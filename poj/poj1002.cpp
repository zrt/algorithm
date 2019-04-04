#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
//by zrt
//problem:
using namespace std;
char a[100];
int b[100005]={0};
int numb(char x){
	x=toupper(x); 
	if(x=='A'||x=='B'||x=='C') return 2;
	if(x=='D'||x=='E'||x=='F') return 3;
	if(x=='G'||x=='H'||x=='I') return 4;
	if(x=='J'||x=='K'||x=='L') return 5;
	if(x=='M'||x=='N'||x=='O') return 6;
	if(x=='P'||x=='R'||x=='S') return 7;
	if(x=='T'||x=='U'||x=='V') return 8;
	if(x=='W'||x=='X'||x=='Y') return 9;
}
int f(){
	int ans=0;
	int l=strlen(a);
	for(int i=0;i<l;i++){
		if(isdigit(a[i])){
			ans*=10;
			ans+=a[i]-'0';
		}
		if(isalpha(a[i])){
//			if(a[i]==)
			ans*=10;
			ans+=numb(a[i]);
		}
	}
	return ans;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",a);
		b[i]=f();
	}
	sort(b,b+n);
	int last=b[0],count=0,ok=1;
	for(int i=1;i<n;i++){
		if(b[i]==last){
			count++;
		}
		else{
			if(count){
				int f1=b[i-1]/10000;
				int f2=b[i-1]%10000;
				printf("%03d-%04d %d\n",f1,f2,count+1);// keng a!!! 03d - -...
				count=0;
				ok=0;
			}
			last=b[i];
		}
	}
	if(count){
				int f1=b[n-1]/10000;
				int f2=b[n-1]%10000;
				printf("%03d-%04d %d\n",f1,f2,count+1);
				count=0;
				ok=0;
			}
	if(ok) printf("No duplicates.\n");
	return 0;
}
