#include<bits/stdc++.h>
using namespace std;
long long n,q,xo[1000009],x,y;
long long ans(int i) {
    long long res=0;
    for (;i>0;i&=(i-1)) {
        res^=xo[i];
    }
    return res;
}
void gettree(int i) {
    for (int j=i-1;j>(i&(i-1));j&=(j-1)) {
        xo[i]^=xo[j];
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
        cin>>xo[i];
        gettree(i);
    }
    while (q--) {
        cin>>x>>y;
        cout<<(ans(y)^ans(x-1))<<"\n";
    }
}