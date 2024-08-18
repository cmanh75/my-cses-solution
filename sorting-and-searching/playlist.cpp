#include<bits/stdc++.h>
using namespace std;
long long n,a[1000009],c,ans;
map <long long,long long> d;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for (long long i=1;i<=n;i++) {
        c=max(c,d[a[i]]);
        ans=max(i-c,ans);
        d[a[i]]=i;
    }
    cout<<ans;
}
