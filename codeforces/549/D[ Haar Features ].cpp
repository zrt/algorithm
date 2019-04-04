#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long LL;
typedef long double ld;
void read(int&x){scanf("%d",&x);}
void read(long double&x){double xx;scanf("%lf",&xx);x=xx;}
void read(char*s){scanf("%s",s);}

int n,m;
char s[105][105];
int c[105][105];
inline int lowbit(int x){
    return x&-x;
}
int ask(int x,int y){
    int ret=0;
    for(int i=x;i>0;i-=lowbit(i)){
        for(int j=y;j>0;j-=lowbit(j)){
            ret+=c[i][j];
        }
    }
    return ret;
}
void add(int x,int y,int d){
    for(int i=x;i<=n;i+=lowbit(i)){
        for(int j=y;j<=m;j+=lowbit(j)){
            c[i][j]+=d;
        }
    }
}
int ans;
void add(int x1,int y1,int x2,int y2,int d){
    add(x1,y1,d);
    add(x1,y2+1,-d);
    add(x2+1,y1,-d);
    add(x2+1,y2+1,d);
}
int main(){
    read(n);read(m);
    for(int i=1;i<=n;i++) read(s[i]+1);
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            int a=ask(i,j);
            int b;
            if(s[i][j]=='B') b=1;else b=-1;
            if(a==b) continue;
            add(1,1,i,j,b-a);
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
