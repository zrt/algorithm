#include<iostream>
#include<cstdio>
#include<queue>
//by zrt
//problem:
using namespace std;
int H[100005],X[200005],P[200005],tot,E[200005];
int in[100005],out[100005];
double F[100005];
inline void add(int x,int y,int z){
	out[x]++;in[y]++;
	P[++tot]=y;E[tot]=z;X[tot]=H[x];H[x]=tot;
}
int n,m,x,y,z,k;
queue<int> q;
double s;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) {
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	F[1]=1.00;
	q.push(1);
	while(!q.empty()){
		k=q.front();q.pop();
		for(int i=H[k];i;i=X[i]){
			in[P[i]]--;
			F[P[i]]+=F[k]/(double) out[k];
			if(!in[P[i]]){
				q.push(P[i]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		F[i]/=(double) out[i];
		for(int j=H[i];j;j=X[j]){
			s+=F[i]*(double)E[j];
		}
	}
	printf("%.2f",s);
	return 0;
}
