#include<iostream>
#include<cstdio>
//by zrt
//problem:
using namespace std;
char s[5][5]; 
int R[4],C[4];
int b[20];
int r[150000],c[150000],last[150000];
bool is[150000];
int q[150000],h,t,top;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	for(int i=0;i<4;i++){
		scanf("%s",s[i]);
	}
	int k=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(s[i][j]=='+'){
				k|=1<<(i*4+j);
			}
		}
	}
	if(k==0) puts("0");
	for(int i=0;i<16;i++){
		b[i]=1<<i;
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			R[i]|=b[i*4+j];
			C[i]|=b[j*4+i];
		}
	} 
	q[t++]=k;
	is[k]=1;
	last[k]=-1;
	int p;
	while(h!=t){
		k=q[h++];
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				p=k^R[i]^C[j]^b[i*4+j];
				if(!is[p]){
					is[p]=1;r[p]=i+1;c[p]=j+1;
					last[p]=k;
					q[t++]=p;
					if(!p) 
					goto end;
				}
			}
		}
	}
	end:;
	for(int i=0;last[i]!=-1;i=last[i]){
		q[top++]=i;
	}

	printf("%d\n",top);
	while(top){
		top--;
		printf("%d %d\n",r[q[top]],c[q[top]]);
		/*
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(q[top]&(1<<(i*4+j))) putchar('+');
				else putchar('-');
			}
			puts("");
		}*/
	}
	return 0;
}
