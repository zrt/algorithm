#include<iostream>
#include<cstdio>
#include<string>
//by zrt
//problem:
using namespace std;
char s[64][20];
int r[64]={0};
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%s",s[i]);
	for(int i=0;i<n;i++){
		r[i]=i+1;
	}
	r[n-1]=0;
	int x,y;
	
	scanf("%d,%d",&x,&y);
	int i=x-1;
	x=n;
	if(y==1){
		while(x--){
			puts(s[i%n]);i++;
		}
		return 0;
	}
	while(x--){
		for(int j=1;j<y-1;j++) i=r[i];
		int j=i;
		i=r[i];
		puts(s[i]);
		r[j]=r[i];
		i=r[i];
	}
	return 0;
}
