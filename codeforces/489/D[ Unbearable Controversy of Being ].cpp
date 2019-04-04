#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
int H[3005],X[30005],P[30005],tot;
inline void add(int x,int y){
    P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
long long num[3005];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0,x,y;i<m;i++){
        scanf("%d%d",&x,&y);
        add(x,y);
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=H[i];j;j=X[j]){
            for(int k=H[P[j]];k;k=X[k]){
                if(P[k]==i) continue;
                num[P[k]]++;
            }
        }
        for(int i=1;i<=n;i++){
            ans+=num[i]*(num[i]-1);
        }
        memset(num,0,sizeof num);
    }
    printf("%I64d\n",ans/2);
//  while(1);
    return 0;
}