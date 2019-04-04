#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,p,k;
vector<int> lft[100005],rgt[100005];
int L[100005],R[100005];
int stk[100005],top;
int old;
int lt[100005],rt[100005];
int ans;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	//freopen("in","r",stdin);
	scanf("%d%d%d%d",&n,&m,&p,&k);
	for(int i=0,x,y,d;i<p;i++){
		scanf("%d%d%d",&x,&y,&d);
		if(!d){
			rgt[x+1].push_back(n-y);
		}else lft[x].push_back(n-y);
	}
	top=0;
	for(int i=1;i<=n;i++){
		L[i]=top;
		sort(lft[i].begin(),lft[i].end(),cmp);
		for(int j=0;j<lft[i].size();j++){
			if(top==0||lft[i][j]>=stk[top-1]) stk[top++]=lft[i][j];
			else *upper_bound(stk,stk+top,lft[i][j])=lft[i][j];
		}
	}
	top=0;
	for(int i=n;i>=1;i--){
		R[i]=top;
		sort(rgt[i].begin(),rgt[i].end(),cmp);
		for(int j=0;j<rgt[i].size();j++){
			if(top==0||rgt[i][j]>=stk[top-1]) stk[top++]=rgt[i][j];
			else *upper_bound(stk,stk+top,rgt[i][j])=rgt[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		if(L[i]==i-1&&R[i]==n-i) old++;
		lt[i]=i-1-L[i];
		rt[i]=n-i-R[i];
	}
	int j=0;
	for(int i=1;i<=n;i++){
		while(j+1<=n&&rt[i]+lt[j+1]<=k) j++;
		ans=max(ans,j-i+1);
	}
	//printf("%d %d\n",lt[1],rt[n]);
	printf("%d\n",ans-old);
	return 0;
}
