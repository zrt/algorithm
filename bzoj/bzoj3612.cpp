#include <cstring>
#include <iostream>
#include <cstdio>
#define MAXN 111
#define MAXK 15
#define MAXNN 1111111

using namespace std;

int nQ, n, k, p;
int a[MAXN * 2][MAXK][MAXK * MAXN * 2];
int g[MAXK * MAXK];
int f[MAXNN];

int calc(int n, int k, int p)
{
    memset(g, 0, sizeof(g));
    g[0] = -1;
    for (int i = 1; i <= k; i++)
        for (int j = i * i; j >= 0; j--)
            g[j + i] -= (g[j] = -g[j]);
    for (int i = 0, j = k * (k + 1) / 2; i < j; i++, j--)
        swap(g[i], g[j]); 
    int m = (k + 1) * (k + 2) / 2, id;
    memset(a, 0, sizeof(a));
    a[0][0][m * k] = a[0][1][m * k] = 1;
    for (int l = 1; l <= 2 * m; l++)
    {
        id = (l + 1) / 2;
        if (l % 2 == 0) id = -id;
        id += m + 1;
        for (int i = 0; i <= k; i++)
            for (int j = 0; j <= 2 * m * k; j++)
                if (i > 0 && (j - id + m + 1) >= 0)
                    a[l][i][j] = (a[l - 1][i][j] + a[l - 1][i - 1][j - id + m + 1]) % p;
                else
                    a[l][i][j] = a[l - 1][i][j];
    }
    memset(f, 0, sizeof(f));
    for (int i = 0; i <= m; i++)
        f[i] = a[2 * i][k][m * k];
    for (int i = m + 1; i <= n; i++)
        for (int j = 1; j <= k * (k + 1) / 2; j++)
            f[i] = ((f[i] + f[i - j] * g[j]) % p + p) % p;
    return f[n];
    return 0;
} 

int main()
{

    scanf("%d", &nQ);
    while (nQ--)
    {
        scanf("%d%d%d", &n, &k, &p);

        cout << calc(n, k, p) << endl;
    }
    return 0;
}
