#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int main(){
    scanf("%d",&n);
    int sum=0;
    int num=0;
    for(int i=1;i<=n;i++){
        sum+=i;
        if(sum<=n){
            num++;
        }else{
            sum-=i;
            break;
        }
    }
    printf("%d\n",num);
    for(int i=1;i<num;i++){
        printf("%d ",i);
    }
    printf("%d\n",num+n-sum);



    return 0;
}