#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[15];
int f[1030][1005];
int tt,d,L;
int cnt[10];
int jiecheng[11];
int main(){
	jiecheng[0]=1;
	for(int i=1;i<=10;i++) jiecheng[i]=jiecheng[i-1]*i;
	scanf("%d",&tt);
	while(tt--){
		scanf("%s%d",s,&d);
		L=strlen(s);
		memset(f,0,sizeof f);
		f[0][0]=1;
		for(int i=0;i<(1<<L);i++){
			for(int j=0;j<d;j++){
				if(f[i][j]){
					for(int k=0;k<L;k++){
						if(!(i&(1<<k))){
							f[i|(1<<k)][(j*10+s[k]-'0')%d]+=f[i][j];
						}
					}
				}
			}
		}
		int ans=f[(1<<L)-1][0];
		memset(cnt,0,sizeof cnt);
		for(int i=0;i<L;i++) cnt[s[i]-'0']++;
		for(int i=0;i<10;i++) ans/=jiecheng[cnt[i]];
		printf("%d\n",ans);
	}
	
	return 0;
}
