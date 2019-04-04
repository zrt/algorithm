#include<cstdio>
using namespace std;
int H[9],P[100],X[100],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
//0 有挡板 
void find(int p,int x,int now,int t){
	if(x==4) add(p,t);
	if(x>3) return;
	if((now&1)==0) find(p,x+1,now>>1,t+(1<<(x-1)));// 没挡板 
	if((now&3)==0) find(p,x+2,now>>2,t);
	if((now&1)!=0) find(p,x+1,now>>1,t);
}
int n,m;
inline void mul(int a[][8],int b[][8]){
	int c[8][8]={0};
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			for(int k=0;k<8;k++){
				c[i][j]+=a[i][k]*b[k][j];
			//	if(c[i][j]>=m) c[i][j]%=m;
			}
		}
	}
	for(int i=0;i<8;i++) for(int j=0;j<8;j++) a[i][j]=c[i][j];
}
int f[8][8];
int p[8][8];
int main(){
	for(int i=0;i<1<<4;i++)
		find(i,1,i,0);
	for(int i=0;i<1<<4;i++){
		for(int j=H[i];j;j=X[j]){
			f[i][P[j]]=1;
		}
	}
	while(scanf("%d",&n)&&(~n)){
		int t[8][8]={0};
		t[0][0]=1;
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				p[i][j]=f[i][j];
			}
		}
		while(n){
			if(n&1) mul(t,p);
			mul(p,p);
			n>>=1; 
		}
		printf("%d\n",t[0][0]);
	}
	
	return 0;
}