#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int n,m,k;
long long ans;
typedef unsigned long long llu;
char s[30005][205];
llu hash[30005];
map<llu,int> mp;
llu pow[205];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	pow[0]=1;
	for(int i=1;i<=m;i++) pow[i]=pow[i-1]*13131;
	for(int i=0;i<n;i++){
		scanf("%s",s[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			hash[i]=hash[i]*13131+s[i][j];
		}
	}
	for(int p=0;p<m;p++){
		mp.clear();
		for(int i=0;i<n;i++){
			llu h=hash[i]-s[i][p]*pow[m-p-1];
			mp[h]++;
		}
		for(map< llu ,int>::iterator it=mp.begin();it!=mp.end();it++){
			if(it->second){
				ans+=it->second*(it->second-1)/2;
			}
		}
	}
	mp.clear();
	for(int i=0;i<n;i++) mp[hash[i]]++;
	for(map<llu,int>::iterator it=mp.begin();it!=mp.end();it++){
		if(it->second){
			ans-=it->second*(it->second-1)/2*m;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
