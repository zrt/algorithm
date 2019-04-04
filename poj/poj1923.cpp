#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int f[105][10005];
//f[i][j] f[i+k][j+i*k]=f[i][j]+(i+1)*k;
int main(){
    memset(f,128,sizeof f);
    f[0][0]=1;
    int tmp;
    for(int i=0;i<=100;i++){
        int M=(i*(i-1))>>1;
        for(int j=0;j<=M;j++){
            tmp=(i+1)*(100-i)+f[i][j];
            for(int k=100-i;k>0;k--,tmp-=i+1){
                if(tmp>f[i+k][j+i*k]) f[i+k][j+i*k]=tmp;
            }
        }
    }
    int n,m;
    int kase=0;
    while(scanf("%d%d",&n,&m),n+m){
        if(f[n][m]>0){
            printf("Case %d: %d lines with exactly %d crossings can cut the plane into %d pieces at most.\n",++kase,n,m,f[n][m]);
        }else{
            printf("Case %d: %d lines cannot make exactly %d crossings.\n",++kase,n,m);
        }
    }
    return 0;
}
