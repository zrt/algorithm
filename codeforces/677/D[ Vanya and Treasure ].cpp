#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n,m;
int a[305][305];
int p;
vector<int> v[90005];
vector<int> dp[90005];
int abs(int x){
    return x>0?x:-x;
}
int calc(int A,int B){
    int x1=A/m,y1=A%m+1;
    int x2=B/m,y2=B%m+1;
    return abs(x1-x2)+abs(y1-y2);
}
int d[305][305];
struct N{
    int x,y;
    int w;
    friend bool operator < (N a,N b){
        return a.w>b.w;
    }
    N(int a=0,int b=0,int c=0){
        x=a,y=b;w=c;
    }
};
priority_queue<N> q;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int main(){
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
        scanf("%d",&a[i][j]);
        v[a[i][j]].push_back(i*m+j-1);
        dp[a[i][j]].push_back(1000000000);
    }
    
    memset(d,0x3f,sizeof d);
    d[1][1]=0;
    q.push(N(1,1,0));
    while(!q.empty()){
        int x=q.top().x,y=q.top().y;
        if(d[x][y]!=q.top().w){
            q.pop();
            continue;
        }
        q.pop();
        for(int k=0;k<4;k++){
            int xx=x+dx[k];
            int yy=y+dy[k];
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m){
                if(d[xx][yy]>d[x][y]+1){
                    d[xx][yy]=d[x][y]+1;
                    q.push(N(xx,yy,d[xx][yy]));
                }
            }
        }
    }
    for(int j=0;j<v[1].size();j++){
        int x=v[1][j]/m,y=v[1][j]%m+1;
        dp[1][j]=d[x][y];
    }

    int now=1;

    if(now==p){
        puts("0");
    }else{
        for(int i=now;i<p;i++){
            if(v[i].size()*v[i+1].size()>300*300*5){
                //bfs solve
                memset(d,0x3f,sizeof d);
                for(int j=0;j<v[i].size();j++){
                    int x=v[i][j]/m,y=v[i][j]%m+1;
                    d[x][y]=dp[i][j];
                    q.push(N(x,y,dp[i][j]));
                }
                while(!q.empty()){
                    int x=q.top().x,y=q.top().y;
                    if(d[x][y]!=q.top().w){
                        q.pop();
                        continue;
                    }
                    q.pop();
                    for(int k=0;k<4;k++){
                        int xx=x+dx[k];
                        int yy=y+dy[k];
                        if(xx>=1&&xx<=n&&yy>=1&&yy<=m){
                            if(d[xx][yy]>d[x][y]+1){
                                d[xx][yy]=d[x][y]+1;
                                q.push(N(xx,yy,d[xx][yy]));
                            }
                        }
                    }
                }
                for(int j=0;j<v[i+1].size();j++){
                    int x=v[i+1][j]/m,y=v[i+1][j]%m+1;
                    dp[i+1][j]=d[x][y];
                }
            }else{
                //brute solve
                for(int j=0;j<v[i+1].size();j++){
                    int mn=1000000000;
                    for(int k=0;k<v[i].size();k++){
                        mn=min(mn,dp[i][k]+calc(v[i+1][j],v[i][k]));
                    }
                    dp[i+1][j]=mn;
                }
            }
        }
        printf("%d\n",dp[p][0]);
    }
    return 0;
}