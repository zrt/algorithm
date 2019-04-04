// 串建SAM 拿Trie跑
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n;
const int MAXN=1000005;
int H[MAXN],X[MAXN],tot,P[MAXN],a[MAXN];
inline void _add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
char s[MAXN<<3];
int l[MAXN*14],c[MAXN*14],cc,x[MAXN*14],go[MAXN*14][3],fa[MAXN*14];
int root,last;
void add(int w){
	int p=last,np=++cc;
	last=np;l[np]=l[p]+1;
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
			int nq=++cc;
			fa[nq]=fa[q];
			fa[q]=fa[np]=nq;
			l[nq]=l[p]+1;
			memcpy(go[nq],go[q],sizeof go[q]);
			while(go[p][w]==q) go[p][w]=nq,p=fa[p];
		}
	}
}
int L;
int len[MAXN],pos[MAXN];
int num[MAXN*14];
queue<int> q;
typedef long long LL;
LL ans;
int main(){
	//freopen("in","r",stdin);
	scanf("%d",&n);
	for(int i=2,x;i<=n;i++){
		scanf("%d%s",&x,s);
		_add(x,i);a[i]=s[0]-'a';
	}
	scanf("%s",s);
	root=last=++cc;
	L=strlen(s);
	for(int i=0;i<L;i++) add(s[i]-'a');
	for(int i=1;i<=cc;i++) c[l[i]]++;
	for(int i=1;i<=L;i++) c[i]+=c[i-1];
	for(int i=1;i<=cc;i++) x[c[l[i]]--]=i;//!!!!!
	for(int i=0;i<=L;i++) c[i]=0;
	int p=root;
	for(int i=0;i<L;i++){
		p=go[p][s[i]-'a'];
		c[p]++;
	}
	for(int i=cc;i>=1;i--){
		if(fa[x[i]]) c[fa[x[i]]]+=c[x[i]];
	}
	q.push(1);pos[1]=root;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=H[x];i;i=X[i]){
			if(go[pos[x]][a[P[i]]]){
				pos[P[i]]=go[pos[x]][a[P[i]]];
				len[P[i]]=len[x]+1;
			}else{
				int p=pos[x];
				while(p&&!go[p][a[P[i]]]) p=fa[p];
				if(!p){
					pos[P[i]]=root;
					len[P[i]]=0;
				}else{
					pos[P[i]]=go[p][a[P[i]]];
					len[P[i]]=l[p]+1;
				}
			}
			ans+=(len[P[i]]-l[fa[pos[P[i]]]])*1LL*c[pos[P[i]]];
			num[fa[pos[P[i]]]]++;
			q.push(P[i]);
		}
	}
	for(int i=cc;i>=1;i--){
		if(fa[x[i]]) num[fa[x[i]]]+=num[x[i]];
	}
	for(int i=cc;i>=1;i--){
		ans+=(l[x[i]]-l[fa[x[i]]])*1LL*c[x[i]]*num[x[i]];
	}
	printf("%lld\n",ans);
	return 0;
}
