#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int k;
char s1[100005],s2[100005];
int last,tot,root;
int fa[200005],go[200005][52];
int c[200005],l[200005],t[200005],x[200005];
int num[200005];
int get(char c){
	if(c>='a'&&c<='z') return c-'a';
	else return c-'A'+26;
}
void add(int w){
	int p=last;
	int np=++tot;
	last=np;
	l[np]=l[p]+1;
	while(p&&!go[p][w]){
		go[p][w]=np;
		p=fa[p];
	}
	if(!p){
		fa[np]=root;
	}else{
		int q=go[p][w];
		if(l[q]==l[p]+1){
			fa[np]=q;
		}else{
			int nq=++tot;
			l[nq]=l[p]+1;
			fa[nq]=fa[q];
			memcpy(go[nq],go[q],sizeof go[q]);
			fa[np]=fa[q]=nq;
			while(go[p][w]==q) go[p][w]=nq,p=fa[p];
		}
	}
}
int main(){
	while(scanf("%d",&k),k){
		scanf("%s%s",s1,s2);
		int L=strlen(s1);
		for(int i=1;i<=L*2;i++){
			memset(go[i],0,sizeof go[i]);
		}
		root=last=tot=1;
		for(int i=0;s1[i];i++){
			add(get(s1[i]));
		}
		for(int i=1;i<=tot;i++) c[i]=num[i]=t[i]=0;
		int p=root;
		for(int i=0;s1[i];i++){
			p=go[p][get(s1[i])];
			c[p]++;
		}
		for(int i=1;i<=tot;i++) t[l[i]]++;
		for(int i=1;i<=L;i++) t[i]+=t[i-1];
		for(int i=1;i<=tot;i++) x[t[l[i]]--]=i;
		for(int i=tot;i>=1;i--){
			if(fa[x[i]])c[fa[x[i]]]+=c[x[i]];
		}
		p=root;L=0;
		long long ans=0;
		for(int i=0;s2[i];i++){
			int w=get(s2[i]);
			if(go[p][w]) p=go[p][w],L++;
			else{
				while(p&&!go[p][w]) p=fa[p];
				if(!p) p=root,L=0;
				else L=l[p]+1,p=go[p][w];
			}
			if(L>=k) {
				if(fa[p]) num[fa[p]]++;
				ans+=c[p]*1LL*(L-max(k,l[fa[p]]+1)+1);
			}
		}
		for(int i=tot;i>=1;i--){
			if(fa[x[i]]) num[fa[x[i]]]+=num[x[i]];
		}
		for(int i=2;i<=tot;i++){
			if(l[i]<k) continue;
			ans+=c[i]*1LL*(l[i]-max(k,l[fa[i]]+1)+1)*num[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
