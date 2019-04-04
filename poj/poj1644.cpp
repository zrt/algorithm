#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int T,n,t;
int sta[60];
bool L[60];
bool cal[60][50];
double ans[60][50];
char s[10];
const double eps=1e-8;
double solve(int x,int t){
    if(x==n+1&&t>=0) return 1;
    if(t<=0) return 0;
    if(cal[x][t]) return ans[x][t];
    else cal[x][t]=1;
    double p=0;
    for(int i=1;i<=2;i++){
        int k=x+i;
   //     printf("# %d %d %d\n",x,t,k);
        if(k>n+1) k=n+1;
        if(L[k]){
      //      L[k]=0;sta[k]=0;
            p+=0.5*solve(k,t-2);
            continue;
        }
        k+=sta[k];
  //      printf("# %d %d %d\n",x,t,k);
        p+=0.5*solve(k,t-1);
    }
 //   printf("$ %d %d %f\n",x,t,p);
    return ans[x][t]=p;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&t);
        memset(L,0,sizeof L);
        memset(sta,0,sizeof sta);
        memset(cal,0,sizeof cal);
        for(int i=1;i<=n;i++){
            scanf("%s",s);
            if(s[0]=='L'){
                L[i]=1;
            }else{
                if(s[0]=='0'){
                    sta[i]=0;
                }else if(s[0]=='-'){
                    int tmp=0;
                    for(int i=1;s[i];i++){
                        tmp*=10;tmp+=s[i]-'0';
                    }
                    sta[i]=-tmp;
                }else{
                    int tmp=0;
                    for(int i=1;s[i];i++){
                        tmp*=10;tmp+=s[i]-'0';
                    }
                    sta[i]=tmp;
                }
            }
        }
     //   for(int i=0;i<=n+1;i++) printf("%d ",L[i]);
       // puts("");
        double x;
        x=solve(0,t);
        if(fabs(x-0.5)<eps){
            printf("Push. %.4f\n",x);
        }else if(x>0.5){
            printf("Bet for. %.4f\n",x);
        }else{
            printf("Bet against. %.4f\n",x);
        }
    }
    return 0;
}
