#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int mod=1e9+7;
int n;
struct N{
	int a[11];
	// a[1]..a[10] defen
	long long hash(){
		long long ret=0;
		for(int i=0;i<=n;i++){
			ret=ret*31+a[i]+1;
		}
		return ret;
	}
	void st(){
		sort(a+n-a[0]+1,a+n+1);
	}
}start,bound;
map<long long ,int > Map;
int dfs(const int step,N now){
	if(now.a[0]==1) return Map[now.hash()]=-1;
	if(now.a[n-now.a[0]+1]>3*(n-step+1)) return -1;
	if(step>n){
		--now.a[0];
		now.st();
		if(Map[now.hash()]) return Map[now.hash()];
		return dfs(n-now.a[0]+2,now);
	}
	long long res=0,tmp;
	int idx=n-now.a[0]+1;
	if(now.a[idx]>=3){
		now.a[idx]-=3;
		tmp=dfs(step+1,now);
		if(tmp!=-1) (res+=tmp)%=mod;
		now.a[idx]+=3;
	}
	if(now.a[idx]>=1&&now.a[step]>=1){
		now.a[idx]-=1;now.a[step]-=1;
		tmp=dfs(step+1,now);
		if(tmp!=-1) (res+=tmp)%=mod;
		now.a[idx]+=1;now.a[step]+=1;
	}
	if(now.a[step]>=3){
		now.a[step]-=3;
		tmp=dfs(step+1,now);
		if(tmp!=-1) (res+=tmp)%=mod;
		now.a[step]+=3;
	}
	res=res?res:-1;
	if(step==idx+1) Map[now.hash()]=res;
	return res;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&start.a[i]);
	start.a[0]=n;
	start.st();
	bound.a[0]=1;
	bound.a[n]=0;
	Map[bound.hash()]=1;
	printf("%d\n",dfs(2,start));	
	return 0;
}
