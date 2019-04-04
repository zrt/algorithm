#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int L,cc;
char s[55005];
char tmps[10];
int c[55005];
unsigned long long hash[55005];
unsigned long long pow[55005];
int main(){
//	freopen("data.in","r",stdin);
	pow[0]=1;
	for(int i=1;i<55005;i++) pow[i]=pow[i-1]*131;
	scanf("%s",s+1);
	cc=L=strlen(s+1);//s 1..L 
	for(int i=1;i<=L;i++) {
		c[i]=c[i-1]+1;
	}
	for(int i=1;i<=L;i++){
		hash[i]=hash[i-1]*131+s[i]-'a'+1;
	}
//	add(2,1);
//	printf("%d %d\n",getpos(1),getpos(3));
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%s",tmps);
	///	putchar('#');
	//		for(int i=1;i<=cc;i++){
	//			
	//			printf(" %d",c[i]);
	//			
	//		}
	//		puts("");
		if(tmps[0]=='I'){
			scanf("%s",tmps);
			int pos;
			scanf("%d",&pos);
			if(pos>L){
				s[L+1]=tmps[0];
				hash[L+1]=hash[L]*131+s[L+1]-'a'+1;
			}else{
				for(int i=L;i>=pos;i--) s[i+1]=s[i];
				s[pos]=tmps[0];
				for(int i=pos;i<=L+1;i++) hash[i]=hash[i-1]*131+s[i]-'a'+1;
				int initpos=lower_bound(c+1,c+1+cc,pos)-c;
				for(int i=initpos;i<=cc;i++){
					c[i]++;
				}
			}
			L++;
		}else{
			int x,y;
			scanf("%d%d",&x,&y);
			x=c[x];y=c[y];
			int l=0,r=min(L-x,L-y)+2,mid;
			while(r-l>1){
				mid=(l+r)/2;
				if(hash[x+mid-1]-hash[x-1]*pow[mid]==hash[y+mid-1]-hash[y-1]*pow[mid]) l=mid;
				else r=mid;
			}
			printf("%d\n",l);
		}
	}
	
	
	return 0;
}