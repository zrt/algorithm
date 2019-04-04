#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<map>
#include<vector>
using namespace std;
typedef long long LL;
LL c,b,p;
LL pow(LL a,LL b,LL p){
    LL ret=1%p;
    while(b){
        if(b&1){
            ret=ret*a%p;
        }
        b>>=1;
        a=a*a%p;
    }
    return ret;
}
LL jie(LL a){
    LL x=p-1;
    LL lim=(LL)(sqrt((double)x)+0.5);
    LL mn=x;
    for(int i=1;i<=lim;i++){
        if(x%i==0){
            if(pow(a,i,p)==1){
                mn=min(mn,i*1LL);
            }
            if(pow(a,x/i,p)==1){
                mn=min(mn,x/i*1LL);
            }
        }
    }
    return mn;
}
LL g;
map<LL,LL> mp;
LL ni(LL x){
    return pow(x,p-2,p);
}
LL BSGS(int b,int a,int p){
    LL lim=sqrt(p)+1;
    LL tmp=b,Ni=ni(a);
    for(int i=0;i<=lim;i++){
        mp[tmp]=i;
        tmp=tmp*Ni%p;
    }
    LL step=pow(a,lim,p);
    tmp=1;
    for(int i=0;i<=lim;i++){
        if(mp.find(tmp)!=mp.end()){
            return i*lim+mp[tmp];
        }
        tmp=tmp*step%p;
    }
}
LL phi;
LL gcd(LL a,LL b){
    return b?gcd(b,a%b):a;
}
vector<LL> ans;
void exgcd(LL a,LL b,LL&x,LL&y){
    if(!b){
        x=1,y=0;
    }else{
        exgcd(b,a%b,y,x);y-=x*(a/b);
    }
}
int main(){
//	freopen("kroot.in","r",stdin);
//	freopen("kroot.out","w",stdout);
    cin>>p>>b>>c;
    for(g=1;;g++){
        if(jie(g)==p-1){
            break;
        }
    }
    c=BSGS(c,g,p);
    phi=p-1;
    LL GCD=gcd(b,phi);
    if(c%GCD){
        puts("0");
    }else{
        LL B=b/GCD;
        LL PHI=phi/GCD;
        LL C=c/GCD;
        LL x,y;
        exgcd(B,PHI,x,y);
        x=(x%PHI+PHI)%PHI;
        x=x*C%PHI;
        while(x<phi){
            ans.push_back(pow(g,x,p));
            x+=PHI;
        }
        sort(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        bool f=1;
        for(int i=0;i<ans.size();i++){
            if(f) f=0;else putchar('\n');
            printf("%lld",ans[i]);
        }
        puts("");
    }
//  system("pause");
	fclose(stdout);
    return 0;
}
