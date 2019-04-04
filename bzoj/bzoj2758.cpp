#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
int n,m;
typedef long double ld;
typedef long long LL;

char s[10];
ld now;
struct Point{
	ld x,y;
	Point(ld a=0,ld b=0){
		x=a,y=b;
	}
	void read(){
		double a,b;
		scanf("%lf%lf",&a,&b);
		x=a,y=b;
	}
	friend bool operator < (const Point&a,const Point &b){
		return a.x<b.x;
	}
}tmp[50];
struct Poly{
	int id;ld lft,rgt;
	vector<Point> up,down;
	void read(int x){
		id=x;
		int num;
		scanf("%d",&num);
		for(int i=0;i<num;i++) tmp[i].read();
		ld mn=1e200;
		int pos;
		for(int i=0;i<num;i++) if(tmp[i].x<mn){
			mn=tmp[i].x;
			pos=i;
		}
		lft=mn;
	//	puts("HAHA");
		int last;
		for(int i=pos;tmp[(i+1)%num].x+1e-10>tmp[i%num].x;i++){
			//puts("HEHE");
			last=i;
			if(!up.size()){
				up.push_back(tmp[i%num]);
				continue;
			}else{
				if(fabs(tmp[i%num].x-up[up.size()-1].x)<1e-10){
					up[up.size()-1].y=max(up[up.size()-1].y,tmp[i%num].y);
				}else{
					up.push_back(tmp[i%num]);
				}
			}
		}
		int i=last+1;
		if(!up.size()){
			up.push_back(tmp[i%num]);
		}else{
			if(fabs(tmp[i%num].x-up[up.size()-1].x)<1e-10){
				up[up.size()-1].y=max(up[up.size()-1].y,tmp[i%num].y);
			}else{
				up.push_back(tmp[i%num]);
			}
		}
		//puts("zzz");
	//	printf("%u\n",up.size());
		rgt=up[up.size()-1].x;
		mn=-1e200;
		for(int i=0;i<num;i++) if(tmp[i].x>mn){
			mn=tmp[i].x;
			pos=i;
		}
	//	puts("HEHE");
	//	printf("!! %d\n",id);
	//	printf("%d\n",pos);
		for(int i=pos;tmp[(i+1)%num].x<tmp[i%num].x+1e-10;i++){
		//	printf("d\n",i);
			last=i;
			if(!down.size()){
				down.push_back(tmp[i%num]);
				continue;
			}else{
				if(fabs(tmp[i%num].x-down[down.size()-1].x)<1e-10){
					down[down.size()-1].y=min(down[down.size()-1].y,tmp[i%num].y);
				}else{
					down.push_back(tmp[i%num]);
				}
			}
		}
		i=last+1;
		if(!down.size()){
			down.push_back(tmp[i%num]);
		}else{
			if(fabs(tmp[i%num].x-down[down.size()-1].x)<1e-10){
				down[down.size()-1].y=min(down[down.size()-1].y,tmp[i%num].y);
			}else{
				down.push_back(tmp[i%num]);
			}
		}
		reverse(down.begin(),down.end());
	}
	ld calcup(){//x=now
		Point p(now-1e-8,0);
		int pos=upper_bound(up.begin(),up.end(),p)-up.begin();
		if(pos==0) pos++;
		if(pos>=up.end()-up.begin()) pos--;
		// pos-1 pos now
		return (up[pos].y-up[pos-1].y)*(now-up[pos-1].x)/(up[pos].x-up[pos-1].x)+up[pos-1].y;
	}
	ld calcdown(){//x=now
		Point p(now-1e-8,0);
		int pos=upper_bound(down.begin(),down.end(),p)-down.begin();
	//	printf("# %d\n",pos);
		if(pos==0) pos++;
	//	printf("# %u\n",down.end()-down.begin());
		if(pos>=down.end()-down.begin()) pos--;
	//	printf("@@@ %.2f\n",(double)now);
	//	printf("%.2f %.2f\n",(double)lft,(double)rgt);	
		//	pos-1 pos now
		return (down[pos].y-down[pos-1].y)*(now-down[pos-1].x)/(down[pos].x-down[pos-1].x)+down[pos-1].y-1e-10;
	}
}p[100005];
struct Cir{
	int id;
	Point c;
	ld lft,rgt;
	ld r;
	void read(int x){
		id=x;
		c.read();
		double R;
		scanf("%lf",&R);
		r=R+1e-8;
		lft=c.x-R;
		rgt=c.x+R;
	}
	ld calcup(){//x=now
		ld l=fabs(now-c.x);
		if(l>=r) return c.y;
		return c.y+sqrt(r*r-l*l+1e-8);
	}
	ld calcdown(){//x=now
		ld l=fabs(now-c.x);
		if(l>=r) return c.y;
		return c.y-sqrt(r*r-l*l+1e-8)-1e-10;
	}
}c[100005];
int cnt1,cnt2;
LL w[100005];
int to1[100005],to2[100005];
bool type[100005];
ld calcup(int x){
	if(x<=n){
		if(type[x]) return p[to1[x]].calcup();
		else return c[to2[x]].calcup();
	}else{
		x-=n;
		if(type[x]) return p[to1[x]].calcdown();
		else return c[to2[x]].calcdown();
	}
}
struct N{
	int x;
	friend bool operator < (const N&a,const N&b){
		return calcup(a.x)>calcup(b.x);
	}
	N(int a=0){
		x=a;
	}
};
set<N> st;
int root;
int H[100005],X[100005],P[100005],tot,fa[100005];
inline void add(int x,int y){
	x++;y++;
	P[++tot]=y;X[tot]=H[x];H[x]=tot;
}
struct Cmpp{
	ld x;int id;
	int type;// +1 -1
	friend bool operator < (Cmpp a,Cmpp b){
		if(fabs(a.x-b.x)<1e-8) return a.type>b.type;
		return a.x<b.x;
	}
	Cmpp(ld a=0,int b=0,int c=0){
		x=a,id=b,type=c;
	}
}list[400005];
ld calcnow(Cmpp a){
	if(type[a.id]){
		if(a.type==1){
			return p[to1[a.id]].lft;
		}else{
			return p[to1[a.id]].rgt;
		}
	}else{
		if(a.type==1){
			return c[to2[a.id]].lft;
		}else{
			return c[to2[a.id]].rgt;
		}
	}
}
int num;
Point ask[200005];
int pos[200005];
int cc;
struct Q{
	int type;
	LL x,y;
}q[200005];
LL sum[400005];
int dfn[200005],top[200005],son[200005],siz[200005],tim,dep[200005];
void dfs(int x){
//	printf("#@%d\n",x);
	siz[x]=1;
	int mx=-1;
	dep[x]=dep[fa[x]]+1;
	for(int i=H[x];i;i=X[i]){
		fa[P[i]]=x;
		dfs(P[i]);
		siz[x]+=siz[P[i]];
		if(siz[P[i]]>mx){
			son[x]=P[i];
		}
	}
}
void dfs2(int x){
	if(!top[x]) top[x]=x;
	dfn[x]=++tim;
	if(son[x]) top[son[x]]=top[x],dfs2(son[x]);
	for(int i=H[x];i;i=X[i]){
		if(P[i]!=son[x]) dfs2(P[i]);
	}
}
int where[200005];
void bd(int o,int l,int r){
	if(l==r){
		sum[o]=w[where[l]];
	}else{
		int mid=(l+r)>>1;
		bd(o<<1,l,mid);bd(o<<1|1,mid+1,r);
		sum[o]=sum[o<<1]^sum[o<<1|1];
	}
}
void cg(int o,int l,int r,int pos,LL d){
	if(l==r){
		sum[o]=d;
	}else{
		int mid=(l+r)>>1;
		if(pos<=mid) cg(o<<1,l,mid,pos,d);
		else cg(o<<1|1,mid+1,r,pos,d);
		sum[o]=sum[o<<1]^sum[o<<1|1];
	}
}
LL Ask(int o,int l,int r,int L,int R){
	if(l==L&&r==R){
		return sum[o];
	}else{
		int mid=(l+r)>>1;
		if(R<=mid) return Ask(o<<1,l,mid,L,R);
		else if(L>mid) return Ask(o<<1|1,mid+1,r,L,R);
		else return Ask(o<<1,l,mid,L,mid)^Ask(o<<1|1,mid+1,r,mid+1,R);
	}
}
int main(){
//	freopen("ot.txt","r",stdin);
//	freopen("ot2.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		if(s[0]=='P'){
			++cnt1;
			p[cnt1].read(i);
			type[i]=1;
			to1[i]=cnt1;
		}else{
			++cnt2;
			c[cnt2].read(i);
			to2[i]=cnt2;
		}
		scanf("%lld",&w[i+1]);
	}
