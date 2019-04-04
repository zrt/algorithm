#include<bits/stdc++.h>
using namespace std;
int v1,v2,t,d;
int f[105][1050];
int main(){
    scanf("%d%d%d%d",&v1,&v2,&t,&d);
    memset(f,0x80,sizeof f);
    f[1][v1]=v1;
    for(int i=2;i<=t;i++){
        for(int j=0;j<=1000;j++){
            for(int k=max(0,j-d);k<=min(j+d,1000);k++){
                f[i][j]=max(f[i][j],f[i-1][k]+j);
            }
        }
    }
    printf("%d\n",f[t][v2]);
    return 0;
}
