#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
char s[305];
char dict[604][30];
int n,l;
int f[305];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%s",&n,&l,s);
	for(int i=1;i<=n;i++){
		scanf("%s",dict[i]);
	}
	for(int i=l-1;i>=0;i--){
		f[i]=f[i+1]+1;
		for(int j=1;j<=n;j++){
			int k=0;
			int p;
			for(p=i;p<l;p++){
				if(dict[j][k]==s[p]) k++;
				if(dict[j][k]=='\0') break;
			}
			if(dict[j][k]=='\0'){
				f[i]=min(f[i],f[p+1]+p-i-k+1);
			}
		}
	}
	printf("%d\n",f[0]);
	return 0;
}
