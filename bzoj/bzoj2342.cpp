#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>

//by zrt
//problem:bzoj2342

using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int L;
char s[500005];
char a[1100005];
int p[1100005];
struct N{
	int i,ri;
}b[1100005];
bool cmp(N a,N b){
	return a.ri>b.ri;
}
set<int> st;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%s",&L,s+1);
	a[0]='$',a[1]='#';
	for(int i=1;i<=L;i++){
		a[i<<1]=s[i];
		a[i<<1|1]='#';
	}
	int id(0),mx(0);
	for(int i=1;i<=(L<<1|1);i++){
		if(i<mx){
			p[i]=min(p[id-(i-id)],mx-i);
		}else p[i]=1;
		while(a[i-p[i]]==a[i+p[i]]) p[i]++;
		if(i+p[i]>mx){
			mx=i+p[i];
			id=i;
		}
		b[i].i=i;b[i].ri=i+p[i]-1;
	}
	sort(b+1,b+1+(L<<1|1),cmp);
	int ans=0;
	int tot=1;
	for(int i=(L<<1|1)-4;i>=5;i-=2){
		int l=i-p[i]+1;
		while(b[tot].ri>=i){
			if(tot<=(L<<1|1)&&b[tot].i&1) st.insert(b[tot].i);
			tot++;
		}
		int k=*st.lower_bound((l+i)/2);
		ans=max(ans,(i-k)*4);
	}
	printf("%d\n",ans/2);
	return 0;
}
