#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,mod;
char s[25];
int nxt[25];
struct N{
	int a[25][25];
	void clear(){
		memset(a,0,sizeof a);
	}
	friend N operator * (const N&a,const N&b){
		N c;
		c.clear();
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				for(int k=0;k<m;k++){
					c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j])%mod;
				}
			}
		}
		return c;
	}
}p,st;
N pow(N a,int b){
	N ret;
	ret.clear();
	for(int i=0;i<m;i++) ret.a[i][i]=1;
	while(b){
		if(b&1) ret=ret*a;
		a=a*a;
		b>>=1;
	}
	return ret;
}

int main(){
	scanf("%d%d%d%s",&n,&m,&mod,s+1);
	int j=0;
	for(int i=2;i<=m;i++){
		while(j&&s[i]!=s[j+1]) j=nxt[j];
		if(s[i]==s[j+1]) j++;
		nxt[i]=j;
	}
	//for(int i=1;i<=m;i++) printf("%d ",nxt[i]);
	// fi0,fi1,fi2...fim-1 
	for(int i=0;i<m;i++){
		for(int j=0;j<10;j++){
			int k=i;
			while(k&&s[k+1]!='0'+j) k=nxt[k];
			if(s[k+1]=='0'+j) k++;
			p.a[i][k]++;
		}
	}
	//for(int i=0;i<m;i++,puts("")) for(int j=0;j<m;j++) printf("%d ",p.a[i][j]);
	st.a[0][0]=1;
	p=pow(p,n);
	//for(int i=0;i<m;i++,puts("")) for(int j=0;j<m;j++) printf("%d ",p.a[i][j]);
	st=st*p;
	int ans=0;
	for(int i=0;i<m;i++) ans=(ans+st.a[0][i])%mod;
	printf("%d\n",ans);
	return 0;
}
