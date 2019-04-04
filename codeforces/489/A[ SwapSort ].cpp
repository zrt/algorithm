#include<cstdio>
#include<algorithm>
using namespace std;

int a[3500];
int n;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    printf("%d\n",n);
    for(int i=0;i<n;i++){
        int mx=0x7fffffff;
        int pos;
        for(int j=i;j<n;j++){
            if(a[j]<mx){
                mx=a[j];
                pos=j;
            }
        }
        swap(a[i],a[pos]);
        printf("%d %d\n",i,pos);
    }
    return 0;
}