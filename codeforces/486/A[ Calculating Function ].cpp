#include<iostream>
using namespace std;
long long n;
int main(){
    cin>>n;
    if(n&1){
        cout<<(n-1)/2-n<<endl;
    }else{
        cout<<n/2<<endl;
    }
    return 0;
}