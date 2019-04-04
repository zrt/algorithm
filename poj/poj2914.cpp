#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
//  by zrt
//  problem:
#define maxn 505
#define inf 0x3f3f3f3f
int n, m;
int map[maxn][maxn];
bool combine[maxn];
int s,e;
bool vis[maxn];
int w[maxn];
int mincut;
void search(){
    memset(vis, 0, sizeof(vis));
    memset(w, 0, sizeof(w));
    while (true){
        int temp = -inf;
        int x = -1;
        for (int i = 0; i < n; i++)
            if (!combine[i] && !vis[i] && w[i] > temp)
            {
                temp = w[i];
                x = i;
            }
        if (x == -1)
            return;
        s = e;
        e = x;
        mincut = temp;
        vis[x] = true;
        for (int i = 0; i < n; i++)
            if (!combine[i] && !vis[i])
                w[i] += map[x][i];
    }
}

int stoer_wagner(){
    int ret = inf;
    for (int i = 0; i < n - 1; i++){
        search();
        ret = min(ret, mincut);
        combine[e] = true;
        for(int j = 0; j < n; j++)
            if (!combine[j]){
                map[s][j]+=map[e][j];
                map[j][s]+=map[j][e];
            }
    }
    return ret;
}

int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w",stdout) ;
	#endif
    while(~scanf("%d%d",&n,&m)){
        memset(map,0, sizeof(map));
        for (int i=0; i<m; i++){
	        int a, b, c;
	        scanf("%d%d%d",&a,&b,&c);
	        map[a][b]+=c;
	        map[b][a]+=c;
	    }
        memset(combine,0,sizeof(combine));
        printf("%d\n", stoer_wagner());
    }
    return 0;
}