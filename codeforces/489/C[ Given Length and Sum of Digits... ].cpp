#include<cstdio>
using namespace std;
int m,s;
int main(){
    scanf("%d%d",&m,&s);
    if(s==0&&m==1){
        puts("0 0");
        return 0;
    }
    if(s==0||m*9<s){
        puts("-1 -1");
        return 0;
    }
    int k=s;
    int now=1;
    while((m-1)*9+now<k) now++;
    printf("%d",now);
    k-=now;
    for(int i=1;i<m;i++){
        now=0;
        while((m-i-1)*9+now<k) now++;
        printf("%d",now);
        k-=now;
    }
    putchar(' ');
    k=s;
    now=9;
    while(now>k) now--;
    printf("%d",now);
    k-=now;
    for(int i=1;i<m;i++){
        now=9;
        while(now>k) now--;
        printf("%d",now);
        k-=now;
    }
    puts("");
//  while(1);
    return 0;
}