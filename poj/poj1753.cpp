#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
//by zrt
//problem:
using namespace std;
char s[5][10];
int sta[262144],aim;
queue<int> Q;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	memset(sta,-1,sizeof sta);
	for(int i=0;i<4;i++){
		scanf("%s",s[i]);
	}
	int init=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(s[i][j]=='b'){
				init|=1<<(i*4+j);
			}
		}
	}
	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
	aim|=1<<(i*4+j);
	if(init==aim||init==0){
		puts("0");return 0;
	}
	sta[init]=0;
	Q.push(init);
	while(!Q.empty()){
		int k=Q.front();Q.pop();
		int p,q;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				p=k;q=1<<(i*4+j);
				if(i-1>=0){
					q|=1<<(4*(i-1)+j);
				}
				if(i+1<4){
					q|=1<<(4*(i+1)+j);
				}
				if(j-1>=0){
					q|=1<<(4*i+j-1);
				}
				if(j+1<4){
					q|=1<<(4*i+j+1);
				}
				p^=q;
				if(sta[p]==-1){
					sta[p]=sta[k]+1;
					Q.push(p);
					if(p==aim||p==0) break;
				}
			}
		} 
	}
	if(sta[aim]==-1&&sta[0]==-1){
		puts("Impossible");
	}else if(sta[aim]==-1){
		printf("%d",sta[0]);
	}else if(sta[0]==-1){
		printf("%d",sta[aim]);
	}else printf("%d",min(sta[0],sta[aim]));
	return 0;
}
