#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
char s[300005];
int n;
int mod=8388607;
int H[20000003];
int X[300005];
long long P[300005];
int cnt[300005];
long long st;
int tot;
long long ans;
inline void add(int x,long long y){
	for(int i=H[x];i;i=X[i]){
		if(P[i]==y){
			cnt[i]++;
			return ;
		}
	}
	P[++tot]=y;X[tot]=H[x];H[x]=tot;cnt[tot]=1;
}
int ask(long long x){
	for(int i=H[x&mod];i;i=X[i]){
		if(P[i]==x){
			return cnt[i];
		}
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		if(s[i]>='a'&&s[i]<='z'){
			s[i]-='a';
		}else s[i]=s[i]-'A'+26;
	}
	add(st&mod,st);
	for(int i=1;i<=n;i++){
		st^=1LL<<s[i];
		ans+=ask(st);
		for(int i=0;i<52;i++){
			ans+=ask(st^(1LL<<i));
		}
		add(st&mod,st);
	}
	cout<<ans<<endl;
	return 0;
}
