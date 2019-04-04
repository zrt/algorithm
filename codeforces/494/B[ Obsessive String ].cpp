#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int mod=1e9+7;
char s[100005];
char t[100005];
int nxt[100005];
int ok[100005];
int f[100005];
int ss[100005];
int sum[100005];
int ans;
int main(){
    scanf("%s%s",s+1,t+1);
    int l1=strlen(s+1);
    int l2=strlen(t+1);
    if(l2>l1){
        puts("0");
        return 0;
    }
    int j=0;
    for(int i=2;i<=l2;i++){
        while(j&&t[i]!=t[j+1]) j=nxt[j];
        if(t[i]==t[j+1]) j++;
        nxt[i]=j;
    }
    j=0;
    for(int i=1;i<=l1;i++){
        while(j&&s[i]!=t[j+1]) j=nxt[j];
        if(s[i]==t[j+1]) j++;
        if(j==l2){
            ok[i]=1;
            j=nxt[j];
        }
    }
    int lst=0;
    bool met=0;
    for(int i=1;i<=l1;i++){
        if(ok[i]) lst=i-l2+1,met=1;
        if(!met) continue;
        else{
            f[i]=lst;
            f[i]+=sum[lst-1];
            f[i]%=mod;
            ss[i]=(ss[i-1]+f[i])%mod;
            sum[i]=(sum[i-1]+ss[i])%mod;
        }
    }
    printf("%d\n",ss[l1]);
//  while(1);
    return 0;
}