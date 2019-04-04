#include<cstdio>
#include<queue>
//by zrt

using namespace std;
deque<int> q;
int num,tt,x;
char s1[10],s2[10];
int main(){
	scanf("%d",&tt);
	while(tt--){
		scanf("%s%s",s1,s2);
		if(s1[0]=='A'){
			if(s2[0]=='L'){
				q.push_front(++num);
			}else q.push_back(++num);
		}else{
			scanf("%d",&x);
			if(s2[0]=='L'){
				for(int i=0;i<x;i++) q.pop_front();
			}else{
				for(int i=0;i<x;i++) q.pop_back();
			}
		}
	}
	for(int i=0;i<q.size();i++){
		printf("%d\n",q[i]);
	}
	return 0;
}
