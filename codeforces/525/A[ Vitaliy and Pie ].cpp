#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
char s[300005];
int num[27];
int main(){
	scanf("%d",&n);
	scanf("%s",s);
	int ans=0;
	for(int i=0;i<n-1;i++){
		num[s[i<<1]-'a']++;
		if(num[s[i<<1|1]-'A']>0){
			num[s[i<<1|1]-'A']--;
		}else ans++;
	}
	printf("%d\n",ans);
	return 0;
}
