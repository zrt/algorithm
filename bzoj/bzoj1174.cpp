#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int n;
int H[1000003],X[8000000],num[8000000];
unsigned long long P[8000000];
int tot;
char s[20005];
long long ans;
void add(int x,unsigned long long y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;num[tot]=1;
}
const int SIZE=1000003;
inline void insert(unsigned long long has,int l){
	bool ok=0;
	int p=has%SIZE;
	for(int i=H[p];i;i=X[i]){
		if(P[i]==has){
			ok=1;
			num[i]++;
			ans=max(ans,num[i]*1LL*(l+1));
		}
	}
	if(!ok){
		add(p,has);
		ans=max(ans,l+1LL);
	}
}
int main(){
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++){
		gets(s);
		unsigned long long h=0;
		for(int j=0;s[j];j++){
			h=h*13331+s[j];
			insert(h,j);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
/*
7
Jora de Sus
Orhei
Jora de Mijloc
Joreni
Jora de Jos
Japca
Orheiul Vechi
*/
