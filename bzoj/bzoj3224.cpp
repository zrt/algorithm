#include<cstdio>
#include<cstdlib>
//by zrt
//problem: Treap
using namespace std;
const int inf=~0U>>1;
struct Treap{
	struct node{
		int val,key,size,has;
		node(int v,node*n){
			val=v;c[0]=c[1]=n;size=1;has=1;key=rand()-1;
		}
		void rz(){
			size=c[0]->size+c[1]->size+has;
		}
		node*c[2];
	}*root,*null;
	void rot(node*&t,int d){ // 0 right //旋转的是t的孩子 
		//也可以理解为把t的哪个孩子旋转上来 
		node*c=t->c[d];
		t->c[d]=c->c[d^1];
		c->c[d^1]=t;
		t->rz();c->rz();
		t=c;// 原先连t的现在连c 
	}
	void insert(node*&t,int x){// 向t添加 x 节点 
		if(t->val==x){
			t->has++;
			t->rz();
			return;
		}
		if(t==null){//如果t 指向null 
			t=new node(x,null);return;
		}
		int d=x>t->val;//左子树< 右子树> 
		insert(t->c[d],x);
		//插入完毕，调整以满足堆性质
		if(t->c[d]->key<t->key){
			rot(t,d);
		}else
			t->rz();
	}
	void Delete(node*&t,int x){
		if(t==null) return;
		if(t->val==x){
			if(t->has>1){
				t->has--;
				t->rz();
				return;
			}
			int d=t->c[1]->key<t->c[0]->key;
			//取孩子 key值最小的
			if(t->c[d]==null){
				//null key=inf
			//	delete t;
				t=null;
				return;
			}
			rot(t,d);
			Delete(t->c[d^1],x);
		}else{
			int d=x>t->val;
			Delete(t->c[d],x);
		}
		t->rz();
	}
	int select(node*t,int k){//第k+1大 
		int r=t->c[0]->size;
		if(k>r&&k<=r+t->has) return t->val;
		if(k<=r) return select(t->c[0],k);
		return select(t->c[1],k-r-t->has);
	}
	int rank(node*t,int x){//查询x前面有多少数 
		if(t==null) return 0;
		int r=t->c[0]->size;
		if(x==t->val) return r;
		if(x<t->val) return rank(t->c[0],x);
		return r+t->has+rank(t->c[1],x);
	}
	Treap(){//构造函数 
		null=new node(0,0);null->size=0;null->key=inf;null->has=0;
		root=null;
	}
	int Qian(node*t,int x,int last){// last 上一个比它小的。 
		if(t==null) return last;
		if(t->val==x){
			if(t->c[0]==null){
				return last;
			}else{
				t=t->c[0];
				while(t->c[1]!=null) t=t->c[1];
				return t->val;
			}
		}
		if(t->val>x){
			return Qian(t->c[0],x,last);
		}else{
			return Qian(t->c[1],x,t->val);
		}
	}
	int Hou(node*t,int x,int last){// last 上一个比它小的。 
		if(t==null) return last;
		if(t->val==x){
			if(t->c[1]==null){
				return last;
			}else{
				t=t->c[1];
				while(t->c[0]!=null) t=t->c[0];
				return t->val;
			}
		}
		if(t->val<x){
			return Hou(t->c[1],x,last);
		}else{
			return Hou(t->c[0],x,t->val);
		}
	}
};
Treap T;
int n,x;
int opt;
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	srand(98813);
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&opt,&x);
		switch(opt){
			case 1: T.insert(T.root,x);break;
			case 2: T.Delete(T.root,x);break;
			case 3: printf("%d\n",T.rank(T.root,x)+1);break;
			case 4: printf("%d\n",T.select(T.root,x));break;
			case 5: printf("%d\n",T.Qian(T.root,x,T.root->val));break;
			case 6: printf("%d\n",T.Hou(T.root,x,T.root->val));break;
		}
	}
	return 0;
}
