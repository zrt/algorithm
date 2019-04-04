/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
int T;
char s[1200][1200];
int nxt[1200];
int l[1200];
int L,R,M;
int minx;
int n;
bool ok[120];
bool judge(int p){
	char S[2][120];
	int siz=l[minx]-p,tot;
	
	for(int i=0;i<=siz;i++){
		tot=1;memset(ok,0,sizeof ok);
		for(int j=0;j<p;j++){
			S[1][p-j-1]=S[0][j]=s[minx][i+j];
		}
		for(int as=0;as<2;as++){
			int j=-1;
			nxt[0]=j;
			for(int k=1;k<p;k++){
				while((~j)&&S[as][j+1]!=S[as][k]) j=nxt[j];
				if(S[as][j+1]==S[as][k]) j++;
				nxt[k]=j;
			}
			for(int k=0;k<n;k++){
				if(k==minx) continue;
				if(ok[k]) continue;
				j=-1;
				for(int v=0;v<l[k];v++){
					while((~j)&&S[as][j+1]!=s[k][v]) j=nxt[j];
					if(S[as][j+1]==s[k][v]) j++;
					if(j==p-1) {
						tot++;
						ok[k]=1;break;
					}
				}
			}
			if(tot==n) return 1;
		}
	}
	return 0;
	
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int minl=~0U>>1;
		for(int i=0;i<n;i++){
			scanf("%s",s[i]);
			l[i]=strlen(s[i]);
			if(l[i]<minl){
				minl=l[i];
				minx=i;
			}
		}
		L=0;R=minl+1;
		while(R>L+1){
			M=(L+R)>>1;
			if(judge(M)){
				L=M;
			}else R=M;
		}
		printf("%d\n",L);
	}
	return 0;
}
