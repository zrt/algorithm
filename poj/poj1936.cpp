#include<cstdio>
using namespace  std;
char s[100005],t[100005];
int main(){
    while(~scanf("%s%s",s,t)){
        int i=0,j=0;
        for(;;){
            if(s[i]==t[j]) i++,j++;
            else j++;
            if(!s[i]){
                printf("Yes\n");break;
            }
            if(!t[j]){
                printf("No\n");break;
            }
        }
    }
    return 0;
}
