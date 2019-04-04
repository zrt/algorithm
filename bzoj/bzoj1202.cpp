#include<cstdio>
#include<cstring>
#include<algorithm>
int f[105],d[105];
int tt,n,m;
bool ok;
int get(int x){
	if(x==f[x]) return x;
	int root=get(f[x]);
	d[x]+=d[f[x]];
	f[x]=root;
	return root;
}
int main(){
//	freopen("out.txt","w",stdout);
	scanf("%d",&tt);
	while(tt--){
		scanf("%d%d",&n,&m);
		ok=1;
		memset(d,0,sizeof d);
		for(int i=1;i<=n+1;i++) f[i]=i;
		for(int i=0,x,y,z;i<m;i++){
			scanf("%d%d%d",&x,&y,&z);
			if(!ok) continue;
			y++;
			if(get(x)==get(y)){
				if(d[y]-d[x]!=z)ok=0; 
			}else{
				int fa=get(y);
				f[fa]=x;
				d[fa]=z-d[y];
				get(y);
			}
		}
		if(ok) puts("true");
		else puts("false");
	}
	return 0;
}
