#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
//by zrt
//problem:
using namespace std;
typedef long long LL;
const int inf(0x3f3f3f3f);
const double eps(1e-9);
const int N=3000000;
char s[5101000],s1[51010000],str[2600][1200];
int next[N][26],fail[N],flag[N],pos;
int ans,ok[3000];
bool vis[N];
int newnode(){
	memset(next[pos],0,sizeof next[pos]);
	fail[pos]=flag[pos]=0;
	return pos++;
}

void insert(char*s,int id){
	int p=0,i=0;
	for(;s[i];i++){
		int k=s[i]-'A';
		p=next[p][k]?next[p][k]:next[p][k]=newnode();
	}
	flag[p]=id;
}

void makefail(){
	queue<int>q;
	q.push(0);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<26;i++){
			int v=next[u][i];
			if(!v) next[u][i]=next[fail[u]][i];
			else q.push(v);
			if(v&&u) fail[v]=next[fail[u]][i];
		}
	}
}

void findstr(char*s){
	int p=0,i;
	for(i=0;s[i];i++){
		int k=s[i]-'A';
		p=next[p][k];
		if(flag[p]){
			ok[flag[p]]=1;
			continue;
		}
		for(int j=p;j&&!vis[j];j=fail[j]){
			vis[j]=1;
			ok[flag[p]]=1;
		}
	}
}
void sea(char*s,int id){
	int p=0,i;
	for(i=0;s[i];i++){
		int k=s[i]-'A';
		p=next[p][k];
		for(int j=p;j&&!vis[j];j=fail[j]){
			if(flag[j]&&flag[j]!=id){
				ok[flag[j]]=0;
				vis[j]=1;
			}
		}
	}
}
void change(){
	int i,j,k,len,tem;
	len=strlen(s);
	for(i=j=0;i<len;){
		if(s[i]!='['){
			s1[j++]=s[i++];
		}else{
			i++;
			tem=0;
			while(s[i]>='0'&&s[i]<='9'){
				tem=tem*10+s[i]-'0';
				i++;
			}
			for(k=1;k<=tem;k++) s1[j++]=s[i];
			i+=2;
		}
	}
	s1[j]='\0';
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int t,T,n,i;
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		memset(vis,0,sizeof vis);
		memset(ok,0,sizeof ok);
		scanf("%d",&n);
		pos=0;newnode();
		for(i=1;i<=n;i++){
			scanf("%s",str[i]);
			strcpy(s,str[i]);
			change();
			strcpy(str[i],s1);
			insert(s1,i);
		}
		makefail();
		scanf("%s",s);
		change();
		findstr(s1);
		memset(vis,0,sizeof vis);
		for(i=1;i<=n;i++) if(ok[i]) sea(str[i],i);
		ans=0;
		for(i=1;i<=n;i++) ans+=ok[i];
		printf("%d\n",ans);
	}
	
	return 0;
}
