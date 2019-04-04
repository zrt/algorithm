#include<cstdio>
int main(){
    int n,h;
    scanf("%d%d",&n,&h);
    int ans=0;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(x>h) ans+=2;
        else ans++;
    }
    printf("%d\n",ans);
    return 0;
}