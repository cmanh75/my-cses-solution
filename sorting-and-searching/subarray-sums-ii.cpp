#include<bits/stdc++.h>
using namespace std;
int n,p,x;
map <long long ,int > f;
long long s,ans;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>p;
    f[0]=1;
    for (int i=1;i<=n;i++) {
        cin>>x;
        s+=x;
        ans+=f[s-p];
        f[s]++;
    }
    cout<<ans;
}
