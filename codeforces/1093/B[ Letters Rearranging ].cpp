#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
char s[1000];
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%s",s);
		int l = strlen(s);
		sort(s,s+l);
		bool ok = 0;
		for(int i=0;i<l;i++){
			if(s[i]!=s[l-i-1]){
				ok = 1;
				break;
			}
		}
		if(ok){
			puts(s);
		}else{
			puts("-1");
		}
	}

	return 0;
}
