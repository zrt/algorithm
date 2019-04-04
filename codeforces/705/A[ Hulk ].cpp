#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int t=1;
    int f=1;
    while(n--){
        if(f) f=0;
        else printf("that ");
        if(t){
            printf("I hate ");
        }else{
            printf("I love ");

        }
        t^=1;
    }
    puts("it");

    return 0;
}