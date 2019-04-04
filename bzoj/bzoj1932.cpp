#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n;
char s[100];
typedef unsigned long long LL;
vector<LL> stk[4005];int top;
vector<LL> empty,tmp;
LL hash(vector<LL>&v){
	LL ret=401794301;
	for(int i=0;i<v.size();i++){
		ret=ret*13331+v[i];
	}
	return ret;
}
vector<LL> Union(vector<LL>&a,vector<LL>&b){
	vector<LL> c;
	c.clear();
	c.insert(c.end(),a.begin(),a.end());
	c.insert(c.end(),b.begin(),b.end());
	sort(c.begin(),c.end());
	c.erase(unique(c.begin(),c.end()),c.end());
	return c;
}
vector<LL> Inter(vector<LL>&a,vector<LL>&b){
	vector<LL> c;
	c.clear();
	int h1=0,h2=0;
	while(h1<a.size()&&h2<b.size()){
		if(a[h1]==b[h2]) c.push_back(a[h1]),h1++,h2++;
		else{
			if(a[h1]<b[h2]) h1++;else h2++;
		}
	}
	return c;
}
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%s",s);
		if(s[0]=='P'){
			stk[top++]=empty;
		}else if(s[0]=='D'){
			stk[top]=stk[top-1];top++;
		}else if(s[0]=='A'){
			tmp=stk[top-2];
			tmp.push_back(hash(stk[top-1]));
			sort(tmp.begin(),tmp.end());
			tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
			top--;top--;
			stk[top++]=tmp;
		}else if(s[0]=='U'){
			stk[top-2]=Union(stk[top-1],stk[top-2]);top--;
		}else if(s[0]=='I'){
			stk[top-2]=Inter(stk[top-1],stk[top-2]);top--;
		}
		printf("%u\n",stk[top-1].size());
	}
	return 0;
}
