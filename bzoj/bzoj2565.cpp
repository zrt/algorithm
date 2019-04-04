#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[100005],a[210005];
int p[210005];
int l,mx,id;
int left[210005];
int mn[210005];
int main(){
	scanf("%s",s+1);
	for(int i=1;s[i];i++){
		a[2*i]=s[i];
		a[2*i+1]='#';
	}
	int l=strlen(s+1);
	a[1]='#';
	a[0]='$';
	mx=-1;
	for(int i=1;i<=l*2+1;i++){
		if(i<mx){p[i]=min(p[id-(i-id)],mx-i);}
		while(a[i+p[i]]==a[i-p[i]]) p[i]++;
		if(i+p[i]>mx) mx=i+p[i],id=i;
	}
	memset(mn,0x3f,sizeof mn);
	for(int i=1;i<=l*2;i++){
		mn[i+p[i]]=min(mn[i+p[i]],i);
	}
	left[l*2+1]=0x3f3f3f3f;
	for(int i=l*2;i>=1;i--) left[i]=min(left[i+1],mn[i]);
	int ans=0;
	for(int i=1;i<=l*2;i++){
		ans=max(ans,i-left[i-p[i]+1]);
	}
	printf("%d\n",ans);	
	return 0;
}
