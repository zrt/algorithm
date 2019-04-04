#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
char s[10];
bool del[100005];
int a[100005],b[100005];
int c[2000050];
#define lowbit(x) ((x)&-(x))
const int zero=1000005;
void add(int pos,int d){
	while(pos<=2000011){
		c[pos]+=d;
		pos+=lowbit(pos);
	}
}
int ask(int pos){
	int ret=0;
	while(pos>0){
		ret+=c[pos];
		pos-=lowbit(pos);
	}
	return ret;
}
void do_(int i,int d){
	if(a[i]==0){
		if(b[i]<0){
			add(1,d);
		}
	}else{
		if(a[i]>0){
			int k=b[i]/a[i];
			if(k*a[i]<=b[i])k++;
			k=max(1-zero,k);
			add(k+zero,d);
		}else{
			int k=(b[i])/a[i];
			//k--;
		//	printf("%d\n",k);
			if(k*a[i]<=b[i]) k--;
		//	printf("%d\n",k);
			k++;
		//	printf("%d\n",k);
			k=max(1-zero,k);
			add(1,d);
			add(k+zero,-d);
		}
	}
}
int cc;
int main(){
	scanf("%d",&n);
	for(int i=0,x,y;i<n;i++){
		scanf("%s",s);
		if(s[0]=='A'){
			cc++;
			scanf("%d%d%d",&a[cc],&x,&y);
			b[cc]=y-x;
			do_(cc,1);
		}else if(s[0]=='D'){
			scanf("%d",&x);
			if(!del[x]){
				del[x]=1;
				do_(x,-1);
			}
		}else if(s[0]=='Q'){
			scanf("%d",&x);
			printf("%d\n",ask(x+zero));
		}
	}
	
	
	return 0;
}
