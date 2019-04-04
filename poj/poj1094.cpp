#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
//by zrt
//problem:
using namespace std;
bool r[30][30];
int n,m;
vector<int> v[30];
int in[30],inn[30];
char s[10];
int q[30],h,t;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%s",s)==1){
		if(s[1]=='<') continue;
		else sscanf(s,"%d",&n);
		scanf("%d",&m);
		if(n==0) break;
		memset(r,0,sizeof r);
		memset(in,0,sizeof in);
		for(int i=0;i<=n;i++) v[i].clear();
		for(int i=1;i<=m;i++){
			scanf("%s",s);
			r[s[0]-'A'][s[2]-'A']=1;
			in[s[2]-'A']++;
			v[s[0]-'A'].push_back(s[2]-'A');
			for(int k=0;k<n;k++){
				for(int i=0;i<n;i++){
					for(int j=0;j<n;j++){
						if(r[i][k]&&r[k][j]&&(!r[i][j])) r[i][j]=1;
					}
				}
			}
			for(int i=0;i<n;i++){
				if(r[i][i]) goto fal;
			}
			if(0){
			fal:;	printf("Inconsistency found after %d relations.\n",i);
			goto ed;
			}
			if(i>=n-1){
				for(int i=0;i<n;i++){
					inn[i]=in[i];
				}
				h=t=0;
				for(int i=0;i<n;i++){
					if(!inn[i]){
						q[t++]=i;
					}
				}
				while(h!=t){
					if(t>h+1){
						goto bk;
					}
					for(int i=0;i<v[q[h]].size();i++){
						inn[v[q[h]][i]]--;
						if(!inn[v[q[h]][i]]){
							q[t++]=v[q[h]][i];
						}
					}
					h++;
				}
				if(t==n){
					printf("Sorted sequence determined after %d relations: ",i);
					for(int i=0;i<n;i++){
						putchar('A'+q[i]);
					}
					putchar('.');
					putchar('\n');
					goto ed;
				}
				bk:;
			}
			
		}
		
		if(1){
			F:; puts("Sorted sequence cannot be determined.");
		}
		ed:;
	}
	
	return 0;
}
