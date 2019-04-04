#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int a[500050];
int b[500050];
bool cg[500050];// can not change
int end[500050];
int mx;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    cg[1]=1;
    cg[n]=1;
    for(int i=2;i<n;i++){
        if(a[i]==a[i-1]||a[i]==a[i+1]){
            cg[i]=1;
        }
    }
    int num=0;
    for(int i=1;i<=n;i++){
        if(cg[i]){
            num=0;
        }else{
            num++;
            mx=max(mx,num);
        }
    }
    printf("%d\n",(mx+1)/2);
    int start;
    for(int i=1;i<=n;i++){
        if(!cg[i]){
            if(cg[i+1]){
                // start ... i
                if(a[start-1]==a[i+1]){
                    for(int j=start;j<=i;j++){
                        end[j]=a[i+1];
                    }
                }else{
                    int num=(i-start+1)/2;
                    for(int j=start;j<start+num;j++){
                        end[j]=a[start-1];
                    }
                    for(int j=i-num+1;j<=i;j++){
                        end[j]=a[i+1];
                    }
                }
            }
        }else{
            start=i+1;
            end[i]=a[i];
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d ",end[i]);
    }
    puts("");
    // 1 1 0 1  0 1 1 1
    return 0;
    // 1 1 0 1 0 1 0 0
} 