#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int n,c;
int pos[100005];
bool judge(int x){
	int tot=1;
	int sum=0;
	for(int i=2;i<=n;i++){
		sum+=pos[i]-pos[i-1];
		if(sum>=x){
			sum=0;tot++;
		}
	}
	if(tot>=c) return 1;
	else return 0;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++){
		scanf("%d",&pos[i]);
	}
	sort(pos+1,pos+n+1);
	int l=0,r=1000000000;
	while(r-l>1){
		int mid=(l+r)>>1;
		if(judge(mid)){
			l=mid;
		}else{
			r=mid;
		}
	}
	printf("%d\n",l);
	return 0;
}
