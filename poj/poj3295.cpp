#include<iostream>
#include<cstdio>
#include<string>
//by zrt
//problem:
using namespace std;
int now,p,q,r,s,t;
string S;
bool dfs(){
	now++;
	switch(S[now]){
		case 'p':return p;
		case 'q':return q;
		case 'r':return r;
		case 's':return s;
		case 't':return t;
		case 'K':return dfs()&dfs();
		case 'A':return dfs()|dfs();
		case 'N':return !dfs();
		case 'C':return !dfs()|dfs();
		case 'E':return dfs()==dfs();
		default : return false;
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(cin>>S&&S[0]!='0'){
		bool ok=1;
		for(p=0;p<2;p++){
			for(q=0;q<2;q++){
				for(r=0;r<2;r++){
					for(t=0;t<2;t++)
					for(s=0;s<2;s++){
						now=-1;
						if(!dfs()){
							ok=0;
							goto end;
						}
					}
				}
			}
		}
		end:;
		if(ok){
			puts("tautology");
		}else{
			puts("not");
		}
	}
	
	return 0;
}