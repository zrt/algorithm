#include<cstdio>
#include<cstring>
int i,l,k,a,b,T,t[555],A[555];
char s[555],d[555];
//poj1220 
int main(){
	scanf("%d",&T); 
	while(T--){
		scanf("%d%d%s",&a,&b,s);
		k=strlen(s);
		for(i=k-1;i>=0;i--) t[k-1-i]=s[i]-(s[i]<58?48:s[i]<97?55:61);
		for(l=0;k;){
			for(i=k-1;i>=1;i--){
				t[i-1]+=t[i]%b*a;
				t[i]/=b;
			}
			A[l++]=t[0]%b;
			t[0]/=b;
			for( ; k>0 && !t[k-1] ; k-- );
		}
		
		for(d[l]=i=0;i<l;i++) d[l-1-i]= A[i] + (A[i]<10?48:A[i]<36?55:61);
		
		printf("%d %s\n%d %s\n\n",a,s,b,d);
	}
	return 0;
}