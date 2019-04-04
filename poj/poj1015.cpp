//Memory Time 
//388K   16MS 
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int n;  //????
int m;  //????
int dp[21][801];   //dp[j][k]:?j????,??????k??????,????????????
int path[21][801];  //????????????

/*??,??dp[j][k]???????????i*/
bool select(int j,int k,int i,int* v)
{
	while(j>0 && path[j][k]!=i)
	{
		k-=v[ path[j][k] ];
		j--;
	}
	return j?false:true;
}

int main(void)
{
	int time=1;
	while(cin>>n>>m && n)
	{
		/*Initial*/

		int j,k,i;
		int* p=new int[n+1];  //???????
		int* d=new int[n+1];  //???????
		int* s=new int[n+1];  //???????
		int* v=new int[n+1];  //???????
		memset(dp,-1,sizeof(dp));
		memset(path,0,sizeof(path));
		
		/*Input*/

		for(i=1;i<=n;i++)
		{
			cin>>p[i]>>d[i];

			s[i]=p[i]+d[i];
			v[i]=p[i]-d[i];
		}
		int fix=m*20;  //????,??????[-400,400]???[0,800]

		/*DP*/

		dp[0][fix]=0;   //???????,??dp[0][fix]?????dp[0][0]
		for(j=1;j<=m;j++)
			for(k=0;k<=2*fix;k++)
			{
				if(dp[j-1][k]>=0)   //?????,dp[0][fix]?????dp[0][0]
				{
					for(i=1;i<=n;i++)
						if(dp[j][ k+v[i] ] < dp[j-1][k]+s[i])
						{
							if(select(j-1,k,i,v))
							{
								dp[j][ k+v[i] ] = dp[j-1][k]+s[i];
								path[j][ k+v[i] ] = i;
							}
						}
				}
			}


		/*Output*/

		for(k=0;k<=fix;k++)
			if(dp[m][fix-k]>=0 || dp[m][fix+k]>=0)    //????????????????k
				break;

		int div=dp[m][fix-k] > dp[m][fix+k] ? (fix-k):(fix+k);  //?????

		cout<<"Jury #"<<time++<<endl;
		cout<<"Best jury has value ";
		//???? = (???+???+???)/2
		cout<<(dp[m][div]+div-fix)/2<<" for prosecution and value ";
		//???? = (???-???+???)/2
		cout<<(dp[m][div]-div+fix)/2<<" for defence:"<<endl;

		int* id=new int[m];
		for(i=0,j=m,k=div;i<m;i++)
		{
			id[i]=path[j][k];
			k-=v[ id[i] ];
			j--;
		}
		sort(id,id+m);   //?????????
		for(i=0;i<m;i++)
			cout<<' '<<id[i];
		cout<<endl<<endl;

		/*Relax*/

		delete p;
		delete d;
		delete s;
		delete v;
		delete id;
	}
	return 0;
}