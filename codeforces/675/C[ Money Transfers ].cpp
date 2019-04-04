#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;

typedef long long LL;
LL n,a[200005];
int pos[200005];
int nxt[200005];
int dp[200005];
bool vis[200005];
map<LL,int> last;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n+1;i<=2*n;i++) a[i]=a[i-n];
    LL sum=0;
    for(int i=1;i<=2*n;i++){
        sum+=a[i];
        pos[i]=last[sum];
        last[sum-a[i]]=i;
    }
    for(int i=1;i<=2*n;i++) if(a[i]==0) pos[i]=i;
    for(int i=1;i<=2*n;i++) nxt[i]=2*n+1;
    for(int i=2*n;i>=1;i--) nxt[pos[i]-1]=min(nxt[pos[i]-1],i);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        vis[i]=1;
        if(!pos[i]) continue;
        int bp=i;
        int j=i;
        int num=1;
        while(bp!=2*n+1){
            while(nxt[j]&&nxt[j]<pos[bp]+n) vis[j]=1,j=nxt[j],num++;
            ans=max(ans,num);
            bp=nxt[bp];num--;
        }
    }
    cout<<n-ans<<endl;
    

    return 0;
}