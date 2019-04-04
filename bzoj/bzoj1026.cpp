#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int f[15][10];
int ff[15][10];
int A,B;
char s[15];
int ask(int x){
	if(x<10) return x;
	int ret=0;
	int lg;
	sprintf(s,"%d",x);
	lg=strlen(s);
	for(int i=0;i<s[0]-'0';i++) ret+=ff[lg][i];
	for(int i=1;i<lg;i++){
		for(int j=0;j<s[i]-'0';j++){
			if(abs(s[i-1]-'0'-j)<2) continue;
			ret+=f[lg-i][j];
		}
		if(abs(s[i]-s[i-1])<2) break;
		if(i==lg-1) ret++;
	}
	return ret-1;
}
int main(){
	for(int i=0;i<=9;i++) f[1][i]=1,ff[1][i]=1;
	for(int i=2;i<=10;i++){
		for(int j=0;j<=9;j++){
			for(int k=0;k<=j-2;k++){
				f[i][j]+=f[i-1][k];
			}
			for(int k=j+2;k<=9;k++){
				f[i][j]+=f[i-1][k];
			}
			ff[i][j]=f[i][j];
		}
	}
	for(int i=2;i<=10;i++){
		ff[i][0]=0;
		for(int j=0;j<=9;j++) ff[i][0]+=ff[i-1][j];
	}
	scanf("%d%d",&A,&B);
	printf("%d\n",ask(B)-ask(A-1));
	return 0;
}
