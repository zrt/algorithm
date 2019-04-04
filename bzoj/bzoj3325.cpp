#include<bits/stdc++.h>
using namespace std;
int n;
int l[200005];
int fa[200005];
int mark[200005][26];
int s[200005];
void Read(int &digit)
{
	digit=0;
	char c;
	for(c=getchar();c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';digit=digit*10+c-'0',c=getchar());
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		Read(l[i<<1]);
	}
	for(int i=1;i<n;i++){
		Read(l[i<<1|1]);
	}
	int m=2*n;
	for(int i=1;i<=m;i++) fa[i]=i;
	int id=1,mx=1;
	for(int i=2;i<=m;i++){
		int p=mx>=i?min(l[id-(i-id)],mx-i):0;
		for(int j=p;j<=l[i];j++){
			if(fa[i+j]==i+j){
				fa[i+j]=i-j;
			}
		}
		if(i+l[i]>mx) mx=i+l[i],id=i;
	}
	for(int i=1;i<=m;i++) fa[i]=fa[fa[i]];
	for(int i=2;i<=m;i++){
		if(~i&1){
			if(fa[i]==i){
				for(s[i]=0;mark[i][s[i]];s[i]++);
			}else s[i]=s[fa[i]];
			putchar(s[i]+'a');
		}
		mark[i+l[i]+1][s[i-l[i]-1]]=1;
	}
	puts("");
	return 0;
}
