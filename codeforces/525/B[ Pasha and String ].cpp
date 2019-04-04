#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
char s[300005];
int a[300005];
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    scanf("%d",&m);
    for(int i=1,x;i<=m;i++){
        scanf("%d",&x);
        a[x]^=1;
    }
    for(int i=1;i+i<=n;i++){
        a[i]^=a[i-1];
        if(a[i]) swap(s[i],s[n-i+1]);
    }
    puts(s+1);
    return 0;
}
