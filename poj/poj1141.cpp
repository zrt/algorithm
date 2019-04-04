#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[1500];
int f[1500][1500];
int l;
//()[)()))[(((][)]](([[(]][)[)[](([][)[(())]((])((])()([][(])(([(])]([([()([))]])]]([)]]()[[((])[[[
void print(int L,int R){
 //  printf("\n#%d %d\n",L,R);
    if(L>R) return;
    if(((s[L]=='['&&s[R]==']')||(s[L]=='('&&s[R]==')'))&&f[L][R]==f[L+1][R-1]){
   //         puts("SBA");
        putchar(s[L]);print(L+1,R-1);putchar(s[R]);
    }else if(L==R){
     //   puts("SBB");
        if(s[L]=='['||s[L]==']') printf("[]");
        else if(s[L]=='('||s[L]==')') printf("()");
    }else if(f[L][R]==f[L+1][R]+1){
       // puts("SBC");
        if(s[L]=='[') {
            putchar('[');
            print(L+1,R);
            putchar(']');
        }else if(s[L]==']'){
            printf("[]");print(L+1,R);
        }else if(s[L]=='('){
            putchar('(');
            print(L+1,R);
            putchar(')');
        }else if(s[L]==')'){
            printf("()");print(L+1,R);
        }
    }else if(f[L][R]==f[L][R-1]+1){
       // puts("SBD");
        if(s[R]==']') {
            putchar('[');
            print(L,R-1);
            putchar(']');
        }else if(s[R]=='['){
            print(L,R-1);printf("[]");
        }else if(s[R]==')'){
            putchar('(');
            print(L,R-1);
            putchar(')');
        }else if(s[R]=='('){
            print(L,R-1);printf("()");
        }
    }else{
        for(int k=L;k<R;k++){
         //       printf("#%d %d %d %d %d %d\n",L,R,k,f[L][R],f[L][k],f[k+1][R]);
            if(f[L][R]==f[L][k]+f[k+1][R]){
                print(L,k);print(k+1,R);return;
            }
        }
    }
}
int main(){
    scanf("%s",s);
    l=strlen(s);
  //  if(l==0) return 0;
  //  memset(f,0x3f,sizeof f);
    for(int i=0;i<l;i++) f[i][i]=1;
    for(int p=1;p<l;p++){
        for(int i=0;i<l;i++){
            int j=i+p;
            if(j>=l) break;
            f[i][j]=~0U>>1;
            for(int k=i;k<j;k++){
                f[i][j]=min(f[i][k]+f[k+1][j],f[i][j]);
            }
            if((s[i]=='['&&s[j]==']')||(s[i]=='('&&s[j]==')')){
                f[i][j]=min(f[i][j],f[i+1][j-1]);
            }
            f[i][j]=min(f[i][j],min(f[i+1][j]+1,f[i][j-1]+1));
        }
    }
    print(0,l-1);
    putchar('\n');
 //  printf("%d\n",f[0][l-1]);
}
