#include<bits/stdc++.h>
using namespace std;
long long n,x,y,sum[1000009],q;
long long ans(int x) {
    long long res=0;
    for (;x>0;x&=(x-1)) {
        res+=sum[x];
    }
    return res;
}
void update(int x) {
    for (int j=x-1,k=0;j>(x&(x-1));j-=(1<<k),k++) {
        sum[x]+=sum[j];
    }
}
int main() {
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
        cin>>x;
        sum[i]=x;
        update(i);
    }
    while (q--) {
        cin>>x>>y;
        cout<<ans(y)-ans(x-1)<<"\n";
    }
}