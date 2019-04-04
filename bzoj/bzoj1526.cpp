#include<cstdio>
#include<cstring>
#include<algorithm>
//by zrt
//problem:
//无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std;
typedef long long ll;
const double eps(1e-10);
const int inf(0x7fffffff);
int last[10005][10];//>=
char s[1005][10005];
int num[1005];
int tot[10050];
int ans,n;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%s",&num[i],s[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<10;j++) last[num[i]][j]=-1;
		for(int j=num[i]-1;j>=0;j--){
			for(int k=0;k<10;k++) last[j][k]=last[j+1][k];
			last[j][s[i][j]-'0']=j;
		}
		for(int p=0;p<10000;p++){
			if(tot[p]<i) continue;
			bool ok=1;
			int idx=0;
				if(last[idx][p/1000]!=-1){
					idx=last[idx][p/1000];
				}else {
					ok=0;
				}
				if(last[idx][p/100%10]!=-1){
					idx=last[idx][p/100%10];
				}else {
					ok=0;
				}
				if(last[idx][p/10%10]!=-1){
					idx=last[idx][p/10%10];
				}else {
					ok=0;
				}
				if(last[idx][p%10]!=-1){
					idx=last[idx][p%10];
				}else {
					ok=0;
				}
			if(ok) tot[p]++;
		}
	}
	for(int i=0;i<10000;i++){
		if(tot[i]==n) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
