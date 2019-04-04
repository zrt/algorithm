// 将Trie建SAM 拿串跑
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n;
const int MAXN=1000005;
int H[MAXN],P[MAXN],X[MAXN],tot;
int a[MAXN];//字母
inline void _add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int id[MAXN<<1];
int fa[MAXN<<1],go[MAXN<<1][3],l[MAXN<<1],c[MAXN<<1],x[MAXN<<1],t[MAXN<<1];
char s[MAXN<<3];
int root,cc;
void add(int x,int w){
	int p=id[x];
	if(go[p][a[w]]){//!!!!!!!!
		id[w]=go[p][a[w]];
		c[go[p][a[w]]]++;
		return;
	}
	int np=++cc;
	id[w]=np;w=a[w];c[np]++;
	l[np]=l[p]+1;
	while(p&&!go[p][w]){
		go[p][w]=np;
		p=fa[p];
	}
	if(!p) fa[np]=root;
	else{
		int q=go[p][w];
		if(l[q]==l[p]+1){
			fa[np]=q;
		}else{
			int nq=++cc;
			l[nq]=l[p]+1;
			memcpy(go[nq],go[q],sizeof go[q]);
			fa[nq]=fa[q];
			fa[q]=fa[np]=nq;
			while(go[p][w]==q){
				go[p][w]=nq;
				p=fa[p];
			}
		}
	}
}
queue<int> q;
int num[MAXN<<1];//完整包含
int main(){
	//freopen("in","r",stdin);
	id[1]=root=++cc;
	scanf("%d",&n);
	for(int i=2,x;i<=n;i++){
		scanf("%d%s",&x,s);
		_add(x,i);a[i]=s[0]-'a';
	}
	q.push(1);
	//dfs(1);
	
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			add(x,P[i]);q.push(P[i]);
		}
	}
	
	scanf("%s",s);
	for(int i=1;i<=cc;i++) t[l[i]]++;
	for(int i=1;i<=cc;i++) t[i]+=t[i-1];
	for(int i=1;i<=cc;i++) x[t[l[i]]--]=i;
	for(int i=cc;i>=1;i--){
		if(fa[x[i]]) c[fa[x[i]]]+=c[x[i]];
	}
	long long ans=0;
	int p=root,L=0;
	for(int i=0;s[i];i++){
		int w=s[i]-'a';
		if(go[p][w]){
			p=go[p][w];L++;
		}else{
			while(p&&!go[p][w]) p=fa[p];
			if(p) L=l[p]+1,p=go[p][w];
			else L=0,p=root;
		}
		if(fa[p]) num[fa[p]]++;
		if(L>0)ans+=c[p]*1LL*(L-l[fa[p]]);
	}
	for(int i=cc;i>=1;i--){
		if(fa[x[i]]){
			num[fa[x[i]]]+=num[x[i]];
		}
	}
	for(int i=1;i<=cc;i++){
		if(l[i]>0)ans+=(l[i]-l[fa[i]])*1LL*c[i]*num[i];
	}
	printf("%lld\n",ans);
	return 0;
}
