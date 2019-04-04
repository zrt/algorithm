#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

int n;
char s[500005];
int leftminusright = 0;
bool checkeq(){
	leftminusright = 0;
	int sum = 0;
	for(int i=0;s[i];i++){
		if(s[i] == '('){
			sum ++;
		}else{
			sum --;
		}
		if(sum < 0) return false;
	}
	if(sum == 0) return true;
	return false;
}

bool checkleftmore(){
	leftminusright = 0;
	int sum = 0;
	for(int i=0;s[i];i++){
		if(s[i] == '('){
			sum ++;
		}else{
			sum --;
		}
		if(sum < 0) return false;
	}
	leftminusright = sum;
	if(sum > 0) return true;
	return false;
}

bool checkrightmore(){
	leftminusright = 0;
	int sum = 0;
	int len = strlen(s);
	for(int i=len-1;i>=0;i--){
		if(s[i] == ')'){
			sum ++;
		}else{
			sum --;
		}
		if(sum < 0) return false;
	}
	leftminusright = -sum;
	if(sum > 0) return true;
	return false;
}
int tot[3];
int cnt[3][100005];
int cnt2[3][500005];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s);
		int type = -1;
		if(checkeq()) type = 0;
		else if(checkleftmore()) type = 1;
		else if(checkrightmore()) type = 2;
		if(type == -1) continue;
		cnt[type][tot[type]++] = leftminusright; 
	}
	int ans = 0;
	ans += tot[0]/2;
	for(int i=0;i<tot[1];i++){
		cnt2[0][cnt[1][i]] ++;
	}
	for(int i=0;i<tot[2];i++){
		cnt2[1][-cnt[2][i]] ++;
	}
	for(int i=0;i<=500000;i++){
		ans += min(cnt2[0][i],cnt2[1][i]);
	}
	printf("%d\n",ans);

	return 0;
}
