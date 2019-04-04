#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
long long gcd(long long a,long long b)
{
	return b==0?a:gcd(b,a%b);
}
long long LCM(long long a,long long b)
{
	return a*b/gcd(a,b);
}
int main()
{
	long long c,hr,hb,wr,wb;
	cin>>c>>hr>>hb>>wr>>wb;
	if(wr<wb)swap(hr,hb),swap(wr,wb);
	long long lcm=LCM(wr,wb);
	if(c<1e7)
	{
		long long ans=0;
		for(int i=0;i*wr<=c;i++)
		ans=max(ans,(c-i*wr)/wb*hb+i*hr);
		cout<<ans<<endl;
	}
	else if(c>5*lcm)
	{
		long long t=c/lcm;t-=4;long long tt=max(lcm/wr*hr,lcm/wb*hb);tt*=t;
		c-=t*lcm;long long ans=0;//cout<<tt<<endl; 
		for(int i=0;i*wr<=c;i++)
		ans=max(ans,(c-i*wr)/wb*hb+i*hr);
		cout<<ans+tt<<endl;
	}
	else
	{
		long long ans=0;
		for(int i=0;i*wr<=c;i++)
		ans=max(ans,(c-i*wr)/wb*hb+i*hr);
		cout<<ans<<endl;
	}
}