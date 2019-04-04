#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
//by zrt
//problem:
using namespace std;
int T,n,m,x,y;
char s[50][50];
int H[2505],P[5005],X[5005],tot;
int val[2505];
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int _H[2505],_P[5005],_X[5005],_tot;
inline void _add(int x,int y){
	_P[++_tot]=y;_X[_tot]=_H[x];_H[x]=_tot;
}
int dfn[2505],tim,low[2505],stk[2505],top,cnt,point[2505],siz[2505];
bool instack[2505];
void tarjan(int u){
	low[u]=dfn[u]=++tim;
	instack[u]=1;stk[top++]=u;
	for(int i=H[u];i;i=X[i]){
		if(!dfn[P[i]]){
			tarjan(P[i]);
			low[u]=min(low[u],low[P[i]]);
		}else if(instack[P[i]]) low[u]=min(low[u],dfn[P[i]]);
	}
	if(dfn[u]==low[u]){
		++cnt;
		int k;
		do{
			k=stk[--top];
			instack[k]=0;
			point[k]=cnt;
			siz[cnt]+=val[k];
		}while(k!=u);
	}
}
int d[2505];
struct N{
	int x,w;
	N(int a=0,int b=0){
		x=a,w=b;
	}
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
}t;
priority_queue<N> q;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&T);
	while(T--){
		memset(H,0,sizeof H);cnt=tot=_tot=0;
		memset(_H,0,sizeof _H);
		memset(d,0,sizeof d);
		memset(val,0,sizeof val);
		top=0;
		memset(dfn,0,sizeof dfn);
		memset(siz,0,sizeof siz);
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%s",s[i]);
		}
		int tmp=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(s[i][j]>='0'&&s[i][j]<='9'){
					val[tmp]=s[i][j]-'0';
					if(j+1<m&&(s[i][j+1]!='#'))add(tmp,tmp+1);
					if(i+1<n&&(s[i+1][j]!='#'))add(tmp,tmp+m);
				}else if(s[i][j]=='*'){
					scanf("%d%d",&x,&y);
					add(tmp,x*m+y);
					if(j+1<m&&(s[i][j+1]!='#'))add(tmp,tmp+1);
					if(i+1<n&&(s[i+1][j]!='#'))add(tmp,tmp+m);
				}
				tmp++;
			}
		}
		int maxx=n*m;
		for(int i=0;i<maxx;i++){
			if(!dfn[i]){
				tarjan(i);
			}
		}
		for(int i=0;i<maxx;i++){
			for(int j=H[i];j;j=X[j]){
				if(point[i]!=point[P[j]]){
					_add(point[i],point[P[j]]);
				}
			}
		}
		d[point[0]]=siz[point[0]];
		q.push(N(point[0],d[point[0]]));
		int ret=0;
		while(!q.empty()){
			t=q.top();q.pop();
			if(ret<d[t.x]) ret=d[t.x];
			for(int i=_H[t.x];i;i=_X[i]){
				if(d[_P[i]]<d[t.x]+siz[_P[i]]){
					d[_P[i]]=d[t.x]+siz[_P[i]];
					q.push(N(_P[i],d[_P[i]]));
				}
			}
		}
		printf("%d\n",ret);
	}
	return 0;
}
