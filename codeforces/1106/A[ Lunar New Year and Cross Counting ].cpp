#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
int n;
char s[505][505];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s[i]);
	}
	int tot =0;
	for(int i=1;i<n-1;i++){
		for(int j=1;j<n-1;j++){
			if(s[i][j] == 'X' && s[i-1][j-1] == 'X' && s[i-1][j+1] == 'X'
			&& s[i+1][j+1] == 'X' && s[i+1][j-1] == 'X')
			 tot ++;
		}
	}
	cout << tot;

	return 0;
}
