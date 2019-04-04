#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int num=0;
vector<int> out;
bool is_prime(int x){
    for(int j=2;j<x;j++) if(x%j==0) return 0;
    return 1;
}
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        if(is_prime(i)){
            for(int j=i;j<=n;j*=i){
                num++;
                out.push_back(j);
            }
        }
    }
    printf("%d\n",num);
    for(int i=0;i<out.size();i++) printf("%d ",out[i]);
    return 0;
} 