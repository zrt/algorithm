#include <cstdio>
#include <cstring>
#include <algorithm>
//  by zrt
//  problem:
//  无论你在什么时候开始，重要的是开始以后就不要停止。
using namespace std ;
typedef long long LL ;
const double eps(1e-10) ;
const int inf(0x3f3f3f3f) ;
int n;
int si[1005],ti[1005],di[1005];
//<<1 begin <<1|1 end
bool instk[1005];
int H[2040],X[4000000],P[4000000],tot;
inline void add(int x,int y){
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
bool mark[2050];

int stk[2005],top;
/*void tarjan(int x){
	int dfn=low[x]=++tim;
	instk[x]=1;stk[top++]=x;
	for(int i=H[x];i;i=X[i]){
		if(!low[P[i]]){
			tarjan(P[i]);
			low[x]=min(low[x],low[P[i]]);
		}else if(instk[P[i]]) low[x]=min(low[x],low[P[i]]);
	}
	if(low[x]>=dfn){
		int k;
		cnt++;
		do{
			k=stk[--top];
			instk[k]=0;
			belong[k]=cnt;
		}while(k!=x);
	}
}
*/
bool dfs(int x){
	if(mark[x^1]) return 0;
	if(mark[x]) return 1;
	mark[x]=1;
	stk[top++]=x;
	for(int i=H[x];i;i=X[i]){
		if(!dfs(P[i])) return 0;
	}
	return 1;
}
bool solve(){
	for(int i=0;i<n<<1;i+=2){
		if(!mark[i]&&!mark[i^1]){
			top=0;
			if(!dfs(i)){
				while(top>0) mark[stk[--top]]=0;
				if(!dfs(i^1)) return 0;
			}
		}
	}
	return 1;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
	scanf("%d",&n);
	for(int i=0,a,b,c,d;i<n;i++){
		scanf("%d:%d%d:%d%d",&a,&b,&c,&d,&di[i]);
		si[i]=a*60+b;
		ti[i]=c*60+d;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			//both first
			//si[i]-- si[i]+di[i] ; si[j]--si[j]+di[j];
			if((si[i]>=si[j]&&si[i]<si[j]+di[j])||(si[j]>=si[i]&&si[j]<si[i]+di[i])){
				add(i<<1,j<<1|1);
				add(j<<1,i<<1|1);
			}
			//ti[i]-di[i] -- ti[i] ; ti[j]-di[j] --ti[j] 
			if((ti[i]-di[i]>=ti[j]-di[j]&&ti[i]-di[i]<ti[j])||(ti[j]-di[j]>=ti[i]-di[i]&&ti[j]-di[j]<ti[i])){
				add(i<<1|1,j<<1);
				add(j<<1|1,i<<1);
			}
			//si[i]-- si[i]+di[i] ;  ti[j]-di[j] --ti[j] 
			if((si[i]>=ti[j]-di[j]&&si[i]<ti[j])||(ti[j]-di[j]>=si[i]&&ti[j]-di[j]<si[i]+di[i])){
				add(i<<1,j<<1);
				add(j<<1|1,i<<1|1);
			}
			//ti[i]-di[i] -- ti[i] ;si[j]--si[j]+di[j];
			if((ti[i]-di[i]>=si[j]&&ti[i]-di[i]<si[j]+di[j])||(si[j]>=ti[i]-di[i]&&si[j]<ti[i])){
				add(i<<1|1,j<<1|1);
				add(j<<1,i<<1);
			}
		}
	}
	if(!solve()) puts("NO");
	else{
		puts("YES");
		for(int i=0;i<n;i++){
			if(mark[i<<1]){
				printf("%02d:%02d %02d:%02d\n",si[i]/60,si[i]%60,(si[i]+di[i])/60,(si[i]+di[i])%60);
			}else{
				printf("%02d:%02d %02d:%02d\n",(ti[i]-di[i])/60,(ti[i]-di[i])%60,ti[i]/60,ti[i]%60);
			}
		}
	}
	return 0 ;
}
