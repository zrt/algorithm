#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,m;
int a[10005],b[10005],c[10005],cnt;
int H[10005],X[10005],P[10005],tot;
int d[10005];
inline void add(int x,int y){
//	printf("%d %d\n",x,y);
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
int link[10005];
bool vis[10005];
bool dfs(int x){
	for(int i=H[x];i;i=X[i]){
		if(!vis[P[i]]){
			vis[P[i]]=1;
			if(!link[P[i]]||dfs(link[P[i]])){
				link[P[i]]=x;
				return 1;
			}
		}
	}
	return 0;
}
vector<int> v[55][105],v2[55][105];
bool del[10005];
int count(int x){
	int ret=0;
	while(x){
		x&=(x-1);
		ret++;
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	while(~scanf("%d%d%d",&a[cnt],&b[cnt],&c[cnt])){
		c[cnt]--,
		d[c[cnt]]=max(d[c[cnt]],a[cnt]),
		d[(c[cnt]+1)%n]=max(d[(c[cnt]+1)%n],b[cnt]),
		v[c[cnt]][a[cnt]].push_back(b[cnt]),
		v2[(c[cnt]+1)%n][b[cnt]].push_back(a[cnt]),
		cnt++;
	}
	for(int i=0;i<n;i++) m+=d[i];
	int ans=0;
	if(n&1){
		int pos=-1;
		int mn=m;
		for(int i=0;i<n;i++){
			if(d[i]<mn){
				mn=d[i];
				pos=i;
			}
		}
		memset(del,0,sizeof del);
		for(int i=(1<<d[pos])-1;i>=0;i--){
		//	puts("START");
			tot=0;
			for(int j=0;j<n;j++) for(int k=1;k<=d[j];k++) H[j*100+k]=0,link[j*100+k]=0;
			for(int j=1;j<=d[pos];j++){
				if(i&(1<<(j-1))){
					for(int k=0;k<v[pos][j].size();k++){
						del[(pos+1)%n*100+v[pos][j][k]]=1;
			//			printf("# %d\n",(pos+1)%n*100+v[pos][j][k]);
					}
					for(int k=0;k<v2[pos][j].size();k++){
			//			puts("AAAAAAAAaa");
						del[(pos-1+n)%n*100+v2[pos][j][k]]=1;
			//			printf("# %d\n",(pos-1+n)%n*100+v2[pos][j][k]);
					}
				}
			}
			for(int j=0;j<pos;j++){
				if(j&1){
					for(int k=1;k<=d[j];k++){
						if(del[j*100+k]) continue;
						if(j+1!=pos)
						for(int p=0;p<v[j][k].size();p++){
							if(!del[(j+1)%n*100+v[j][k][p]])
							add(j*100+k,(j+1)%n*100+v[j][k][p]);
						}
						if((j-1+n)%n!=pos)
						for(int p=0;p<v2[j][k].size();p++){
							if(!del[(j-1+n)%n*100+v2[j][k][p]])
							add(j*100+k,(j-1+n)%n*100+v2[j][k][p]);
						}
					}
				}
			}
			for(int j=pos+1;j<n;j++){
				if(!(j&1)){
					for(int k=1;k<=d[j];k++){
                        if(del[j*100+k]) continue;
						if((j+1)%n!=pos)
						for(int p=0;p<v[j][k].size();p++){
                            if(!del[(j+1)%n*100+v[j][k][p]])
							add(j*100+k,(j+1)%n*100+v[j][k][p]);
						}
						if(j-1!=pos)
						for(int p=0;p<v2[j][k].size();p++){
                            if(!del[(j-1+n)%n*100+v2[j][k][p]])
							add(j*100+k,(j-1+n)%n*100+v2[j][k][p]);
						}
					}
				}
			}
			int kk=m-d[pos]+count(i);
			for(int i=0;i<n;i++){
				for(int j=1;j<=d[i];j++){
					if(del[i*100+j]) kk--;
				}
			}
	//		printf("# %d\n",kk);
			for(int j=0;j<pos;j++){
				if(j&1){
					for(int k=1;k<=d[j];k++){
						memset(vis,0,sizeof vis);
						if(dfs(j*100+k)) kk--;
					}
				}
			}
			for(int j=pos+1;j<n;j++){
				if(!(j&1)){
					for(int k=1;k<=d[j];k++){
						memset(vis,0,sizeof vis);
						if(dfs(j*100+k)) kk--;
					}
				}
			}
	//		printf("# %d\n",kk);
			ans=max(ans,kk);
 			for(int j=1;j<=d[pos];j++){
				if(i&(1<<(j-1))){
					for(int k=0;k<v[pos][j].size();k++){
						del[(pos+1)%n*100+v[pos][j][k]]=0;
					}
					for(int k=0;k<v2[pos][j].size();k++){
						del[(pos-1+n)%n*100+v2[pos][j][k]]=0;

					}
				}
			}
		}
		printf("%d\n",ans);
	}else{
		ans=m;
		for(int i=0;i<cnt;i++){
			if(c[i]&1){
				add(a[i]+c[i]*100,b[i]+(c[i]+1)%n*100);
			}else{
				add(b[i]+(c[i]+1)%n*100,a[i]+c[i]*100);
			}
		}
	//	printf("#%d\n",ans);
		for(int i=0;i<n;i++){
			if(i&1)
			for(int j=1;j<=d[i];j++){
				memset(vis,0,sizeof vis);
				if(dfs(i*100+j)) ans--;
			}
		}
		
		printf("%d\n",ans);
	}
//	while(1);
	return 0;
}
