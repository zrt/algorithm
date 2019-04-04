#include <cstdio>
using namespace std;

struct Trie {
	Trie *ch[2];
	int size;
	Trie(): size(0) {
		ch[0]=ch[1]=0;
	}
	void insert(const char *str)
	{
		++size;
		if(!str[0]) return;
		if(!ch[str[0]-'0']) ch[str[0]-'0']=new Trie();
		ch[str[0]-'0']->insert(str+1);
	}
	void dfs(bool isroot)
	{
		if(size<=1) return;
		if(!isroot) printf("%d\n", size);
		if(ch[0]) ch[0]->dfs(false);
		if(ch[1]) ch[1]->dfs(false);
	}
} root;

const int maxn=3000+5;
//int n;
char str[maxn];

int main()
{
	scanf("%*d%s", str);
	for(int i=0; str[i]; ++i) root.insert(str+i);
	root.dfs(true);
	return 0;
}

