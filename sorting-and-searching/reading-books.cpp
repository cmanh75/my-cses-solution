#include<bits/stdc++.h>
using namespace std;
long long n,x,s,ma;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>x;
        ma=max(ma,x);
        s+=x;
    }
    if (ma*2>s) {
        cout<<ma*2;
        return 0;
    }
    cout<<s;
}