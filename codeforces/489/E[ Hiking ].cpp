#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,l;
double f[1005];
int pos[1005];
int x[1005],b[1005];
bool judge(double c){
    for(int i=0;i<=n;i++) f[i]=1e80;
    f[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            double tmp=sqrt(abs(x[i]-x[j]+0.0-l))-b[i]*c;
            if(f[j]+tmp<f[i]){
                pos[i]=j;
                f[i]=f[j]+tmp;
            }
        }
    }
    return f[n]<0;
}
void print(int x){
    if(x==0){
        return;
    }else{
        print(pos[x]);
        printf("%d ",x);
    }
}
int main(){
    scanf("%d%d",&n,&l);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x[i],&b[i]);
    }
    double L=0,R=1e7;
    double M;
    for(int i=0;i<60;i++){
        M=(L+R)/2.0;
        if(judge(M)){
            R=M;
        }else L=M;
    }
//  printf("%.5f\n",M);
    judge(R);
    print(n);
//  while(1);
    return 0;
}