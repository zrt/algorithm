/*
ID: zrtdrea1
PROG:
LANG: C++
*/
#include<cstdio>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int n,a[100005];
//int num[100005];
int stk[100005],top;
int lft[100005],rgt;
long long ans=-(1LL<<60);int pos;
long long sum[100005];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);lft[i]=i;
	}
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		if(top==0){
			stk[top++]=i;
			lft[i]=1;
		}else{
			if(a[stk[top-1]]<a[i]){
				lft[i]=stk[top-1]+1;
				stk[top++]=i;
			}else if(a[stk[top-1]]==a[i]){   //!!!!!       <-- there
				lft[i]=lft[stk[top-1]];   
				stk[top++]=i;
			}else{
				while(top>0&&a[stk[top-1]]>a[i]){
					if(a[stk[top-1]]*(sum[i-1]-sum[lft[stk[top-1]]-1])>=ans){
						ans=a[stk[top-1]]*(sum[i-1]-sum[lft[stk[top-1]]-1]);
						pos=stk[top-1];rgt=i-1;
					}
					top--;
				}
				i--;continue;
			}
		}
	} 
	while(top>0){
		if(a[stk[top-1]]*(sum[n]-sum[lft[stk[top-1]]-1])>=ans){
			ans=a[stk[top-1]]*(sum[n]-sum[lft[stk[top-1]]-1]);
			pos=stk[top-1];rgt=n;
		}
		top--;
	}
	printf("%lld\n%d %d\n",ans,lft[pos],rgt);
	return 0;
}
