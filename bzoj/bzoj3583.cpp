#include <cstdio>
#include <vector>
using namespace std;

inline void ERR(const char info[])
{
	printf("error.. %s\n", info);
	throw 123;
}
const int mod=1000000007;

struct Matrix {
	typedef long long NUM;
	int h, w;
	vector<vector<NUM> > mt;
	inline vector<NUM> &operator [](int i) {return mt[i];}
	inline const vector<NUM> &operator [](int i) const {return mt[i];}
	inline void test()
	{
		printf("testing a %d*%d matrix..\n", h, w);
		for(int i=0; i<h; ++i, putchar('\n')) for(int j=0; j<w; ++j) printf(" %I64d", mt[i][j]);
		printf("test complete.\n");
	}
	inline void rebuild()
	{
		//O(n^2)
		mt.clear();
		vector<NUM> v; v.resize(w);
		for(int i=0; i<h; ++i) mt.push_back(v);
	}
	Matrix(int h, int w): h(h), w(w){rebuild();}
	inline Matrix operator * (const Matrix &b) const
	{
		const Matrix &a=*this;
		if(a.w!=b.h) ERR("¾ØÕó³Ë·¨Ôª·Ç·¨");
		Matrix ans(a.h, b.w);
		for(int i=0; i<a.h; ++i) for(int j=0; j<b.w; ++j)
			for(int k=0; k<a.w; ++k) ans[i][j]=(ans[i][j]+a[i][k]*b[k][j])%mod;
		return ans;
	}
	Matrix pow(int k) const
	{
		const Matrix &a=*this;
		if(a.h!=a.w) ERR("¾ØÕóÇóÃÝ·Ç·¨");
		if(!k)
		{
			//Éú³ÉÒ»¸öµ¥Î»¾ØÕó£¬·µ»Ø¡£
			Matrix E(a.h, a.w);
			for(int i=0; i<a.h; ++i) E[i][i]=1;
			return E; 
		}
		Matrix b=a.pow(k>>1);
		if(k&1) return b*b*a;
		else return b*b; 
	}
	inline Matrix operator ^ (int k) const {return pow(k);}
};

int main()
{
	int n, k; scanf("%d%d", &n, &k);
	Matrix A(n+1, k+1), B(k+1, n+1);
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<k; ++j) scanf("%d", &B[j][i]);
		for(int j=0; j<k; ++j) scanf("%d", &A[i][j]);
	}
	A[n][k]=B[k][n]=1;
	int m; scanf("%d", &m);
	while(m--)
	{
		int u, v, d; scanf("%d%d%d", &u, &v, &d);
		Matrix st(1, n+1); st[0][v-1]=1;
/*		long long ans=u==v;
		for(int i=1; i<=d; ++i) ans=(ans+(st*A*((B*A)^(i-1))*B)[0][v-1])%mod;	*/
		A[u-1][k]=1;
//		(A*B).test();
//		A.test(); B.test();
//		printf("%lld\n", ((st*A*((B*A)^(d-1))*B)[0][n])%mod);
		printf("%lld\n", (st*A*((B*A)^d)*B)[0][n]);
		A[u-1][k]=0;
	}
	return 0;
}
