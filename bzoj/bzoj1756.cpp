/*
ID: zrtdrea1
PROG:
LANG: C++
*/
//ÓÀÔ¶×ö×Ô¼º»á×öµÄÌâ¾ÍÓÀÔ¶»¹ÊÇÔ­À´µÄÑù×Ó
#include<cstdio>
#include<algorithm>
//by zrt
//problem:
using namespace std;
const int MAXN=500005;
int lmax[MAXN*3],rmax[MAXN*3],sum[MAXN*3],maxs[MAXN*3];
int a[MAXN],n,m;
int _l,_r,_c;
void mk(int o,int l,int r){
	if(l==r){
		maxs[o]=lmax[o]=rmax[o]=sum[o]=a[l];
		return;
	}else{
		int m=(l+r)>>1;
		mk(o<<1,l,m);
		mk((o<<1)+1,m+1,r);
		sum[o]=sum[o<<1]+sum[(o<<1)+1];
		if(maxs[o<<1]>maxs[(o<<1)+1]){
			maxs[o]=maxs[o<<1];
		}else maxs[o]=maxs[(o<<1)+1];
		if(maxs[o]<rmax[o<<1]+lmax[(o<<1)+1]){
			maxs[o]=rmax[o<<1]+lmax[(o<<1)+1];
		}
		if(lmax[o<<1]>sum[o<<1]+lmax[(o<<1)+1]){
			lmax[o]=lmax[o<<1];
		}else lmax[o]=sum[o<<1]+lmax[(o<<1)+1];
		if(rmax[(o<<1)+1]>sum[(o<<1)+1]+rmax[o<<1]){
			rmax[o]=rmax[(o<<1)+1];
		}else rmax[o]=sum[(o<<1)+1]+rmax[o<<1];
	}
}
int askl(int o,int l,int r){
	if(_r>=r) return lmax[o];
	int m=(l+r)>>1;
	if(_r>m){
		int ans=lmax[o<<1];
		int k=sum[o<<1]+askl((o<<1)+1,m+1,r);
		return max(ans,k);
	}
	else {
		return askl(o<<1,l,m);
	}
}
int askr(int o,int l,int r){
	if(_l<=l) return rmax[o];
	int m=(l+r)>>1;
	if(_l<=m){
		int ans=rmax[(o<<1)+1];
		int k=sum[(o<<1)+1]+askr(o<<1,l,m);
		return max(ans,k);
	}else{
		return askr((o<<1)+1,m+1,r);
	}
}
void ask(int o,int l,int r){
	if(_l<=l&&_r>=r){
		if(maxs[o]>_c) _c=maxs[o];
		return;
	}
	int m=(l+r)>>1;
	if(_l<=m&&_r>m){
		_c=max(_c,askr(o<<1,l,m)+askl((o<<1)+1,m+1,r));
		ask(o<<1,l,m);ask((o<<1)+1,m+1,r);
		return;// max(max(ask(o<<1,l,m),ask((o<<1)+1,m+1,r)),);
	}else{
		if(_l<=m){
			ask(o<<1,l,m);
		}else{
			ask((o<<1)+1,m+1,r);
		}
	}
}
int _pos;
void change(int o,int l,int r){
	int m=(l+r)>>1;
	if(l==r){
		maxs[o]=lmax[o]=rmax[o]=sum[o]=a[l];
	}else{
		if(_pos<=m){
			change(o<<1,l,m);
		}else change((o<<1)+1,m+1,r);
		sum[o]=sum[o<<1]+sum[(o<<1)+1];
		if(maxs[o<<1]>maxs[(o<<1)+1]){
			maxs[o]=maxs[o<<1];
		}else maxs[o]=maxs[(o<<1)+1];
		if(maxs[o]<rmax[o<<1]+lmax[(o<<1)+1]){
			maxs[o]=rmax[o<<1]+lmax[(o<<1)+1];
		}
		if(lmax[o<<1]>sum[o<<1]+lmax[(o<<1)+1]){
			lmax[o]=lmax[o<<1];
		}else lmax[o]=sum[o<<1]+lmax[(o<<1)+1];
		if(rmax[(o<<1)+1]>sum[(o<<1)+1]+rmax[o<<1]){
			rmax[o]=rmax[(o<<1)+1];
		}else rmax[o]=sum[(o<<1)+1]+rmax[o<<1];
	}
}
char c;
int read(){
	while(((c=getchar())<'0'||c>'9')&&c!='-');
	int sign=1;
	int sum=0;
	if(c=='-'){
		c=getchar();
		sign=-1;
	}
	do{
		sum*=10;sum+=c-'0';
	}while((c=getchar())>='0'&&c<='9');
	return sum*sign;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	mk(1,1,n);
	// _c = -10000
	int k,x,y;
	for(int i=0;i<m;i++){
		k=read();x=read();y=read();
	//	scanf("%d%d%d",&k,&x,&y);
		if(k&1){
			if(x>y) swap(x,y);
			_l=x;_r=y;
			_c=-10000;
			ask(1,1,n);
			printf("%d\n",_c);
		}else{
			_pos=x;
			a[x]=y;
			change(1,1,n);
		}
	}
	return 0;
}
