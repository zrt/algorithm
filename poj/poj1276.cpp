#include<cstdio>
#include<cstring>
using namespace std;
bool a[100005];
int main(){
    int w,n,x,y;
    while(~scanf("%d%d",&w,&n)){
        memset(a,0,sizeof a);
        a[0]=1;
        for(int i=0;i<n;i++){
            scanf("%d%d",&x,&y);
            int p=1;
            for(;p<=x;p<<=1){
                x-=p;
                int v=p*y;
                for(int j=w-v;j>=0;j--){
                    if(a[j]){
                        a[j+v]=1;
                    }
                }
            }
            y*=x;
            for(int j=w-y;j>=0;j--){
                if(a[j]){
                    a[j+y]=1;
                }
            }
        }
        for(int i=w;i>=0;i--){
            if(a[i]){
                printf("%d\n",i);break;
            }
        }
    }
    return 0;
}
