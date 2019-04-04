#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;

int n;
vector<int> v[100005];
int fa[100005];
int a[100005];
bool flag = 0;
int main(){	
	scanf("%d",&n);
	for(int i=2;i<=n;i++) scanf("%d",&fa[i]),v[fa[i]].push_back(i);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	flag = 1;
	LL sum = 0;
	for(int i=1;i<=n;i++){
		if(a[i]==-1){
			LL mn = 1LL << 60;
			for(int j=0;j<v[i].size();j++){
				mn = min(mn,a[v[i][j]]*1LL);
			}
			if(mn == (1LL<<60)){
				a[i] = a[fa[i]];
				if(fa[i] && a[fa[i]]>a[i]){
					flag = 0;
				}
			}else{
				a[i] = mn;
				if(fa[i] && a[fa[i]]>a[i]){
					flag = 0;
				}

			}
			sum += a[i]-a[fa[i]];

		}else{
			sum+=a[i]-a[fa[i]];
		}
	}
	if(flag) cout<<sum<<endl;
	else puts("-1");



	return 0;
}
