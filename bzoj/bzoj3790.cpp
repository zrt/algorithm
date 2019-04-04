#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[250000],a[250000];
int p[250000];
int f[250000];
int c[250000];
int L;
struct N{
	int l,r;
}b[250000];
bool cmp(const N&a,const N&b){
	if(a.r!=b.r) return a.r<b.r;
	return a.l<b.l;
}
#define lowbit(x) ((x)&-(x))
void change(int pos,int k){
	while(pos>0){
		c[pos]=min(c[pos],k);
		pos-=lowbit(pos);
	}
}
int ask(int pos){
	if(pos==0) return -1;
	int ret=0x7fffffff;
	while(pos<=L){
		ret=min(ret,c[pos]);
		pos+=lowbit(pos);
	}	
	return ret;
}
int main(){
	while(~scanf("%s",s+1)){
		L=strlen(s+1);
		for(int i=1;i<=L;i++){
			a[i*2]=s[i];a[i*2+1]='#';
		}
		a[1]='#';
		a[0]='$';
		int id,mx=-1;
		int l=L*2;
		for(int i=1;i<=l;i++){
			p[i]=1;
			if(i<mx){
				p[i]=min(p[id-(i-id)],mx-i);
			}
			while(a[i-p[i]]==a[i+p[i]]) p[i]++;
			if(mx<i+p[i]-1){
				mx=i+p[i]-1;
				id=i;
			}
		}
		int tot=0;
		for(int i=2;i<=l;i++){
			if(!(i&1)){
				p[i]--;
				b[tot].l=i/2-p[i]/2;
				b[tot].r=i/2+p[i]/2;
				tot++;
			}else{
				if(p[i]==1) continue;
				b[tot].l=i/2-p[i]/2+1;
				b[tot].r=i/2+p[i]/2;
				tot++;
			}
		}
		sort(b,b+tot,cmp);
		memset(c,0x3f,sizeof c);
		memset(f,0x3f,sizeof f);
		for(int i=0;i<tot;i++){
			f[b[i].r]=min(f[b[i].r],ask(b[i].l-1)+1);
			change(b[i].r,f[b[i].r]);
		}
		printf("%d\n",f[L]);
	}
	return 0;
}
