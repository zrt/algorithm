#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
int n,k,s;int aa[100005][26],bb[100005][26];int a[100005],b[100005];
bool cmp(int j,int i,int c1,int c2){//b 0...j | a i-j..i
	int sum1=0,sum2=0;
	for(int k=1;k<c1;k++){
		sum1+=j?bb[j-1][k]:0;
	}
	for(int k=1;k<c2;k++){
		sum2+=(i?aa[i-1][k]:0)-((i-j)?aa[i-j-1][k]:0);
	}
	return sum1==sum2&&(j?bb[j-1][c1]:0)==((i?aa[i-1][c2]:0)-((i-j)?aa[i-j-1][c2]:0));
}
bool cmpp(int j,int i,int c1,int c2){//b 0...j |b i-j..i
	int sum1=0,sum2=0;
	for(int k=1;k<c1;k++){
		sum1+=j?bb[j-1][k]:0;
	}
	for(int k=1;k<c2;k++){
		sum2+=(i?bb[i-1][k]:0)-((i-j)?bb[i-j-1][k]:0);
	}
	return sum1==sum2&&(j?bb[j-1][c1]:0)==((i?bb[i-1][c2]:0)-((i-j)?bb[i-j-1][c2]:0));
}
int nxt[100005];

void mk_pre(){
	for(int i=0;i<n;i++) {
		if(i)for(int j=1;j<=s;j++) aa[i][j]=aa[i-1][j];
		aa[i][a[i]]++;
	}
	for(int i=0;i<k;i++) {
		if(i)for(int j=1;j<=s;j++) bb[i][j]=bb[i-1][j];
		bb[i][b[i]]++;
	}
}
void mk(){
	int j=-1;
	nxt[0]=-1;
	for(int i=1;i<k;i++){
		while(~j&&!cmpp(j+1,i,b[j+1],b[i])) j=nxt[j];
		if(cmpp(j+1,i,b[j+1],b[i])) j++;
		nxt[i]=j;
	}
}

int ans[100005],top;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d%d%d",&n,&k,&s);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<k;i++){
		scanf("%d",&b[i]);
	}
	mk_pre();// qianzhuihe
	mk();
	int j=-1;
	for(int i=0;i<n;i++){
		while(~j&&!cmp(j+1,i,b[j+1],a[i])) j=nxt[j];
		if(cmp(j+1,i,b[j+1],a[i])) j++;
		if(j==k-1){
			ans[top++]=i-j+1;
			j=nxt[j];
		}
	}
	printf("%d\n",top);
	for(int i=0;i<top;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}
