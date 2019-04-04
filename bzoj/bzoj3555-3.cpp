  
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int n,m,k;
long long ans;
typedef unsigned long long llu;
char s[30005][205];
llu hash[30005];
llu a[30005];
llu pow[205];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    pow[0]=1;
    for(int i=1;i<=m;i++) pow[i]=pow[i-1]*13131;
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            hash[i]=hash[i]*13131+s[i][j];
        }
    }
    for(int p=0;p<m;p++){
    	int tot=0;
        for(int i=0;i<n;i++){
            llu h=hash[i]-s[i][p]*pow[m-p-1];
            a[++tot]=h;
        }
        sort(a+1,a+tot+1);
        for(int i=1;i<=tot;i++){
        	int j=i;
        	while(j<=tot&&a[i]==a[j]) j++;
        	ans+=(j-i)*1LL*(j-i-1)/2;
        	i=j-1;
		}
    }
     
    printf("%lld\n",ans);
    return 0;
}
