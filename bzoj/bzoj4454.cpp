#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int tt,n,m;
int a[2005],b[2005];
int p_a[2005][10],t_a[2005][10],pow_a[2005][10][30],n_a[2005];
int p_b[2005][10],t_b[2005][10],pow_b[2005][10][30],n_b[2005];
unsigned gcd(int i,int j){
    if(a[i]==0) return b[j];
    if(b[j]==0) return a[i];
    int pos_a=1,pos_b=1;
    unsigned ans=1;
    while(pos_a<=n_a[i]&&pos_b<=n_b[j]){
        if(p_a[i][pos_a]==p_b[j][pos_b]){
            ans*=pow_a[i][pos_a][min(t_a[i][pos_a],t_b[j][pos_b])];
            pos_a++;
            pos_b++;
        }else if(p_a[i][pos_a]<p_b[j][pos_b]){
            pos_a++;
        }else{
            pos_b++;
        }
    }
    return ans;
}
int main(){
    scanf("%d",&tt);
    while(tt--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<m;i++) scanf("%d",&b[i]);
        for(int i=0;i<n;i++){
            if(a[i]!=0){
                int x=a[i];
                n_a[i]=0;
                for(int j=2;j<=1000;j++){
                    if(x%j==0){
                        n_a[i]++;
                        pow_a[i][n_a[i]][0]=1;
                        p_a[i][n_a[i]]=j;
                        t_a[i][n_a[i]]=0;
                        while(x%j==0){
                            x/=j;
                            t_a[i][n_a[i]]++;
                            pow_a[i][n_a[i]][t_a[i][n_a[i]]]=pow_a[i][n_a[i]][t_a[i][n_a[i]]-1]*j;
                        }
                    }
                }
                if(x>1){
                    n_a[i]++;
                    p_a[i][n_a[i]]=x;
                    t_a[i][n_a[i]]=1;
                    pow_a[i][n_a[i]][1]=x;
                }
            }
        }
        for(int i=0;i<m;i++){
            if(b[i]!=0){
                int x=b[i];
                n_b[i]=0;
                for(int j=2;j<=1000;j++){
                    if(x%j==0){
                        n_b[i]++;
                        pow_b[i][n_b[i]][0]=1;
                        p_b[i][n_b[i]]=j;
                        t_b[i][n_b[i]]=0;
                        while(x%j==0){
                            x/=j;
                            t_b[i][n_b[i]]++;
                            pow_b[i][n_b[i]][t_b[i][n_b[i]]]=pow_b[i][n_b[i]][t_b[i][n_b[i]]-1]*j;
                        }
                    }
                }
                if(x>1){
                    n_b[i]++;
                    p_b[i][n_b[i]]=x;
                    t_b[i][n_b[i]]=1;
                    pow_b[i][n_b[i]][1]=x;
                }
            }
        }
        unsigned ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=gcd(i,j)^(unsigned)i^(unsigned)j;
            }
        }
        printf("%u\n",ans);
    }

    return 0;
}
