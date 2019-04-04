#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
typedef long long LL;
int tt;
int n;
LL a[100005];
LL ans;
LL gcd(LL a,LL b){
	return b?gcd(b,a%b):a;
}
set<int> st;
set<int>::iterator it2;
int b[100005],tot;
int main(){
	scanf("%d",&tt);
	while(tt--){
		st.clear();
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++){
			st.insert(i);
			LL g=a[i],last;
			tot=0;
			for(set<int>::iterator it=st.end();;){
				--it;
				if(it==st.begin()) break;
				it2=it;
				--it2;
				ans=max(ans,(i-*it+1)*1LL*g);
				last=g;
				g=gcd(a[*it2],g);
				a[*it2]=g;
				if(last==g){
					b[++tot]=*it;
				}
			}
			ans=max(ans,i*1LL*g);
			for(int i=1;i<=tot;i++) st.erase(b[i]);
		}
		printf("%lld\n",ans);
	}
//	while(1);
	return 0;
}
