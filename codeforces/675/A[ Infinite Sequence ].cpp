#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){

    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(c==0){
        if(a==b){
            puts("YES");
        }else puts("NO");
    }else{
        if(c==0&&a==b||(b-a)%c==0&&(b-a)/c>=0){
            puts("YES");
        }else puts("NO");
    }
    

    return 0;
}