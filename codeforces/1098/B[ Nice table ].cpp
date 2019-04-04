#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;

int n,m;
vector<int> v[300005];
vector<int> vv[300005];
char s[300005];
char ACGT[]="ACGT";
LL cnt[2][300005][4];

LL ans = (1LL<<60);

void solve(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cnt[i&1][j][v[i][j]] ++;
		}
	}
	for(int i=0;i<4;i++){
		for(int j=i+1;j<4;j++){
			// i,j
			for(int k=0;k<4;k++){
				if(k!=i && k!=j){
					int l = 6-i-j-k;
					LL tmp = 0;
					for(int w=0;w<m;w++){
						if(w&1){
							tmp += min(n-cnt[0][w][i] - cnt[1][w][j], n-cnt[0][w][j]- cnt[1][w][i]);
						}else{
							tmp += min(n-cnt[0][w][k] - cnt[1][w][l], n-cnt[0][w][l]- cnt[1][w][k]);
						}
					}
					ans = min(ans,tmp);
				}
			}
		}
	}
}
bool FLIP;
int output[2][300005];
void solve2(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cnt[i&1][j][v[i][j]] ++;
		}
	}
	for(int i=0;i<4;i++){
		for(int j=i+1;j<4;j++){
			// i,j
			for(int k=0;k<4;k++){
				if(k!=i && k!=j){
					int l = 6-i-j-k;
					LL tmp = 0;
					for(int w=0;w<m;w++){
						if(w&1){
							tmp += min(n-cnt[0][w][i] - cnt[1][w][j], n-cnt[0][w][j]- cnt[1][w][i]);
						}else{
							tmp += min(n-cnt[0][w][k] - cnt[1][w][l], n-cnt[0][w][l]- cnt[1][w][k]);
						}
					}
					if(ans == tmp){
						// printf("%c %c %c %c %I64d\n",ACGT[i],ACGT[j],ACGT[k],ACGT[l],ans);
						for(int w=0;w<m;w++){
							if(w&1){
								if(n-cnt[0][w][i] - cnt[1][w][j] < n-cnt[0][w][j]- cnt[1][w][i]){
									output[0][w] = i;
									output[1][w] = j;
								}else{
									output[0][w] = j;
									output[1][w] = i;
								}
							}else{
								if(n-cnt[0][w][k] - cnt[1][w][l] < n-cnt[0][w][l]- cnt[1][w][k]){
									output[0][w] = k;
									output[1][w] = l;
								}else{
									output[0][w] = l;
									output[1][w] = k;
								}
							}
						}
						if(FLIP){
							for(int i=0;i<m;i++){
								for(int j=0;j<n;j++){
									putchar(ACGT[output[j&1][i]]);
								}
								puts("");
							}
						}else{
							for(int i=0;i<n;i++){
								for(int j=0;j<m;j++){
									putchar(ACGT[output[i&1][j]]);
								}
								puts("");
							}
						}
						exit(0);
					}
				}
			}
		}
	}
}


int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",s);
		for(int j=0;s[j];j++){
			for(int k=0;k<4;k++){
				if(s[j]==ACGT[k]){
					v[i].push_back(k);
				}
			}
		}
	}
	solve();
	memset(cnt,0,sizeof cnt);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			vv[i].push_back(v[j][i]);
		}
	}
	for(int i=0;i<m;i++) v[i] = vv[i];
	swap(m,n);
	solve();
	// printf("%I64d\n",ans);
	memset(cnt,0,sizeof cnt);
	for(int i=0;i<m;i++){
		vv[i].clear();
		for(int j=0;j<n;j++){
			vv[i].push_back(v[j][i]);
		}
	}
	for(int i=0;i<m;i++) v[i] = vv[i];
	swap(m,n);
	solve2();
	memset(cnt,0,sizeof cnt);
	for(int i=0;i<m;i++){
		vv[i].clear();
		for(int j=0;j<n;j++){
			vv[i].push_back(v[j][i]);
		}
	}
	for(int i=0;i<m;i++) v[i] = vv[i];
	swap(m,n);
FLIP=1;
	solve2();


	

	return 0;
}
