#include<cstdio>
using namespace std;
int f[50][2];
int main(){
    f[1][0]=f[1][1]=1;
    for(int i=2;i<=46;i++){
        f[i][0]=f[i-1][0]+f[i-1][1];
        f[i][1]=f[i-1][0];
    }
    int t,x;
    scanf("%d",&t);
    int kase=0;
    while(t--){
        scanf("%d",&x);
        printf("Scenario #%d:\n%d\n\n",++kase,f[x+1][0]);
    }
    return 0;
}
