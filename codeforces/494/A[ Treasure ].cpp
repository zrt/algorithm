#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
char s[100005];
queue<int> q;
int main(){
    scanf("%s",s);
    int num=0;
    bool ok=0;
    int mn=0;
    for(int i=0;s[i];i++){
        if(s[i]=='(') num++,mn++;
        else if(s[i]==')'){
            num--;mn--;
            if(mn<0) mn=0;
            if(num<0){
                puts("-1");return 0;
            }
            if(num==0&&ok){
                puts("-1");return 0;
            }
        }else{
            mn=0;
            if(num==0){
                puts("-1");return 0;
            }else{
                if(ok){
                    q.push(1);
                    num--;
                }else{
                    ok=1;
                }
            }
        }
    }
    if(ok){
        if(num==0||mn>0){
            puts("-1");
            return 0;
        }else{
            q.push(num);
            while(!q.empty()){
                printf("%d\n",q.front());
                q.pop();
            }
        }
    }
//  while(1);
    return 0;
}