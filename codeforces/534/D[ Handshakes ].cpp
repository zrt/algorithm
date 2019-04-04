#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
vector<int> v[200005];
queue<int> ans;
int main(){
    scanf("%d",&n);
    int now=0;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),v[a[i]].push_back(i);
    bool ok=1;
    for(int i=1;i<=n;i++){
        if(now<0){
            ok=0;break;
        }
        if(v[now].size()>0){
            ans.push(v[now].back());
            v[now].pop_back();
            now++;
        }else now-=3,i--;
    }
    if(ok){
        puts("Possible");
        while(!ans.empty()){
            int x=ans.front();ans.pop();
            printf("%d ",x);
        }
        puts("");
    }else puts("Impossible");
    return 0;
}
