#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int a[1000005];
bool vis[1000005];
int q[1000005];//down
int h,t;
int c;
void pop(int pos){
	if(pos==q[h]) h++;
	vis[a[pos]]=0;
	c--;
}
void insert(int pos){
	vis[a[pos]]=1;
	while(h<t&&a[q[t-1]]<=a[pos]) t--;
	q[t++]=pos;
	c++;
}

int ans;
int main(){
//	freopen("in","r",stdin);
//	freopen("out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int j=1;
	for(int i=1;i<=n;i++){
		while(vis[a[i]]) pop(j),j++;
		insert(i);
		if(c==a[q[h]]) ans=max(ans,c);
	}
	while(j<n){
		pop(j);j++;
		if(c==a[q[h]]) ans=max(ans,c);
	}
	printf("%d\n",ans);
	return 0;
}
