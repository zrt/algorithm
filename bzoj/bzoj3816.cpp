/**************************************************************
    Problem: 1287
    User: bjbsz12
****************************************************************/
 
 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int a[405][405];
int b[405];
int q[405*405];
struct N{
    int x,y;
    N(int a=0,int b=0){
        x=a,y=b;
    }
    friend bool operator < (const N&a,const N&b){
        return a.y<b.y;
    }
}tmp;
int tt,n,m;
vector<N> v[405];
void check(){
    memset(b,0,sizeof b);
    for(int i=1;i<=n;i++) q[i]=i;
    for(int l=1,r=n;l<=r;l++){
        int t=q[l];
        while(!v[t].empty()){
            tmp=v[t].back();
            if(b[tmp.x]==0){
                b[tmp.x]=t;
                break;
            }
            if(a[tmp.x][b[tmp.x]]>tmp.y){
                q[++r]=b[tmp.x];
                b[tmp.x]=t;
                break;
            }
            v[t].pop_back();
        }
        if(v[t].empty()) break;
        v[t].pop_back();
    }
}
int main(){
    scanf("%d",&tt);
    while(tt--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) v[i].clear();
        for(int i=1;i<=n;i++){
            for(int j=1,x;j<=m;j++){
                scanf("%d",&x);
                if(x){
                    v[x].push_back(N(i,j));
                    a[i][x]=j;
                }
            }
        }
        for(int i=1;i<=n;i++) sort(v[i].begin(),v[i].end());
        check();
     //   for(int i=1;i<=n;i++) printf("%d ",b[i]);
     //   puts("");
    }
    return 0;
}
