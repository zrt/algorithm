#include<iostream>
#include<cstdio>
#include<cstring>
//by zrt
//problem:
using namespace std;
bool bag[20000*6+100];
int a,b,c,d,e,f,total,aim,cas;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	while(scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f)==6&&(a||b||c||d||e||f)){
		total=a+b*2+c*3+d*4+e*5+f*6;
		printf("Collection #%d:\n",++cas);
		if(total&1){
			puts("Can't be divided.\n");continue;
		}
		memset(bag,0,sizeof bag);
		aim=total>>1;
		int maxn=0;
		bag[0]=1;
		int i,w;
		for(i=1;(i<<1)-1<a;i<<=1){
			w=i;
			for(int i=min(maxn,aim-w);i>=0;i--){
				if(bag[i]){
					bag[i+w]=1;
					if(bag[aim]){
						puts("Can be divided.\n");goto end;
					}
					if(i+w>maxn){
						maxn=i+w;
					}
				}
			}
		}
	//	i>>=1;
		w=a-i+1;
		for(int i=min(maxn,aim-w);a&&i>=0;i--){
			if(bag[i]){
				bag[i+w]=1;
				if(bag[aim]){
					puts("Can be divided.\n");goto end;
				}
				if(i+w>maxn){
					maxn=i+w;
				}
			}
		}
		for(i=1;(i<<1)-1<b;i<<=1){
			w=i*2;
			for(int i=min(maxn,aim-w);i>=0;i--){
				if(bag[i]){
					bag[i+w]=1;
					if(bag[aim]){
						puts("Can be divided.\n");goto end;
					}
					if(i+w>maxn){
						maxn=i+w;
					}
				}
			}
		}
//		i>>=1;
		w=(b-i+1)*2;
		for(int i=min(maxn,aim-w);b&&i>=0;i--){
			if(bag[i]){
				bag[i+w]=1;
				if(bag[aim]){
					puts("Can be divided.\n");goto end;
				}
				if(i+w>maxn){
					maxn=i+w;
				}
			}
		}
		for(i=1;(i<<1)-1<c;i<<=1){
			w=i*3;
			for(int i=min(maxn,aim-w);i>=0;i--){
				if(bag[i]){
					bag[i+w]=1;
					if(bag[aim]){
						puts("Can be divided.\n");goto end;
					}
					if(i+w>maxn){
						maxn=i+w;
					}
				}
			}
		}
	//	i>>=1;
		w=(c-i+1)*3;
		for(int i=min(maxn,aim-w);c&&i>=0;i--){
			if(bag[i]){
				bag[i+w]=1;
				if(bag[aim]){
					puts("Can be divided.\n");goto end;
				}
				if(i+w>maxn){
					maxn=i+w;
				}
			}
		}
		for(i=1;(i<<1)-1<d;i<<=1){
			w=i*4;
			for(int i=min(maxn,aim-w);i>=0;i--){
				if(bag[i]){
					bag[i+w]=1;
					if(bag[aim]){
						puts("Can be divided.\n");goto end;
					}
					if(i+w>maxn){
						maxn=i+w;
					}
				}
			}
		}
	//	i>>=1;
		w=(d-i+1)*4;
		for(int i=min(maxn,aim-w);d&&i>=0;i--){
			if(bag[i]){
				bag[i+w]=1;
				if(bag[aim]){
					puts("Can be divided.\n");goto end;
				}
				if(i+w>maxn){
					maxn=i+w;
				}
			}
		}
		for(i=1;(i<<1)-1<e;i<<=1){
			w=i*5;
			for(int i=min(maxn,aim-w);i>=0;i--){
				if(bag[i]){
					bag[i+w]=1;
					if(bag[aim]){
						puts("Can be divided.\n");goto end;
					}
					if(i+w>maxn){
						maxn=i+w;
					}
				}
			}
		}
	//	i>>=1;
		w=(e-i+1)*5;
		for(int i=min(maxn,aim-w);e&&i>=0;i--){
			if(bag[i]){
				bag[i+w]=1;
				if(bag[aim]){
					puts("Can be divided.\n");goto end;
				}
				if(i+w>maxn){
					maxn=i+w;
				}
			}
		}
		for(i=1;(i<<1)-1<f;i<<=1){
			w=i*6;
			for(int i=min(maxn,aim-w);i>=0;i--){
				if(bag[i]){
					bag[i+w]=1;
					if(bag[aim]){
						puts("Can be divided.\n");goto end;
					}
					if(i+w>maxn){
						maxn=i+w;
					}
				}
			}
		}
	//	i>>=1;
		w=(f-i+1)*6;
		for(int i=min(maxn,aim-w);f&&i>=0;i--){
			if(bag[i]){
				bag[i+w]=1;
				if(bag[aim]){
					puts("Can be divided.\n");goto end;
				}
				if(i+w>maxn){
					maxn=i+w;
				}
			}
		}
		puts("Can't be divided.\n");goto end;
		end: ;
	}
	return 0;
}
