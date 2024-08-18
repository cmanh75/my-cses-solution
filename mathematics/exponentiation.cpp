#include<bits/stdc++.h>
using namespace std;
long long q,a,b;
const long long mod=1e9+7;
long long po(long long a,long long b) {
    if (b==0) {
        return 1;
    }
    if (b==1) {
        return a;
    }
    long long t=po(a,b/2);
    if (b&1) {
        return ((t*t)%mod*a)%mod;
    }
    return (t*t)%mod;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for (cin>>q;q--;) {
        cin>>a>>b;
        cout<<po(a,b)<<"\n";
    }
}