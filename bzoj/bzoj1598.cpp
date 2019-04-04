#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int pnum=1005,mnum=100005;
int H[pnum],X[mnum],P[mnum],E[mnum],tot;
int _H[pnum],_X[mnum],_P[mnum],_E[mnum];
inline void add(int x,int y,int z){
	P[++tot]=y;E[tot]=z;X[tot]=H[x];H[x]=tot;
	_P[tot]=x;_E[tot]=z;_X[tot]=_H[y];_H[y]=tot;
}
int n,m,x,y,z,s,t,k;
int d[pnum];
struct N{
	int x,w;
	N(int a=0,int b=0){
		x=a,w=b;
	}
	friend bool operator < (N a,N b){
		return a.w>b.w;
	}
}tmp;
priority_queue<N> q;
struct K{
	int x,w;
	K(int a=0,int b=0){
		x=a,w=b;
	}
	friend bool operator < (K a,K b){
		return a.w+d[a.x]>b.w+d[b.x];
	}
}ttp;
priority_queue<K> kth;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&x,&y,&z);
		if(x<y) swap(x,y); 
		add(x,y,z);
	}
	s=n,t=1;
	if(s==t) k++;////!!!!!!!!!!!!!!!!
	memset(d,0x3f,sizeof d);
	d[t]=0;
	q.push(N(t,0));
	while(!q.empty()){
		tmp=q.top();q.pop();
		for(int i=_H[tmp.x];i;i=_X[i]){
			if(d[_P[i]]>d[tmp.x]+_E[i]){
				d[_P[i]]=d[tmp.x]+_E[i];
				q.push(N(_P[i],d[_P[i]]));
			}
		}
	}
	if(d[s]==0x3f3f3f3f) {
		puts("-1");return 0;
	}
	int cnt=0;
	kth.push(K(s,0));
	while(cnt<k){
		if(kth.empty()){
			break;
		}
		ttp=kth.top();kth.pop();
		if(ttp.x==t) cnt++,printf("%d\n",ttp.w);
		if(cnt>=k) break;
		for(int i=H[ttp.x];i;i=X[i]){
			kth.push(K(P[i],ttp.w+E[i]));
		}
		
	}
	for(int i=cnt;i<k;i++) puts("-1");
	return 0;
}
