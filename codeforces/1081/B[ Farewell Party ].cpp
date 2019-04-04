#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int a[100005];
vector<int> v[100005];
int b[100005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		v[n-a[i]].push_back(i);
	}
	int gg = 0;
	int tt = 1;
	for(int i=1;i<=n;i++){
		if(v[i].size()%i!=0){
			gg = 1; break;
		}else{
			int tot = 0;
			for(int j=0;j<v[i].size();j++){
				tot++;
				b[v[i][j]] = tt;
				if(tot==i){
					tot = 0;
					tt++;
				}
			}
		}
	}
	if(gg) puts("Impossible");
	else{
		puts("Possible");
		for(int i=1;i<=n;i++){
			printf("%d ",b[i]);
		}
	}

	return 0;
}