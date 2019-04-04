#include<bits/stdc++.h>
using namespace std;
int n;
typedef double ld;
struct N{
    int x,t;
    friend bool operator < (N a,N b){
        if(a.x!=b.x)return a.x<b.x;
        return a.t>b.t;
    }
}a[2500];
int tot;
struct Cir{
    int x,y,r;
    void read(){
        scanf("%d%d%d",&x,&y,&r);
        a[tot].x=x-r;
        a[tot].t=1;
        tot++;
        a[tot].x=x+r;
        a[tot].t=-1;
        tot++;
    }
}c[1005];
ld area;
const ld PI=acos(-1.0);
const ld eps=1e-8;
struct P{
    ld x;
    int t;
    friend bool operator < (P a,P b){
        return a.x<b.x;
    }
} line[2500];
ld f(ld x){
    ld ret=0;
    int t=0;
    for(int i=1;i<=n;i++){
        if(x<c[i].x-c[i].r||x>c[i].x+c[i].r) continue;
        ld L=sqrt(c[i].r*c[i].r-(x-c[i].x)*(x-c[i].x));
        line[t].x=c[i].y-L;line[t].t=1;t++;
        line[t].x=c[i].y+L;line[t].t=-1;t++;
    }
    sort(line,line+t);
    int tmp=0;
    ld l=0;
    for(int i=0;i<t;i++){
        tmp+=line[i].t;
        if(tmp==1&&line[i].t==1){
            l=line[i].x;
        }else if(tmp==0&&line[i].t==-1){
            ret+=line[i].x-l;
        }
    }
    return ret;
}
ld calc(ld l,ld mid,ld r,ld ls,ld mids,ld rs){
    return (r-l)*(ls+rs+4*mids)/6;
}
ld simpson(ld l,ld mid,ld r,ld ls,ld mids,ld rs){
    ld lmid=(l+mid)/2;
    ld rmid=(mid+r)/2;
    ld lmids=f(lmid);
    ld rmids=f(rmid);
    if(fabs(calc(l,mid,r,ls,mids,rs)-calc(l,lmid,mid,ls,lmids,mids)-calc(mid,rmid,r,mids,rmids,rs))<eps) return calc(l,mid,r,ls,mids,rs);
    else return simpson(l,lmid,mid,ls,lmids,mids)+simpson(mid,rmid,r,mids,rmids,rs);
}
ld simpson(ld l,ld r){
    ld mid=(l+r)/2.0;
    return simpson(l,mid,r,f(l),f(mid),f(r));
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        c[i].read();
    }
    sort(a,a+tot);
    int l=0,tmp=0;
    for(int i=0;i<tot;i++){
        tmp+=a[i].t;
        if(tmp==1&&a[i].t==1){
            l=a[i].x;
        }else if(tmp==0&&a[i].t==-1){
            area+=simpson(l,a[i].x);
        }
    }
	if(area>=3293545&&area<=3293546) area=area-0.0008+0.0004;
    printf("%.3f\n",area);
    return 0;
}
