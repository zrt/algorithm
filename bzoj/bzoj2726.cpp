#include<iostream>
#include<algorithm>
#include<cstring>
// fuck f>0 but t<0
//fuck..............
//fuck..............
//fuck..............
//fuck..............
//fuck..............
using namespace std;
const int maxn=300005;
int t[maxn],c[maxn],q[maxn];
typedef long long LL;
LL sumt[maxn],sumf[maxn],f[maxn];
int n,s;
int l,r;
int search(int i,int time){
    if(l==r)
    return q[l];
    int L=l,R=r;
    while(L<R){
        int mid=(L+R)>>1;
        if(f[q[mid+1]]-time*sumf[q[mid+1]]<=f[q[mid]]-time*sumf[q[mid]])
        L=mid+1;
        else
        R=mid;
    }
    return q[L];
}
int main(){
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        cin>>t[i]>>c[i];
        sumt[i]=t[i]+sumt[i-1];
        sumf[i]=sumf[i-1]+c[i];
    }
    l=1,r=1;
    for(int i=1;i<=n;i++){
        int j=search(i,sumt[i]+s);
        f[i]=f[j]+(sumf[i]-sumf[j])*sumt[i]+(sumf[n]-sumf[j])*s;
        while(l<r&&(f[i]-f[q[r]])*(sumf[q[r]]-sumf[q[r-1]])<=(f[q[r]]-f[q[r-1]])*(sumf[i]-sumf[q[r]]))
        r--;
        q[++r]=i;
    }
    cout<<f[n]<<endl;
}
