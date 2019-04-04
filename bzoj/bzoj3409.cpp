#include<iostream>
#include<cstdio>
#include<cstring>
//by zrt
//problem:
using namespace std;
inline int scan(){int tmp=0,sign=1;char x;while(((x=getchar())<'0'||x>'9')&&x!='-');if(x=='-') sign=-1;else tmp=x-'0';while((x=getchar())>='0'&&x<='9') tmp*=10,tmp+=x-'0';if(sign==1) return tmp;else return (-tmp);}
char a[100],b[100];
int la,lb,tmp;
bool ok[100],ko[100];
bool stp(int x1,int x2,int y1,int y2){
	while(x1<=x2&&y1<=y2){
		if(a[x1]!=b[y1]) return false;
		x1++;y1++;
	}
	return true;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%s%s",a,b);
	la=strlen(a);
	lb=strlen(b);
	int maxx=0,x1,x2,y1,y2;
	for(int i=0;i<lb;i++){
		if(a[0]==b[i]) ok[i]=1;
	}
	for(int i=0;i<lb;i++){
		if(!ok[i]) continue;
		x1=0,x2=lb-i-1,y1=i,y2=lb-1;
		if(x2>=la) continue;
		if(stp(x1,x2,y1,y2)){
			maxx=max(maxx,lb-i);
		}
	}
	for(int i=0;i<la;i++){
		if(b[0]==a[i]) ko[i]=1;
	}
	for(int i=0;i<la;i++){
		if(!ko[i]) continue;
		y1=0,y2=la-i-1,x1=i,x2=la-1;
		if(y2>=lb) continue;
		if(stp(x1,x2,y1,y2)){
			maxx=max(maxx,la-i);
		}
	}
	printf("%d",maxx);
	return 0;
}
