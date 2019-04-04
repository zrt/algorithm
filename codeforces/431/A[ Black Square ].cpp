/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt
//problem:
using namespace std;
typedef long long ll;
const double eps=1e-9;
int a[5];
char s[100005];
long long ans=0;
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    scanf("%d%d%d%d",&a[1],&a[2],&a[3],&a[4]);
    scanf("%s",s);
    for(int i=0;s[i];i++){
        ans+=a[s[i]-'0'];
    }
    printf("%I64d\n",ans);
    return 0;
}
