#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;
#define MAXN 200005
int m,mod,T,x;
char s[10];
struct N{
    int x,w;
}q[MAXN];
int h,t,pos;
void add(int x){
    pos++;
    while(h!=t&&q[t-1].w<=x) t--;
    q[t].w=x,q[t].x=pos;t++;
    return;
}
bool cmp(N a ,N b){
	return a.x<b.x;
}
int ask(int L){
    int Pos=pos-L;
    //x > Pos de di yi ge shu
    q[t].x = Pos;
    int r = upper_bound(q,q+t,q[t],cmp)-q;
    return q[r].w;
}
int main(){
    scanf("%d%d",&m,&mod);
    while(m--){
        scanf("%s%d",s,&x);
        if(s[0]=='A')   add((x+T)%mod);
        else    printf("%d\n",T=ask(x));
    }
    return 0 ;
}
