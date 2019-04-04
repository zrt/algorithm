#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;

char s[10];

int main(){
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	int x,y;
	int mx =0,my = 0;
	while(n--){
		cin >> s>>x>>y;
		if(x>y) swap(x,y);
		if(s[0] == '+'){
			mx = max(mx,x);
			my = max(my,y);
		}else{
			//
			// cout<< x<<" "<<y<<" "<<mx<<" "<<my<<endl;
			if(mx<=x && my<=y){
				puts("YES");
			}else{
				puts("NO");
			}

		}
	}



	return 0;
}