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
int a[5][5];
int per[5]={0,1,2,3,4};
//  34
int main(){
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
        scanf("%d",&a[i][j]);
    }
    int maxx=-(1<<30);
    //01234
    do{
        int ans=0;  
        ans+=a[per[0]][per[1]]+a[per[1]][per[0]]+a[per[2]][per[3]]+a[per[3]][per[2]]+a[per[1]][per[2]]+a[per[2]][per[1]]+(a[per[3]][per[4]]+a[per[4]][per[3]])*2+a[per[2]][per[3]]+a[per[3]][per[2]];
        maxx=max(maxx,ans);
    }while(next_permutation(per,per+5));
    printf("%d\n",maxx);
    return 0;
}
