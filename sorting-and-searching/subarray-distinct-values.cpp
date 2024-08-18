#include<bits/stdc++.h>
using namespace std;
int n,a[1000009],r,k;
long long ans;
map <int,int> d;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    int j=0;
    for (int i=1;i<=n;i++) {
        if (!d[a[i]]) {
            r++;
        }
        d[a[i]]++;
        if (r>k) {
            do {
                j++;
                d[a[j]]--;
            } while (d[a[j]]);
            r--;
        }
        ans+=i-j;
    }
    cout<<ans;
}