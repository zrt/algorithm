#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long LL;
typedef long double ld;
void read(int&x){scanf("%d",&x);}
void read(long double&x){double xx;scanf("%lf",&xx);x=xx;}
void read(char*s){scanf("%s",s);}

int n,m;
char s[55][55];
bool check(int x,int y){
    if(s[x][y]=='f'||s[x+1][y]=='f'||s[x][y+1]=='f'||s[x+1][y+1]=='f'){
        if(s[x][y]=='a'||s[x+1][y]=='a'||s[x][y+1]=='a'||s[x+1][y+1]=='a'){
            if(s[x][y]=='c'||s[x+1][y]=='c'||s[x][y+1]=='c'||s[x+1][y+1]=='c'){
                if(s[x][y]=='e'||s[x+1][y]=='e'||s[x][y+1]=='e'||s[x+1][y+1]=='e'){
                    return 1;
                }
            }
        }
    }
    return 0;
}
int main(){
    read(n);read(m);
    for(int i=1;i<=n;i++) read(s[i]+1);
    int ans=0;
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(check(i,j)){
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    
    return 0;
}
