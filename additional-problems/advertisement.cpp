#include<bits/stdc++.h>
using namespace std;
deque <int> dq;
long long n,ans,a[1000008],l[1000009];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        while (dq.size()&&a[dq.back()]>=a[i]) {
            dq.pop_back();
        }
        if (!dq.size()) {
            l[i]=0;
        }
        else {
            l[i]=dq.back();
        }
        dq.push_back(i);
    }
    dq.clear();
    for (int i=n;i>=1;i--) {
        while (dq.size()&&a[dq.back()]>=a[i]) {
            dq.pop_back();
        }
        if (!dq.size()) {
            ans=max((n-l[i])*a[i],ans);
        }
        else {
            ans=max(ans,(dq.back()-l[i]-1)*a[i]);
        }
        dq.push_back(i);
    }
    cout<<ans;
}
