#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,m;
double c[1050][1050];
vector<int> v[1005];
int num[1050],cc;
int d[1050];
bool cmp(int a,int b){
    return a>b;
}
double dp[1050][1050];
int main(){
    c[0][0]=1;
    for(int i=1;i<=1000;i++){
        c[i][0]=1;
        for(int j=1;j<=i;j++){
            c[i][j]=c[i-1][j]+c[i-1][j-1];
        }
    }
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&d[i]);
        for(int j=0;j<d[i];j++){
            scanf("%d",&num[cc]);
            v[i].push_back(num[cc]);
            cc++;
        }
    }
    nth_element(num,num+n-1,num+cc,cmp);
    int V=num[n-1];
    for(int i=0;i<=n;i++) dp[0][0]=1;
    int s=0,t=0;
    for(int i=1;i<=m;i++){
        int num=0;
        bool ok=0;
        for(int j=0;j<d[i];j++){
            if(v[i][j]>V) num++;
            else if(v[i][j]==V) ok=1,t++;
        }
        s+=num;
        for(int j=0;j<=n;j++){
            if(ok){
                if(j>0)dp[i][j]=dp[i-1][j]/c[d[i]][num]+dp[i-1][j-1]/c[d[i]][num+1];
                else dp[i][j]=dp[i-1][j]/c[d[i]][num];
            }else{
                dp[i][j]=dp[i-1][j]/c[d[i]][num];
            }
        }
    }
//  printf("%d %d\n",s,t);
    printf("%.15f\n",dp[m][n-s]/c[t][n-s]);
    return 0;
}