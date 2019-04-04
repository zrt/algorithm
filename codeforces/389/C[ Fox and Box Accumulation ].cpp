#include<iostream>
#include<cstdio>
#include<algorithm>
//by zrt
//problem:
using namespace std;
int n,a[100],cnt,tmp,pile[100];//pile  shuliang //ÿ������� 
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	pile[cnt++]++;
	for(int i=1;i<n;i++){
		int maxx=0,opt;
		for(int j=0;j<cnt;j++){
			if(a[i]>=pile[j]){
				if(pile[j]>maxx){
					maxx=pile[j];
					opt=j;
				}
			}
		}
		if(maxx==0){
			pile[cnt++]++;
		}else{
			pile[opt]++;
		}
	}
	printf("%d",cnt);
	return 0;
}

