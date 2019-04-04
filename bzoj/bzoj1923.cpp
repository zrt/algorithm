#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
int n,m;
bitset<1005> in[2005],a[2005];
char s[1005];
bool Gauss(int m){
	for(int i=0;i<n;i++){
		bool ok=0;
		for(int j=i;j<m;j++){
			if(a[j][i]){
				ok=1;swap(a[i],a[j]);
			}
		}
		if(!ok) return 0;
		for(int j=i+1;j<m;j++){
			if(a[j][i]) a[j]^=a[i];
		}
	}
	for(int i=n-1;i>=0;i--){
		for(int j=i+1;j<n;j++){
			if(a[i][j]) a[i][n]=a[i][n]^a[j][n];
		}
	}
	return 1;
}
bool judge(int x){
	for(int i=0;i<x;i++) a[i]=in[i];
	if(Gauss(x)) return 1;
	else return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%s",s);
		for(int j=0;s[j];j++){
			if(s[j]=='0') in[i][j]=0;else in[i][j]=1;
		}
		scanf("%s",s);
		if(s[0]=='1') in[i][n]=1;
	}
	if(!judge(m)){
		puts("Cannot Determine");
		return 0;
	}
	int l=0,r=m;
	while(r-l>1){
		int mid=(l+r)>>1;
		if(judge(mid)) r=mid;
		else l=mid;
	}
	printf("%d\n",r);
	judge(r);
	for(int i=0;i<n;i++){
		if(a[i][n]) puts("?y7M#");
		else puts("Earth");
	}
	return 0;
}
