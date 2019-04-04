#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);

const int MAXN = 100005;
int ls[MAXN],rs[MAXN],fa[MAXN],root,num[MAXN];
unsigned long long hash[MAXN],pow[MAXN],val[MAXN];
void push_up(int x){
	if(!x) return;
	num[x]=1;
	if(ls[x]) num[x]+=num[ls[x]];
	if(rs[x]) num[x]+=num[rs[x]];
	if(ls[x]&&rs[x]){
		hash[x]=hash[ls[x]]*pow[num[rs[x]]+1]+val[x]*pow[num[rs[x]]]+hash[rs[x]];
	}else if(ls[x]){
		hash[x]=hash[ls[x]]*pow[1]+val[x];
	}else if(rs[x]){
		hash[x]=hash[rs[x]]+val[x]*pow[num[rs[x]]];
	}else{
		hash[x]=val[x];
	}
}
char s[MAXN];
void zig(int x){
	int y=fa[x];
	if(rs[x]) ls[y]=rs[x],fa[rs[x]]=y;else ls[y]=0;
	fa[x]=fa[y];
	if(fa[x]){
		if(ls[fa[x]]==y) ls[fa[x]]=x;else rs[fa[x]]=x;
	}
	fa[y]=x;rs[x]=y;
	push_up(y);push_up(x);
}
void zag(int x){
	int y=fa[x];
	if(ls[x]) rs[y]=ls[x],fa[ls[x]]=y;else rs[y]=0;
	fa[x]=fa[y];
	if(fa[x]){
		if(ls[fa[x]]==y) ls[fa[x]]=x;else rs[fa[x]]=x;
	}
	fa[y]=x;ls[x]=y;
	push_up(y);push_up(x);
}
void splay(int x,int z){
	while(fa[x]!=z){
		int y=fa[x];
		if(fa[y]==z){
			if(ls[y]==x) zig(x);else zag(x);
		}else{
			if(ls[fa[y]]==y){
				if(ls[y]==x) zig(y),zig(x);else zag(x),zig(x);
			}else{
				if(ls[y]==x) zig(x),zag(x);else zag(y),zag(x);
			}
		}
	}
	if(!z) root=x;
}
int Select(int pos){
	pos++;
	int o=root;
	while(num[ls[o]]+1!=pos){
		if(num[ls[o]]>=pos) o=ls[o];
		else pos-=num[ls[o]]+1,o=rs[o];
	}
	return o;
}

int mk(int l,int r){
	if(l>r) return 0;
	if(l==r){
		val[l]=s[l]-'a'+1;
		push_up(l);
		return l;
	}else{
		int mid=(l+r)>>1;
		val[mid]=s[mid]-'a'+1;
		ls[mid]=mk(l,mid-1);
		rs[mid]=mk(mid+1,r);
		if(ls[mid]) fa[ls[mid]]=mid;
		if(rs[mid]) fa[rs[mid]]=mid;
		push_up(mid);
		return mid;
	}
}
int m;
char tmp[10];
bool judge(int x,int y,int l){
	unsigned long long hash1;
	int a,b;
	a=Select(x-1),b=Select(x+l);
	splay(a,0),splay(b,a);
	hash1=hash[ls[b]];
	a=Select(y-1),b=Select(y+l);
	splay(a,0),splay(b,a);
	if(hash1==hash[ls[b]]) return 1;
	else return 0;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	pow[0]=1;
	for(int i=1;i<=100000;i++) pow[i]=pow[i-1]*13331;
	scanf("%s",s+2);
	int n=strlen(s+2);
	s[1]='$';s[n+2]='#';
	root=mk(1,n+2);
	n+=2;
	scanf("%d",&m);
	while(m--){
		scanf("%s",tmp);
		if(tmp[0]=='Q'){
			int x,y;
			scanf("%d%d",&x,&y);
			int l=0,r=min(n-x,n-y);
			while(r-l>1){
				int mid=(l+r)>>1;
				if(judge(x,y,mid)) l=mid;
				else r=mid;
			}
			printf("%d\n",l);
		}else if(tmp[0]=='R'){
			int x;
			scanf("%d%s",&x,tmp);
			x=Select(x);
			splay(x,0);
			val[x]=tmp[0]-'a'+1;
			push_up(x);
		}else{
			int x;
			scanf("%d%s",&x,tmp);
			int a=Select(x),b=Select(x+1);
			splay(a,0);splay(b,a);
			++n;
			val[n]=tmp[0]-'a'+1;
			ls[b]=n;
			fa[n]=b;
			push_up(n);
			splay(n,0);
		}
	}
	return 0;
}
