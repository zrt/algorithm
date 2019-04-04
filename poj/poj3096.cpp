/*
ID: zrtdrea1
PROG:
LANG: C++
*/
#include<cstdio>
#include<cstring>
#include<set>
//by zrt
//problem:
using namespace std;
char s[100];
int l;
struct N{
	char x,y;
	N(char a='0',char b='0'){
		x=a,y=b;
	}
	friend bool operator <(N a,N b){
		if(a.x!=b.x) return a.x<b.x;
		return a.y<b.y;
	}
};
set<N> m;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%s",s)&&s[0]!='*'){
		l=strlen(s);
		if(l<=2){
			printf("%s is surprising.\n",s);
			continue;
		}
		for(int i=0;i<=l-2;i++){
			m.clear();
			for(int j=0;j<l-i;j++){
				if(m.find(N(s[j],s[j+i+1]))!=m.end()){
					printf("%s is NOT surprising.\n",s);
					goto end;
				}
				m.insert(N(s[j],s[j+i+1]));
			}
		}
		printf("%s is surprising.\n",s);
		end:;
	}
	
	return 0;
}
