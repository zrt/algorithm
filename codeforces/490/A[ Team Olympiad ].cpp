#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<int> v[4];
int main(){
    scanf("%d",&n);
    for(int i=1,x;i<=n;i++){
        scanf("%d",&x);
        v[x].push_back(i);
    }
    int num=min(v[1].size(),min(v[2].size(),v[3].size()));
    printf("%d\n",num);
    for(int i=0;i<num;i++){
        printf("%d %d %d\n",v[1][i],v[2][i],v[3][i]);
    }
//  while(1);
    return 0;
}