#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int n,m;
int a[40005];
int b[40005];
int SIZE;
int cc;
vector<int> v[40005];
int tot;
int d[205][205],p[205][205];
int st[205];
int ed[205];
int cs[40005];
int ask(int l,int r){
	int L=(l-1)/SIZE+1,R=(r-1)/SIZE+1;
	int ansn=p[L+1][R-1],anss=d[L+1][R-1];
	for(int i=l;i<=ed[L]&&i<=r;i++){
		int cnt=upper_bound(v[a[i]].begin(),v[a[i]].end(),r)-lower_bound(v[a[i]].begin(),v[a[i]].end(),l);
		if(cnt>anss){
			ansn=a[i];anss=cnt;
		}else if(cnt==anss&&a[i]<ansn){
			ansn=a[i];
		}
	}
	for(int i=max(st[R],l);i<=r;i++){
		int cnt=upper_bound(v[a[i]].begin(),v[a[i]].end(),r)-lower_bound(v[a[i]].begin(),v[a[i]].end(),l);
		if(cnt>anss){
			ansn=a[i];anss=cnt;
		}else if(cnt==anss&&a[i]<ansn){
			ansn=a[i];
		}
	}
	return ansn;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	SIZE=sqrt(n+0.5);
	if(SIZE==0) SIZE=1;
	tot=n/SIZE;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	cc=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(b+1,b+cc+1,a[i])-b;
	}
	for(int i=1;i<=n;i++){
		v[a[i]].push_back(i);
	}
	for(int i=1;i<=tot;i++){
		st[i]=ed[i-1]+1;
		ed[i]=st[i]+SIZE-1;
	}
	if(ed[tot]!=n){
		tot++;
		st[tot]=ed[tot-1]+1;
		ed[tot]=n;
	}
	int cnum,csum;
	for(int i=1;i<=tot;i++){
		csum=0;
		memset(cs,0,sizeof cs);
		for(int j=i;j<=tot;j++){
			for(int k=st[j];k<=ed[j];k++){
				cs[a[k]]++;
				if(cs[a[k]]>csum){
					csum=cs[a[k]];
					cnum=a[k];
				}else if(cs[a[k]]==csum){
					cnum=min(cnum,a[k]);
				}
			}
			d[i][j]=csum;
			p[i][j]=cnum;
		}
	}
	int x=0,l,r;
	for(int i=0;i<m;i++){
		scanf("%d%d",&l,&r);
		l=(l+x-1)%n+1;r=(r+x-1)%n+1;
		if(l>r) swap(l,r);
	//	printf("%d %d\n",l,r);
		printf("%d\n",x=b[ask(l,r)]);
	}
	return 0;
}
