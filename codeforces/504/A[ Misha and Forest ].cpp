#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int d[100005],s[100005];
int n;
queue<int> q;
int ansx[100005],ansy[100005],cc;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",&d[i],&s[i]);
    for(int i=0;i<n;i++) if(d[i]==1){
        q.push(i);
    }
    while(!q.empty()){
        int x=q.front();q.pop();
        if(!d[x]) continue;
        ansx[cc]=x;
        ansy[cc]=s[x];
        cc++;
        d[x]--;
        d[s[x]]--;
        if(d[s[x]]==1) q.push(s[x]);
        s[s[x]]^=x;
        s[x]=0;
    }
    printf("%d\n",cc);
    for(int i=0;i<cc;i++){
        printf("%d %d\n",ansx[i],ansy[i]);
    }
    return 0;
}