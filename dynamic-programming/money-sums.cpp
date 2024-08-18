#include<bits/stdc++.h>
using namespace std;
int n,a[1000009],sum,d[1000009];
vector <int> ans;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    d[0]=1;
    for (int i=1;i<=n;i++) {
        for (int j=sum;j>=0;j--) {
            if (d[j]) {
                d[j+a[i]]=1;
            }
        }
        cout<<"\n";
        sum+=a[i];
    }
    for (int i=1;i<=sum;i++) {
        if (d[i]) {
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<"\n";
    for (int j : ans) {
        cout<<j<<" ";
    }
}
