#include<cstdio>
#define N 500010
int n,i,j,t,delta,ca,cb,a[10],b[10],c[N],d[N],p[N][10];
int seed[10]={233,13331,997,733,811,953,2011,1999,1997,1801};
unsigned int pow,target,f[11][N];
inline void read(int&a){char c;while(!(((c=getchar())>='0')&&(c<='9')));a=c-'0';while(((c=getchar())>='0')&&(c<='9'))(a*=10)+=c-'0';}
int main(){
  read(n);
  for(i=0,ca=1;i<n;i++)read(a[i]),ca*=a[i];
  for(i=0,cb=1;i<n;i++)read(b[i]),cb*=b[i];
  for(i=0;i<ca;i++)read(c[i]);
  for(i=0;i<cb;i++)read(d[i]);
  for(i=0;i<cb;i++)for(t=i,j=n-1;~j;j--)p[i][j]=t%b[j],t/=b[j];
  for(j=0;j<cb;j++)f[n][j]=d[j];
  for(delta=1,i=n-1;~i;i--){
    for(j=0;j<cb;j++){
      f[i][j]=f[i+1][j];
      if(p[j][i])f[i][j]+=f[i][j-delta]*seed[i];
    }
    delta*=b[i];
  }
  target=f[0][cb-1];
  for(i=0;i<ca;i++)for(t=i,j=n-1;~j;j--)p[i][j]=t%a[j],t/=a[j];
  for(j=0;j<ca;j++)f[n][j]=c[j];
  for(delta=1,i=n-1;~i;i--){
    for(pow=1,j=b[i];j;j--)pow*=seed[i];
    for(j=0;j<ca;j++){
      f[i][j]=f[i+1][j];
      if(p[j][i])f[i][j]+=f[i][j-delta]*seed[i];
      if(p[j][i]>=b[i])f[i][j]-=f[i+1][j-delta*b[i]]*pow;
    }
    delta*=a[i];
  }
  for(j=0;j<ca;j++){
    for(t=1,i=0;i<n;i++)if(p[j][i]<b[i]-1){t=0;break;}
    if(t&&f[0][j]==target){
      for(i=0;i<n;i++)printf("%d ",p[j][i]-b[i]+2);
      return 0;
    }
  }
}
