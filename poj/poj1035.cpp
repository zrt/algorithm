#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int trie[150005][26];
int tot;
int num[150005];
char dict[10005][16];
int cnt;
char s[30];
int finds[30005];
int main(){
    while(scanf("%s",dict[++cnt])&&dict[cnt][0]!='#');
    cnt--;
    for(int i=1;i<=cnt;i++){
        int idx=0;
        for(int j=0;dict[i][j];j++){
            if(trie[idx][dict[i][j]-'a']) idx=trie[idx][dict[i][j]-'a'];
            else idx=trie[idx][dict[i][j]-'a']=++tot;
        }
        num[idx]=i;
    }
    while(scanf("%s",s)&&s[0]!='#'){
        bool ok=1;
        int idx=0;
        for(int i=0;s[i]&&ok;i++){
            if(trie[idx][s[i]-'a']) idx=trie[idx][s[i]-'a'];
            else ok=0;
        }
        int p=0;
        if(ok){
            for(int i=0;i<26;i++){
                if(num[trie[idx][i]]) finds[p++]=num[trie[idx][i]];
            }
        }
        if(!num[idx]) ok=0;
        if(ok){
            printf("%s is correct\n",s);
            continue;
        }
        //1. shan
        for(int i=0;s[i];i++){
            idx=0;
            for(int j=0;s[j];j++) if(j!=i) {
                if(trie[idx][s[j]-'a']) idx=trie[idx][s[j]-'a'];
                else{
                    idx=0;break;
                }
            }
            if(num[idx]) finds[p++]=num[idx];
        }
        //2.tihuan
        for(int i=0;s[i];i++){
            for(int k=0;k<26;k++){
                idx=0;
                for(int j=0;s[j];j++) if(j!=i) {
                    if(trie[idx][s[j]-'a']) idx=trie[idx][s[j]-'a'];
                    else{
                        idx=0;break;
                    }
                }else{
                    if(trie[idx][k]) idx=trie[idx][k];
                    else{
                        idx=0;break;
                    }
                }
                if(num[idx]) finds[p++]=num[idx];
            }
        }
        //3.tianjia
        // i wei zhi qian
        for(int i=0;s[i];i++){
            for(int k=0;k<26;k++){
                idx=0;
                for(int j=0;s[j];j++){
                    if(i==j){
                        if(trie[idx][k]) idx=trie[idx][k];
                        else{
                            idx=0;break;
                        }
                    }
                    {
                        if(trie[idx][s[j]-'a']) idx=trie[idx][s[j]-'a'];
                        else{
                            idx=0;break;
                        }
                    }
                }
                if(num[idx]) finds[p++]=num[idx];
            }
        }
        sort(finds,finds+p);
        int last=-1;
        printf("%s:",s);
        bool first=1;
        for(int i=0;i<p;i++){
            if(finds[i]!=last){
                last=finds[i];
        //        if(first) first=0;else putchar(' ');
                printf(" %s",dict[finds[i]]);
            }
        }
        puts("");
    }
    return 0;
}