//	printf("### %.2f\n",(double)p[1].rgt);
	for(int i=1;i<=m;i++){
		scanf("%s",s);
		if(s[0]=='Q'){
			ask[++cc].read();
			q[i].x=cc;
			ask[++cc].read();
			q[i].y=cc;
		}else{
			q[i].type=1;
			scanf("%lld%lld",&q[i].x,&q[i].y);
		}
	}
//	printf("## %d\n",cnt1);
//	for(int i=1;i<=cnt1;i++) printf("%u %u\n",p[i].up.size(),p[i].down.size());
	for(int i=1;i<=cc;i++) list[num++]=Cmpp(ask[i].x,i,0);
	for(int i=1;i<=cnt1;i++) list[num++]=Cmpp(p[i].lft,p[i].id,1),list[num++]=Cmpp(p[i].rgt,p[i].id,-1);
	for(int i=1;i<=cnt2;i++) list[num++]=Cmpp(c[i].lft,c[i].id,1),list[num++]=Cmpp(c[i].rgt,c[i].id,-1);
	sort(list,list+num);
	for(int i=0;i<num;i++){
		if(!list[i].type){
			now=ask[list[i].id].x;
			if(!st.size()){
				pos[list[i].id]=0;
			}else{
				c[0].c=ask[list[i].id];
				set<N>::iterator it=st.upper_bound(N(0));
				if(it==st.begin()){
					pos[list[i].id]=0;
				}else{
					--it;
					if(it->x>n){
						pos[list[i].id]=fa[it->x-n];
					}else	pos[list[i].id]=it->x;
				}
			}
			continue;
		}
	//	printf("# %d\n",list[i].id);
		if(list[i].type==1){
			now=calcnow(list[i])+1e-10;
		//	printf("tim: %.2f\n",(double)now);
			int sizz=st.size();
			if(!st.size()){
		//		puts("empty");
				add(root,list[i].id);
				st.insert(N(list[i].id));
				st.insert(N(list[i].id+n));
			}else{
				set<N>::iterator it=st.upper_bound(N(list[i].id));
				if(it==st.begin()){
					add(root,list[i].id);
					st.insert(N(list[i].id));
					st.insert(N(list[i].id+n));
				}else{
					it--;
			//		printf("%d\n",it->x);
					if(it->x>n){
						fa[list[i].id]=fa[it->x-n];
						add(fa[list[i].id],list[i].id);
						st.insert(N(list[i].id));
						st.insert(N(list[i].id+n));
					}else{
						fa[list[i].id]=it->x;
						add(fa[list[i].id],list[i].id);
						st.insert(N(list[i].id));
						st.insert(N(list[i].id+n));
					}
				}
			}
		}else{
		//	continue;
//			if(now<2762779) goto ed;
//			printf("%u\n",st.size());
//			now=calcnow(list[i])-1e-8;
//			printf("####%.2f\n",(double) now);
//			for(set<N>::iterator it=st.begin();it!=st.end();it++){
//				printf("%d ",it->x);
//			}
//			puts(""); 
//		ed:;
			set<N>::iterator it=st.upper_bound(N(list[i].id));
			it--;
		//		printf("%d DELET %d\n",list[i].id,it->x);
			if(list[i].id!=it->x) break;
			st.erase(it);
			it=st.upper_bound(N(list[i].id+n));
			it--;
		//		printf("%d DELET %d\n",list[i].id,it->x-n);
			if(list[i].id!=it->x-n) break;
			st.erase(it);
		}
	}
	//////////////////////////////////////////////////
	//puts("HHHHHHHHHHHHHHHHHHHH");
	memset(fa,0,sizeof fa);
	for(int i=1;i<=cc;i++) pos[i]++;
	root=1;
	dfs(root);dfs2(root);
	n++;
	for(int i=1;i<=n;i++) where[dfn[i]]=i;
	bd(1,1,n);
	LL ans=0;//printf("s%lld\n",sum[1]);
	for(int i=1;i<=m;i++){
		if(q[i].type){
			cg(1,1,n,dfn[q[i].x+1],q[i].y);
		//	printf("s%lld\n",sum[1]);
		}else{
			int x=pos[q[i].x],y=pos[q[i].y];
			while(top[x]!=top[y]){
				if(dep[top[x]]<dep[top[y]]) swap(x,y);
				ans^=Ask(1,1,n,dfn[top[x]],dfn[x]);
				x=fa[top[x]];
			}
			if(dep[x]<dep[y]) swap(x,y);
			if(x!=y) ans^=Ask(1,1,n,dfn[y]+1,dfn[x]);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
