#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int trie[200050][26];
int end[200050];
char s[25];
int n,m,tot;
int list[2000500],t;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		int id=0;
		for(int j=0;s[j];j++){
			if(trie[id][s[j]-'a']){
				id=trie[id][s[j]-'a'];
			}else id=trie[id][s[j]-'a']=++tot;
		}
		end[id]=i;
	}
	for(int i=0;i<m;i++){
		scanf("%s",s);
		int id=0;
		bool ok=1;
		for(int j=0;s[j];j++){
			if(trie[id][s[j]-'a']){
				id=trie[id][s[j]-'a'];
			}else {
				ok=0;
				break;
			}
		}
		if(!end[id]) ok=0;
		if(ok){
			puts("-1");
			continue;
		}
		t=0;
		for(int p=0;s[p];p++){
			id=0;ok=1;
			for(int j=0;s[j];j++){
				if(p==j) continue;
				if(trie[id][s[j]-'a']){
					id=trie[id][s[j]-'a'];
				}else {
					ok=0;
					break;
				}
			}
			if(!end[id]) ok=0;
			if(ok){
				list[t++]=end[id];
			}
		}
		for(int h=0;h<26;h++){
			for(int p=0;s[p];p++){
				id=0;ok=1;
				for(int j=0;s[j];j++){
					if(p==j){
						if(trie[id][h]){
							id=trie[id][h];
						}else {
							ok=0;
							break;
						}
						continue;
					}
					if(trie[id][s[j]-'a']){
						id=trie[id][s[j]-'a'];
					}else {
						ok=0;
						break;
					}
				}
				if(!end[id]) ok=0;
				if(ok){
					list[t++]=end[id];
				}
			}
			for(int p=0;s[p];p++){
				id=0;ok=1;
				for(int j=0;s[j];j++){
					if(p==j){
						if(trie[id][h]){
							id=trie[id][h];
						}else {
							ok=0;
							break;
						}
					}
					if(trie[id][s[j]-'a']){
						id=trie[id][s[j]-'a'];
					}else {
						ok=0;
						break;
					}
				}
				if(!end[id]) ok=0;
				if(ok){
					list[t++]=end[id];
				}
			}
		}
		id=0;ok=1;
		for(int j=0;s[j];j++){
			if(trie[id][s[j]-'a']){
				id=trie[id][s[j]-'a'];
			}else {
				ok=0;
				break;
			}
		}
		if(ok){
			for(int i=0;i<26;i++){
				if(trie[id][i]&&end[trie[id][i]]) list[t++]=end[trie[id][i]];
			}
			
		}
		sort(list,list+t);
		t=unique(list,list+t)-list;
		printf("%d\n",t);
	}
	return 0;
}
