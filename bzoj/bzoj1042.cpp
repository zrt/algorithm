#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int c[5],d[5],s;
long long f[100005];
int tot;
long long F(int x){
	if(x<0) return 0;
	else return f[x];
}
int main(){
	scanf("%d%d%d%d%d",&c[1],&c[2],&c[3],&c[4],&tot);
	f[0]=1;
	for(int i=c[1];i<=100000;i++)f[i]+=f[i-c[1]];
	for(int i=c[2];i<=100000;i++)f[i]+=f[i-c[2]];
	for(int i=c[3];i<=100000;i++)f[i]+=f[i-c[3]];
	for(int i=c[4];i<=100000;i++)f[i]+=f[i-c[4]];
	while(tot--){
		scanf("%d%d%d%d%d",&d[1],&d[2],&d[3],&d[4],&s);
		printf("%lld\n",f[s]
						-F(s-(d[1]+1)*c[1])-F(s-(d[2]+1)*c[2])-F(s-(d[3]+1)*c[3])-F(s-(d[4]+1)*c[4])
						+F(s-(d[1]+1)*c[1]-(d[2]+1)*c[2])+F(s-(d[1]+1)*c[1]-(d[3]+1)*c[3])+F(s-(d[1]+1)*c[1]-(d[4]+1)*c[4])
						+F(s-(d[2]+1)*c[2]-(d[3]+1)*c[3])+F(s-(d[2]+1)*c[2]-(d[4]+1)*c[4])+F(s-(d[4]+1)*c[4]-(d[3]+1)*c[3])
						-F(s-(d[2]+1)*c[2]-(d[3]+1)*c[3]-(d[4]+1)*c[4])
						-F(s-(d[1]+1)*c[1]-(d[3]+1)*c[3]-(d[4]+1)*c[4])
						-F(s-(d[1]+1)*c[1]-(d[2]+1)*c[2]-(d[4]+1)*c[4])
						-F(s-(d[1]+1)*c[1]-(d[2]+1)*c[2]-(d[3]+1)*c[3])
						+F(s-(d[1]+1)*c[1]-(d[2]+1)*c[2]-(d[3]+1)*c[3]-(d[4]+1)*c[4])
		);
	}
	return 0;
}
