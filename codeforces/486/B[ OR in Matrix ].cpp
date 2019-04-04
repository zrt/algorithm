#include<cstdio>
int b[105][105],a[105][105],c[105][105];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&b[i][j]);
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i][j]==0){
                for(int k=1;k<=m;k++) a[i][k]=0;
                for(int k=1;k<=n;k++) a[k][j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=m;k++) c[i][j]|=a[i][k];
            for(int k=1;k<=n;k++) c[i][j]|=a[k][j];
        }
    }
    bool ok=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i][j]!=c[i][j]){
                ok=0;break;
            }
        }
    }
    if(ok){
        puts("YES");
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                printf("%d ",a[i][j]);
            }
            puts("");
        }
    } else puts("NO");
//  while(1);
    return 0;
}