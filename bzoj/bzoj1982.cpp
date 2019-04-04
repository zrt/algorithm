#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
string a[100005];
bool cmp(string a,string b){
	if(a.length()!=b.length()){
		return a.length()<b.length();
	}else return a<b;
}
int main(){
	scanf("%d",&n);
	if(n&1){
		puts("first player");
		return 0;
	}
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		if(!(i&1)){
			if(a[i]!=a[i+1]){
				puts("first player");
				return 0;
			}
		}
	}
	puts("second player");
	return 0;
}
