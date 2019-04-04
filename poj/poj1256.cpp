#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int n;
bool cmp(char a,char b){
	if(a>='a'&&a<='z'){
		if(b>='a'&&b<='z'){
			return a<b;
		}
		else{
			return a-'a'<b-'A';
		}
	}
	else{
		if(b>='a'&&b<='z'){
			return a-'A'<=b-'a';
		}
		else{
			return a<b;
		}
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	while(n--){
		string s;
		cin>>s;
		sort(s.begin(),s.end(),cmp);
		cout<<s<<'\n';
		while(next_permutation(s.begin(),s.end(),cmp)){
			cout<<s<<'\n';
		}
	}
	
	return 0;
}
