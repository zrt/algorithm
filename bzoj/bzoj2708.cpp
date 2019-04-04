#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int p[55];
int f[55];
int match(int l,int r){
	for(int k=1;k<=r-l+1;k++){
		if(abs(p[l+k-1]-p[r-k+1])<=1) return k-1;
		for(int i=l;i<=r-k;i++){
			if(abs(p[i]-p[i+k])>1) return k-1;
		}
	}
	return r-l+1;
}
int main(){
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++) scanf("%d",&p[i]);
		sort(p+1,p+n+1);
		memset(f,0,sizeof f);
		for(int i=1;i<=n;i++){
			for(int j=0;j<i;j++){
				f[i]=max(f[i],f[j]+match(j+1,i));
			}
		}
		printf("%d\n",f[n]);
	}
	return 0;
}
