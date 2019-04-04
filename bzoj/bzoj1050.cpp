#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct N{
	int x,y,z;
	friend bool operator < (const N&a,const N&b){
		return a.z<b.z;
	}
}a[5005];
int n,m;
int f[505];
int ansx,ansy;
int get(int x){
	return f[x]==x?x:f[x]=get(f[x]);
}
int s,t;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	scanf("%d%d",&n,&m);
	bool ok=0;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	}
	sort(a,a+m);
	scanf("%d%d",&s,&t);
	for(int i=0;i<m;i++){
		for(int j=1;j<=n;j++) f[j]=j;
		int k=i;
		while(get(s)!=get(t)&&k<m){
			if(get(a[k].x)!=get(a[k].y)){
				f[get(a[k].x)]=get(a[k].y);
			}
			k++;
		}
		k--;
		if(get(s)!=get(t)) continue;
		if(!ok){
	//		printf("$$ %d %d\n",i,k);
	//		printf("## %d %d\n",a[i].z,a[k].z);
			ansx=a[k].z;
			ansy=a[i].z;ok=1;
		}else{
	//		printf("$$ %d %d\n",i,k);
	//		printf("## %d %d\n",a[i].z,a[k].z);
			if(ansx*a[i].z>ansy*a[k].z){
				ansx=a[k].z;
				ansy=a[i].z;
			}
		}
		
	}
	if(!ok){
		puts("IMPOSSIBLE");
	}else{
		int G=gcd(ansx,ansy);
		ansx/=G;
		ansy/=G;
		printf("%d",ansx);
		if(ansy!=1) printf("/%d\n",ansy);else puts("");
	}
	
	
	return 0;
}
