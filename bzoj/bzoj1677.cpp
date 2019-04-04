#include<cstdio>
using namespace std;
int a[1000005];
int mod=1000000000;
int main(){
    int n;
    a[0]=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i<<=1){
            int siz=n-i;
        for(int j=0;j<=siz;j++){
            if(a[j]){
                a[j+i]+=a[j];
                if(a[j+i]>=mod) a[j+i]-=mod;
            }
        }
    }
    printf("%d\n",a[n]);
    return 0;
}
