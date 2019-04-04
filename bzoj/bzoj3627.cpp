#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<iostream>
using namespace std;
int n,m,k,limit,cost;
map<string,int> mp;
int a[10005],b[10005],c[10005];
string s,s2,s3;
int S,T;
bool check(string&s){
	int L=s.length();
	for(int i=0;i+2<L;i++){
		if(s[i]=='g'&&s[i+1]=='a'&&s[i+2]=='s'){
			return 1;
		}
	}
	return 0;
}
int H[10005],X[400050],P[400050],tot,tag[400050],ext[400050];
double E[400050];
inline void add(int x,int y,double z,int k=0,int ta=0){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;E[tot]=z;tag[tot]=ta;ext[tot]=k;
}
double d[10005][12];
struct N{
	int x,y;double w;
	N(int a=0,int b=0,double c=0){
		x=a,y=b,w=c;
	}
	friend bool operator < (const N&a,const N&b){
		return a.w>b.w;
	}
}t;
priority_queue<N> q;
void dijkstra(int x,int ta){
	memset(d,0x42,sizeof d);
	d[x][0]=0,q.push(N(x,0,0));
	while(!q.empty()){
		t=q.top();q.pop();
		for(int i=H[t.x];i;i=X[i]){
			if(ta!=tag[i]) continue;
			if(a[P[i]]){
				if(t.y<k){
					double extra;
					if(ta){
						extra=1;
					}else extra=a[P[i]]*1.0*a[P[i]]/2.0/(a[P[i]]+b[P[i]]);
					if(d[P[i]][t.y+1]>d[t.x][t.y]+E[i]+extra){
						d[P[i]][t.y+1]=d[t.x][t.y]+E[i]+extra;
						q.push(N(P[i],t.y+1,d[P[i]][t.y+1]));
					}
				}
			}else{
				if(d[P[i]][t.y]>d[t.x][t.y]+E[i]){
					d[P[i]][t.y]=d[t.x][t.y]+E[i];
					q.push(N(P[i],t.y,d[P[i]][t.y]));
				}
			}
		}
	}
}
void solve(int x){
	dijkstra(x,0);
	for(int i=1;i<=n;i++){
		if(i!=x&&c[i]){
			for(int j=0;j<=k;j++){
				if(d[i][j]<=limit){
					add(x,i,d[i][j],j,1);
				}
			}
		}
	}
}
void Dijkstra(int x=S){
	memset(d,0x42,sizeof d);
	d[x][0]=0,q.push(N(x,0,0));
	while(!q.empty()){
		t=q.top();q.pop();
		for(int i=H[t.x];i;i=X[i]){
			if(tag[i]!=1) continue;
			if(t.y+ext[i]<=k){
				if(d[P[i]][t.y+ext[i]]>d[t.x][t.y]+E[i]+cost){
					d[P[i]][t.y+ext[i]]=d[t.x][t.y]+E[i]+cost;
					q.push(N(P[i],t.y+ext[i],d[P[i]][t.y+ext[i]]));
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>k>>limit>>cost;
	for(int i=1;i<=n;i++){
		cin>>s>>a[i]>>b[i];
		mp[s]=i;
		if(check(s)) c[i]=1;
		if(s=="start") S=i;
		if(s=="end") T=i;
	}
	c[S]=1;
	c[T]=1;
	for(int i=0,x;i<m;i++){
		cin>>s>>s2>>s3>>x;
		add(mp[s],mp[s2],x);
		add(mp[s2],mp[s],x);
	}
	for(int i=1;i<=n;i++){
		if(c[i]==1){
			solve(i);
		}
	}
	Dijkstra();
	double ans=1e100;
	for(int i=0;i<=k;i++){
		ans=min(ans,d[T][i]);
	}
	printf("%.3f\n",ans-cost);
	return 0;
}
