#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long int64_t;
// some not by me --zrt
#define inf 0x3fffffffffffffLL // We do not use 0x7fffffffffffffff as inf since it may cause overflow.

struct Edge {
    int v, w;
    Edge *n;
    bool u;
};

struct Vertex {
    Edge *e;
};

Vertex vers[200000];
Edge edges[400000], *lase;
int par[200000];
int64_t parw[200000];
int64_t parf[200000];
int ind[200000];
int oud[200000];
bool ter[200000];
int nv;

inline void addEdge(int s, int e, int w) {
    lase->v = e;
    lase->n = vers[s].e;
    lase->w = w;
    vers[s].e = lase++;
    
    return;
}

void buildTree() {
    static int que[200000];
    static bool vis[200000];
    int l, f = l = 0;
    
    memset(vis, 0, sizeof(vis));
    memset(ind, 0, sizeof(ind));
    memset(oud, 0, sizeof(oud));

    vis[0] = true;
    // Vertex 0 will not be treated in first phase of DP since it has a
    // self loop (Thus it has no topological order.).
    ind[0] = 1; 
    que[l++] = 0;
    while (l != f) {
        int v = que[f++];
        
        for (Edge *e = vers[v].e; e; e = e->n) {
            if (e->u = !vis[e->v]) {
                vis[e->v] = true;
                par[e->v] = v;
                parw[e->v] = e->w;
                ++ind[v]; // For the first phase of DP, graph is reversed.
                ++oud[v]; // For the second phase of DP..
                que[l++] = e->v;
            }
        }
    }
    
    return;
}

int64_t maxFlow() {
    static int64_t dp1[200000], dp2[200000];
    static int que[200000];
    int l, f = l = 0;
    int64_t r = 0;

    for (int i = 0; i != nv; ++i) {
        if (!ind[i]) {
            que[l++] = i;
            dp1[i] = inf; // Will be fixed later.
            ter[i] = true;
        } else {
            ter[i] = false;
            dp1[i] = 0;
        }
    }
    
    while (l != f) {
        int v = que[f++], p = par[v];
        
        dp1[p] += (parf[v] = min(dp1[v], parw[v]));
        if (!--ind[p]) {
            que[l++] = p;
        }
    }
    
    for (int i = 0; i != nv; ++i) {
        if (ter[i]) {
            // dp1[i] should be initialized to 0 by its meaning, 
            // We initialize it to inf just to simplify our
            // first phase of DP. Here, we restore it to 0.
            dp1[i] = 0; 
        }
    }
    
    l = f = 0; // Since our queue is not circular.
    
    if (oud[0] == 1) {
        // Root has only one out degree, in which case a special judge is needed.
        // -- Terminal can absorb a inifinite amount of flow.
        dp2[0] = inf;
    } else {
        dp2[0] = 0;
    }
    que[l++] = 0;
    while (l != f) {
        int v = que[f++];
        
        for (Edge *e = vers[v].e; e; e = e->n) {
            if (e->u) {
                // parw[e->v] is same as (int64_t)e->w. (See function buildTree)
                dp2[e->v] = min(parw[e->v], dp2[v] + dp1[v] - parf[e->v]);
                que[l++] = e->v;
            }
        }
    }
    
    if (oud[0] == 1) {
        // Restore it
        dp2[0] = 0;
    }

    for (int i = 0; i != nv; ++i) {
        r = max(r, dp1[i] + dp2[i]);
    }
    
    return r;
}

void solveProb() {

    scanf("%d", &nv);
    for (int i = 1; i != nv; ++i) {
        int a, b, w;
        
        scanf("%d%d%d", &a, &b, &w);
        --a; --b;
        addEdge(a, b, w);
        addEdge(b, a, w);
    }
    
    buildTree();
    printf("%lld\n", maxFlow());
    
    return;
}

int main() {
    int t;
    
    scanf("%d", &t);
    while (t--) {
        memset(vers, 0, sizeof(vers));
        lase = edges;
        solveProb();
    }
    
    return 0;
}
