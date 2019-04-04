#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
char s[100005][10];
int l[100005];
bool tianchong(int x,bool ok){
    if(ok){
        if(x==1||l[x]>l[x-1]){
            for(int i=l[x]-1;i>=0;i--){
                if(s[x][i]=='?') s[x][i]='1';
            }
        }else{
            bool up=0;
            for(int i=l[x]-1;i>=0;i--){
                if(s[x][i]=='?') s[x][i]='9';
                if(s[x][i]>s[x-1][i]) up=1;
                if(s[x][i]<s[x-1][i]&&!up){
                    return 0;
                }
            }
            return up;
        }
        return 1;
    }else{
        if(x==1||l[x]>l[x-1]){
            bool up=0;
            for(int i=l[x]-1;i>=0;i--){
                if(s[x][i]=='?') s[x][i]=(i==l[x]-1)?'1':'0';
                if((s[x+1][i]=='?'&&s[x][i]<'9')||s[x][i]<s[x+1][i]) up=1;
                if(s[x][i]>s[x+1][i]&&!up){
                    return 0;
                }
            }
            return 1;
        }else{
            char t[10];
            bool bad=1;
            for(int i=0;i<l[x];i++) t[i]=s[x-1][i];
            for(int i=0;i<l[x];i++) if(s[x-1][i]!='9') bad=0;
            t[l[x]]=0;
            if(bad) return 0;
            t[0]++;
            for(int i=0;i<l[x];i++){
                if(t[i]>'9'){
                    t[i+1]++;
                    t[i]-=10;
                }
            }
            t[l[x]]=0;
            bool up=0,up2=0;
            for(int i=l[x]-1;i>=0;i--){
                if(s[x][i]=='?'){
                    if(up){
                        s[x][i]='0';
                    }else{
                        s[x][i]=t[i];
                        bool ok=1;
                        for(int j=i-1;j>=0;j--){
                            if(s[x][j]!='?'){
                                if(s[x][j]>t[j]) break;
                                if(s[x][j]<t[j]) {
                                    ok=0;break;
                                }
                            }else{
                                if(t[j]<'9') break;
                            }
                        }
                        if(!ok){
                            s[x][i]=t[i]+1;
                            if(s[x][i]>'9') return 0;
                        }
                    }
                }
                if(s[x][i]>s[x-1][i]) up=1;
                if(s[x][i]<s[x-1][i]&&!up){
                    return 0;
                }
                if((s[x+1][i]=='?'&&s[x][i]<'9')||s[x][i]<s[x+1][i]) up2=1;
                if(s[x][i]>s[x+1][i]&&!up2){
                    return 0;
                }
            }
            return 1;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]);
        l[i]=strlen(s[i]);
        reverse(s[i],s[i]+l[i]);
    }
    for(int i=2;i<=n;i++){
        if(l[i]<l[i-1]){
            puts("NO");
            return 0;
        }
    }
    bool ok=1;
    for(int i=1;i<=n&&ok;i++){
        if(!tianchong(i,i==n||l[i+1]>l[i])) ok=0;
    }
    if(ok){
        puts("YES");
        for(int i=1;i<=n;i++){
            reverse(s[i],s[i]+l[i]);
            puts(s[i]);
        }
    }else puts("NO");
//  while(1);
    return 0;
}