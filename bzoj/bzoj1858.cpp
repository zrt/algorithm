#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int sum[400000][2],lmx[400000][2],rmx[400000][2],mx[400000][2];
int set[400000];
bool rev[400000];
int a[400000];
void up(int o,int l,int r){
	int mid=(l+r)>>1;
	for(int k=0;k<2;k++){
		if(lmx[o<<1][k]==mid-l+1) lmx[o][k]=lmx[o<<1][k]+lmx[o<<1|1][k];
		else lmx[o][k]=lmx[o<<1][k];
		if(rmx[o<<1|1][k]==r-mid) rmx[o][k]=rmx[o<<1|1][k]+rmx[o<<1][k];
		else rmx[o][k]=rmx[o<<1|1][k];
		mx[o][k]=max(lmx[o<<1|1][k]+rmx[o<<1][k],max(mx[o<<1][k],mx[o<<1|1][k]));
		sum[o][k]=sum[o<<1][k]+sum[o<<1|1][k];
	}
}
void bd(int o,int l,int r){
	set[o]=-1;
	if(l==r){
		sum[o][a[l]]=1;lmx[o][a[l]]=rmx[o][a[l]]=1;mx[o][a[l]]=1;
	}else{
		int mid=(l+r)>>1;
		bd(o<<1,l,mid);
		bd(o<<1|1,mid+1,r);
		up(o,l,r);
	}
}
void do_set(int o,int l,int r,int k){
	lmx[o][k]=rmx[o][k]=mx[o][k]=sum[o][k]=r-l+1;
	lmx[o][k^1]=rmx[o][k^1]=mx[o][k^1]=sum[o][k^1]=0;
	set[o]=k;
}
void do_rev(int o){
	rev[o]^=1;
	swap(lmx[o][0],lmx[o][1]);
	swap(rmx[o][0],rmx[o][1]);
	swap(mx[o][0],mx[o][1]);
	swap(sum[o][0],sum[o][1]);
	if(set[o]!=-1) set[o]^=1;
}

void down(int o,int l,int r){
	if(set[o]!=-1){
		rev[o]=0;
		int mid=(l+r)>>1;
		do_set(o<<1,l,mid,set[o]);
		do_set(o<<1|1,mid+1,r,set[o]);
		set[o]=-1;
	}
	if(rev[o]){
		do_rev(o<<1),do_rev(o<<1|1);
		rev[o]=0;
	}
}
void Set(int o,int l,int r,int L,int R,int k){
	if(l==L&&r==R){
		do_set(o,l,r,k);
	}else{
		int mid=(l+r)>>1;
		down(o,l,r);
		if(R<=mid) Set(o<<1,l,mid,L,R,k);
		else if(L>mid) Set(o<<1|1,mid+1,r,L,R,k);
		else Set(o<<1,l,mid,L,mid,k),Set(o<<1|1,mid+1,r,mid+1,R,k);
		up(o,l,r);
	}
}
void Rev(int o,int l,int r,int L,int R){
	//printf("R %d %d %d %d %d\n",o,l,r,L,R);
	if(l==L&&r==R){
		do_rev(o);
	}else{
		int mid=(l+r)>>1;
		down(o,l,r);
		if(R<=mid) Rev(o<<1,l,mid,L,R);
		else if(L>mid) Rev(o<<1|1,mid+1,r,L,R);
		else Rev(o<<1,l,mid,L,mid),Rev(o<<1|1,mid+1,r,mid+1,R);
		up(o,l,r);
	}
}
int Sum(int o,int l,int r,int L,int R,int k){
	//printf("S %d %d %d %d %d\n",o,l,r,L,R);
	if(l==L&&r==R){
		return sum[o][k];
	}else{
		down(o,l,r);
		int mid=(l+r)>>1;
		if(R<=mid) return Sum(o<<1,l,mid,L,R,k);
		else if(L>mid) return Sum(o<<1|1,mid+1,r,L,R,k);
		else return Sum(o<<1,l,mid,L,mid,k)+Sum(o<<1|1,mid+1,r,mid+1,R,k);
	}
}
int Mx(int o,int l,int r,int L,int R){
	if(l==L&&r==R){
		return mx[o][1];
	}else{
		down(o,l,r);
		int mid=(l+r)>>1;
		if(R<=mid) return Mx(o<<1,l,mid,L,R);
		else if(L>mid) return Mx(o<<1|1,mid+1,r,L,R);
		else{
			return max(max(Mx(o<<1,l,mid,L,mid),Mx(o<<1|1,mid+1,r,mid+1,R)),min(mid-L+1,rmx[o<<1][1])+min(R-mid,lmx[o<<1|1][1]));
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	bd(1,1,n);
	for(int i=0,t,x,y;i<m;i++){
		scanf("%d%d%d",&t,&x,&y);
		x++;y++;
		if(t==0){
			Set(1,1,n,x,y,0);
		}else if(t==1){
			Set(1,1,n,x,y,1);
		}else if(t==2){
			Rev(1,1,n,x,y);
		}else if(t==3){
			printf("%d\n",Sum(1,1,n,x,y,1));
		}else if(t==4){
			printf("%d\n",Mx(1,1,n,x,y));
		}
	}
	
	
	return 0;
}
