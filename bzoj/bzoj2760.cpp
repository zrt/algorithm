#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
string h[1200],s[1200];
int num[1200];
int n,m;
int sum;
int hh;
int main(){
	//ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>s[0];
		int mx=0,tmp=0;
		for(int i=1;i<=m;i++){
			cin>>s[i];
			tmp=0;
			for(int j=0;j<s[i].length();j++){
				if(s[i][j]==',') tmp++;
			}
			num[i]=tmp;
			mx=max(mx,tmp);
		}
		h[0]=h[0]+','+s[0];
		for(int i=0;i<mx;i++) h[0]+=',';
		for(int i=hh+1;i<=m;i++){
			for(int j=0;j<sum;j++) h[i]+=',';
		}
		for(int i=m+1;i<=hh;i++){
			for(int j=0;j<=mx;j++) h[i]+=',';
		}
		for(int i=1;i<=m;i++){
			h[i]=h[i]+','+s[i];
			for(int j=num[i];j<mx;j++){
				h[i]+=',';
			}
		}
		hh=max(hh,m);sum+=mx+1;
	}
	for(int i=0;i<=hh;i++) printf("%s\n",h[i].substr(1,h[i].length()).c_str());
	return 0;
}
