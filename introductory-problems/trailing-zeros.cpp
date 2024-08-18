#include<bits/stdc++.h>
using namespace std;
long long i,n,a[1000000],ans,x,y,t,d;
vector <long long> setf,sets;
void solve() {
    cin>>n;
    for (i=5;n/i>=1;i*=5) {
        ans+=n/i;
    }
    cout<<ans;
}
int main() {
    solve();
}