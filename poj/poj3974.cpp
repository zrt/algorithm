#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[1000005],str[3000000];int l,ans,mx,idx,id[3000000];
int main(){
	int kase=1;
	while(scanf("%s",s+1)&&s[1]!='E'){
		s[0]=' ';
		ans=0;
		l=strlen(s);
		for(int i=1;i<l;i++){
			str[i<<1]=s[i];str[i<<1|1]='#';
		}
		str[1]='#';
		str[0]='*';
		idx=0;mx=0;
		l<<=1;
		for(int i=1;i<l;i++){
			if(i<mx){
				id[i]=min(id[idx-(i-idx)],mx-i);
			}else id[i]=1;
			while(1){
				if(str[i+id[i]]==str[i-id[i]]){
					id[i]++;
					ans=max(ans,id[i]);
					if(i+id[i]>mx){
						mx=i+id[i];
						idx=i;
					}
				}else break;
			}
		}
		printf("Case %d: %d\n",kase++,ans-1);
	}
	
	
	
	return 0;
}