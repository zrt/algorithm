#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
//by zrt

using namespace std;
typedef long long LL;
LL gcd(LL a,LL b){
	return b?gcd(b,a%b):a;
}
void sort(LL&x,LL&y,LL&z){
	if(x>y) swap(x,y);
	if(x>z) swap(x,z);
	if(y>z) swap(y,z);
}
LL a,b,c,x,y,z;
LL g1,g2;
LL X[2][100005];
LL Y[2][100005];
int sum[2][100005];
int cnt[2];
void calc(LL&x,LL&y,LL&z,int k){
	while(y-x!=z-y){
		cnt[k]++;
		X[k][cnt[k]]=y-x;
		Y[k][cnt[k]]=z-y;
		if(y-x>z-y){
			int a=(y-x)%(z-y);
			int b=(y-x)/(z-y);
			if(!a) a=z-y,b--;
			z=x+a+(z-y);
			y=x+a;
			sum[k][cnt[k]]=sum[k][cnt[k]-1]+b;
		}else{
			int a=(z-y)%(y-x);
			int b=(z-y)/(y-x);
			if(!a) a=y-x,b--;
			x=z-a-(y-x);
			y=z-a;
			sum[k][cnt[k]]=sum[k][cnt[k]-1]+b;
		}
	}
}
int main(){

//	freopen("hop.in","r",stdin);
//	freopen("hop.out","w",stdout);

	cin>>a>>b>>c>>x>>y>>z;
	sort(a,b,c);
	sort(x,y,z);
	LL a1=a,b1=b,c1=c;
	LL x1=x,y1=y,z1=z;
	calc(a1,b1,c1,0);
	calc(x1,y1,z1,1);
	if(a1==x1&&b1==y1&&c1==z1){
		puts("YES");
		int k=0;
		while(k<cnt[0]&&k<cnt[1]&&X[0][cnt[0]-k]==X[1][cnt[1]-k]&&Y[0][cnt[0]-k]==Y[1][cnt[1]-k]) k++;
		int ans=sum[0][cnt[0]-k-1]+sum[1][cnt[1]-k-1];
		if(k!=cnt[0]&&k!=cnt[1]){
			if(X[0][cnt[0]-k]==X[1][cnt[1]-k]){
				ans+=abs(Y[0][cnt[0]-k]-Y[1][cnt[1]-k])/X[0][cnt[0]-k];
			}else if(Y[0][cnt[0]-k]==Y[1][cnt[1]-k]){
				ans+=abs(X[0][cnt[0]-k]-X[1][cnt[1]-k])/Y[0][cnt[0]-k];
			}else{
				ans=sum[0][cnt[0]-k]+sum[1][cnt[1]-k];
			}
		}else{
			ans=sum[0][cnt[0]-k]+sum[1][cnt[1]-k];
		}
		printf("%d\n",ans);
	}else puts("NO");
	return 0;
}
