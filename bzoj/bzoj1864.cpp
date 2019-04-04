#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[500005];
int f[500005][3];// 0,1,2 mx 0
int tot;
void dfs2(){
	tot++;
	int x=tot;
	if(s[tot]=='0'){
		f[tot][0]=1;
	}else if(s[tot]=='1'){
		int ls=tot+1;
		dfs2();
		f[x][0]=1+min(f[ls][1],f[ls][2]);
		f[x][1]=min(f[ls][0],f[ls][2]);
		f[x][2]=min(f[ls][0],f[ls][1]);
	}else{
		int ls=tot+1;
		dfs2();
		int rs=tot+1;
		dfs2();
		f[x][0]=1+min(f[ls][1]+f[rs][2],f[ls][2]+f[rs][1]);
		f[x][1]=min(f[ls][0]+f[rs][2],f[ls][2]+f[rs][0]);
		f[x][2]=min(f[ls][0]+f[rs][1],f[ls][1]+f[rs][0]);
	}
}
void dfs(){
	tot++;
	int x=tot;
	if(s[tot]=='0'){
		f[tot][0]=1;
	}else if(s[tot]=='1'){
		int ls=tot+1;
		dfs();
		f[x][0]=1+max(f[ls][1],f[ls][2]);
		f[x][1]=max(f[ls][0],f[ls][2]);
		f[x][2]=max(f[ls][0],f[ls][1]);
	}else{
		int ls=tot+1;
		dfs();
		int rs=tot+1;
		dfs();
		f[x][0]=1+max(f[ls][1]+f[rs][2],f[ls][2]+f[rs][1]);
		f[x][1]=max(f[ls][0]+f[rs][2],f[ls][2]+f[rs][0]);
		f[x][2]=max(f[ls][0]+f[rs][1],f[ls][1]+f[rs][0]);
	}
}
int main(){
	scanf("%s",s+1);
	dfs();
	printf("%d ",max(max(f[1][0],f[1][1]),f[1][2]));
	memset(f,0,sizeof f);
	tot=0;
	dfs2();
	printf("%d\n",min(min(f[1][0],f[1][1]),f[1][2]));
	return 0;
}
