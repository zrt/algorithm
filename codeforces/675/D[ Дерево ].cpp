#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
using namespace std;


map<int,int> who;
set<int> st;

int n;
int a[100005];
int fa[100005];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    st.insert(1);who[1]=1;
    st.insert(a[1]);who[a[1]]=1;
    for(int i=2;i<=n;i++){
        set<int>::iterator it=st.upper_bound(a[i]);
        it--;
        fa[i]=who[*it];
        who[*it]=i;
        st.insert(a[i]);
        who[a[i]]=i;
    }
    for(int i=2;i<=n;i++) printf("%d ",a[fa[i]]);
        puts("");
    return 0;
}