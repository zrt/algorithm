#include<cstdio>
using namespace std;
int n;
int tot,x,y;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&y);
		if(tot==0){
			tot=1;
			x=y;
		}else if(x==y){
			tot++;
		}else{
			tot--;
		}
	}
	printf("%d\n",x);
	return 0;
}
