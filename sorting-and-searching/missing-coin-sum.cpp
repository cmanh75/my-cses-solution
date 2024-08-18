#include<bits/stdc++.h>
using namespace std;
int n,a[1000009];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if (a[1]>1) {
        cout<<"1";
        return 0;
    }
    long long s=a[1];
    for (int i=2;i<=n;i++) {
        if (a[i]>s+1) {
            cout<<s+1;
            return 0;
        }
        s+=a[i];
    }
    cout<<s+1;
}
