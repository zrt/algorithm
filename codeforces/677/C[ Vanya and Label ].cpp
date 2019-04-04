#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
char s[100005];
int num;
LL pow(LL a,LL b,LL p){
    LL ret=1%p;
    while(b){
        if(b&1) ret=ret*a%p;
        b>>=1;
        a=a*a%p;
    }
    return ret;
}
void calc(char c){
    int x=0;
    if(c>='0'&&c<='9') x=c-'0';
    else if(c>='A'&&c<='Z') x=c-'A'+10;
    else if(c>='a'&&c<='z') x=c-'a'+36;
    else if(c=='-') x=62;
    else if(c=='_') x=63;
    for(int i=0;i<6;i++){
        if(x&1) ;else num++;
        x>>=1;
    }
}
int main(){
    scanf("%s",s);
    for(int i=0;s[i];i++){
        calc(s[i]);
    }
    printf("%I64d\n",pow(3,num,1000000007));
    return 0;
}