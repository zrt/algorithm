#include<iostream>
using namespace std;
typedef long long LL;
LL a1,b1,a2,b2;
LL s1,s2,tot1,tot2,c1,c2;
int main(){
    cin>>a1>>b1>>a2>>b2;
    s1=a1*b1;
    s2=a2*b2;
    while(s1%2==0) tot1++,s1/=2;
    while(s2%2==0) tot2++,s2/=2;
    while(s1%3==0) c1++,s1/=3;
    while(s2%3==0) c2++,s2/=3;
    if(s1!=s2){
        cout<<"-1"<<endl;
        return 0;
    }else{
        LL ans=0;
        if(c1>c2){
            ans=c1-c2;
            tot1+=c1-c2;
            for(int i=c1-c2;i>0;i--){
                if(a1%3==0){
                    a1/=3;a1*=2;continue;
                };
                b1/=3;b1*=2;
            }
        }else if(c1<c2){
            ans=c2-c1;
            tot2+=c2-c1;
            for(int i=c2-c1;i>0;i--){
                if(a2%3==0) {
                    a2/=3;a2*=2;continue;
                }
                b2/=3;b2*=2;
            }
        }
        if(tot1>tot2){
            ans+=tot1-tot2;
            for(int i=tot1-tot2;i>0;i--){
                if(a1%2==0){
                    a1/=2;continue;
                }
                b1/=2;
            }
        }else if(tot1<tot2){
            ans+=tot2-tot1;
            for(int i=tot2-tot1;i>0;i--){
                if(a2%2==0) {
                    a2/=2;continue;
                }
                b2/=2;
            }
        }
        cout<<ans<<endl<<a1<<' '<<b1<<endl<<a2<<' '<<b2<<endl;
    }
//  while(1);
    return 0;
}