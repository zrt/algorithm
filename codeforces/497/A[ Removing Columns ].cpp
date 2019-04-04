#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
char s[105][105];
int num[105][105];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    int p=1;
    for(int i=1;i<=n;i++) num[i][0]=1;
    int ans=0;
    int last=0;
    for(int j=1;j<=m;j++){
        if(p>=n) break;
        bool ok=1;
        for(int i=2;i<=n;i++) if(s[i][j]<s[i-1][j]&&num[i-1][last]==num[i][last]){
            ok=0;break;
        }
        if(!ok){
            ans++;continue;
        }
        p=1;
        num[1][j]=1;
        for(int i=2;i<=n;i++){
            if(num[i][last]==num[i-1][last]&&s[i][j]==s[i-1][j]){
                num[i][j]=p;
            }else num[i][j]=++p;
        }
        last=j;
    }
    printf("%d\n",ans);
    return 0;
}