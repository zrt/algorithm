#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,m;
int H[10005],X[2000005],P[2000005],tot;
bool del[10005];
int seq[10005];
vector<int> v[10005];
int best;
int label[10005];
void MCS(){
	for(int i=1;i<=n;i++) v[0].push_back(i);
	int best=0;
	for(int i=n;i>=1;i--){
		int x;
		while(1){
			bool ok=0;
			while(v[best].size()){
				if(!del[v[best].back()]){
					ok=1;break;
				}else v[best].erase(v[best].end()-1);
			}
			if(ok){
				x=v[best].back();
				seq[i]=x;
				del[x]=1;
				for(int i=H[x];i;i=X[i]){
					if(!del[P[i]]){
						label[P[i]]++;
						v[label[P[i]]].push_back(P[i]);
						best=max(best,label[P[i]]);
					}
				}
				break;
			}else{
				best--;
			}
		}
	}
}
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int tag[10005];
int mark[10005];
int ans;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	MCS();
	for(int i=n;i>=1;i--){
		int x=seq[i];
		for(int j=H[x];j;j=X[j]){
			mark[tag[P[j]]]=i;
		}
		int j=1;
		while(mark[j]==i) j++;
		tag[x]=j;
		ans=max(ans,j);
	}
	printf("%d\n",ans);
	return 0;
}
