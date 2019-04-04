#include<cstdio>
#include<cstring>
using namespace std;
int siz;
struct Matrix{
    int a[10][10];
    void setI(){
        for(int i=1;i<=siz;i++){
            for(int j=1;j<=siz;j++){
                if(i==j) a[i][j]=1;
                else a[i][j]=0;
            }
        }
    }
    void set0(){
        memset(a,0,sizeof a);
    }
    friend Matrix operator *(Matrix a,Matrix b){
        Matrix c;
        c.set0();
        for(int i=1;i<=siz;i++){
            for(int j=1;j<=siz;j++){
                for(int k=1;k<=siz;k++){
                    c.a[i][j]+=a.a[i][k]*b.a[k][j];
                }
            }
        }
        return c;
    }
};
int main(){
    Matrix a,b;
    siz=2;
    a.set0();b.set0();
    scanf("%d%d",&a.a[1][1],&a.a[1][2]);
    b.a[1][1]=1;b.a[2][1]=1;
    Matrix c=a*b;
    printf("%d\n",c.a[1][1]);
    return 0;
}
