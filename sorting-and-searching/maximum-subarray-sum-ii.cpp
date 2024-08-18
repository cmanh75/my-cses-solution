#include<bits/stdc++.h>
using namespace std;
long long n,sum[1000009],ans=-1e18,l,r,x,a[1000009];
deque <long long> dq;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>l>>r;
    for (int i=1;i<=n;i++) {
        cin>>x;
        sum[i]=sum[i-1]+x;
    }
    for (int i=l;i<=n;i++) {
        while (dq.size()&&dq.front()<i-r) {
            dq.pop_front();
        }
        while (dq.size()&&sum[dq.back()]>=sum[i-l]) {
            dq.pop_back();
        }
        if (!dq.size()) {
            ans=max(ans,sum[i]-sum[i-l]);
        }
        else {
            ans=max(ans,sum[i]-sum[dq.front()]);
        }
        dq.push_back(i-l);
    }
    cout<<ans;
}
