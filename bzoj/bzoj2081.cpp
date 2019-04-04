#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=200005;
int n;
int a[MAXN];
int b[MAXN];
typedef long long LL;
const int mod=1e9+7;
LL hash_a[MAXN],hash_b[MAXN];
LL power[MAXN];
// 13331
vector<int> ans;
void get_hash(LL hash[],int a[]){
	hash[0]=0;
	for(int i=1;i<=n;i++) hash[i]=(hash[i-1]*13331+a[i])%mod;
}
LL get_hash(LL hash[],int l,int r){
	return (hash[r]-hash[l-1]*power[r-l+1]%mod+mod)%mod;
}
LL hash(int L,int R){
	return min(get_hash(hash_a,L,R),get_hash(hash_b,n-R+1,n-L+1));
}
int Ans;
LL list[MAXN],t;
int getans(int k){
	int num=n/k;t=0;
	for(int i=1;i<=num;i++){
		int L=(i-1)*k+1,R=i*k;
		list[t++]=hash(L,R);
	}
	sort(list,list+t);
	t=unique(list,list+t)-list;
	return t;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) b[i]=a[n-i+1];
	get_hash(hash_a,a);get_hash(hash_b,b);
	power[0]=1;
	for(int i=1;i<=n;i++) power[i]=power[i-1]*13331%mod;
	for(int i=1;i<=n;i++){
		int tmp=getans(i);
		if(tmp>Ans){
			Ans=tmp;ans.clear();
			ans.push_back(i);
		}else if(tmp==Ans) ans.push_back(i);
	}
	printf("%d %u\n",Ans,ans.size());
	bool ok=1;
	for(int i=0;i<ans.size();i++){
		if(ok) ok=0;else putchar(' ');
		printf("%d",ans[i]);
	}
	puts("");
	return 0;
}
