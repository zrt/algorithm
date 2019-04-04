#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[50005],b[50005],stk[50005],top;
int st[50005][17];
int pos[50005][17];
int log;
inline int ask(int l,int r){
	int d=r-l+1;
	int lg;
	for(lg=0;1<<lg<=d;lg++);lg--;
	int a=st[l][lg];
	int b=st[r-(1<<lg)+1][lg];
	if(a>b){
		return pos[l][lg];
	}else return pos[r-(1<<lg)+1][lg];
}
int main(){
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){// dan diao di jian
			if(top==0){
				stk[top++]=i;
			}else if(a[i]>a[stk[top-1]]){
				stk[top++]=i;
			}else{
				while(top>0&&a[i]<=a[stk[top-1]]){
					b[stk[top-1]]=i-1;
					top--;
				}
				i--;continue;
			}
		}
		while(top>0){
			b[stk[top-1]]=n;
			top--;
		}
		for(log=0;1<<log<=n;log++);log--;
		for(int i=1;i<=n;i++){
			st[i][0]=a[i];pos[i][0]=i;
		}
		for(int i=1;i<=log;i++){
			for(int j=1;j<=n;j++){
				if(j+(1<<i)-1<=n){
					if(st[j][i-1]<=st[j+(1<<(i-1))][i-1]){
						st[j][i]=st[j+(1<<(i-1))][i-1];
						pos[j][i]=pos[j+(1<<(i-1))][i-1];
					}else{
						st[j][i]=st[j][i-1];
						pos[j][i]=pos[j][i-1];
					}
				}
			}
		}
		int ans=-1;
		for(int i=1;i<=n;i++){
			int k=ask(i,b[i]);
			if(k-i>0)ans=max(ans,k-i);
		}
		printf("%d\n",ans);
	}
	return 0;
}