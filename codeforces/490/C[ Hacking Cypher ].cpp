#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[1000500];
int L;
int a,b;
int l[1000500],r[1000500];
int main(){
    scanf("%s",s+1);
    scanf("%d%d",&a,&b);
    L=strlen(s+1);
    int num=0;
    for(int i=1;i<=L;i++){
        num=num*10+s[i]-'0';
        num%=a;
        l[i]=num;
    }
    num=0;
    int tmp=1;
    for(int i=L;i>=1;i--){
        num=(num+(s[i]-'0')*1LL*tmp)%b;
        tmp=tmp*10%b;
        r[i]=num;
    }
    if(s[1]=='0'){
        puts("NO");
        return 0;
    }
    for(int i=1;i<L;i++){
        if(s[i+1]!='0'&&l[i]==0&&r[i+1]==0){
            puts("YES");
            char c=s[i+1];
            s[i+1]=0;
            printf("%s\n",s+1);
            s[i+1]=c;
            printf("%s\n",s+i+1);
            return 0;
        }
    }
    puts("NO");
    return 0;
}