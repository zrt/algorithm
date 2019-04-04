#include<cstdio>
#include<algorithm>
using namespace std;
int bag[56000];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    bag[0]=1;
    int p,c;
    for(int i=0;i<n;i++){
        scanf("%d%d",&p,&c);
        for(int j=0;j<m;j++){
            if(bag[j]){
                if(!bag[j+p]) bag[j+p]=bag[j]+c;
                else bag[j+p]=min(bag[j+p],bag[j]+c);
            }
        }
    }
    int ans=~0U>>1;
    for(int i=m;i<=m+5000;i++){
        if(bag[i]){
            ans=min(ans,bag[i]);
          //  printf("%d\n",bag[i]-1);break;
        }
    }
    printf("%d\n",ans-1);
    return 0;
}
