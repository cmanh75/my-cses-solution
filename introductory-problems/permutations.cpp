#include<bits/stdc++.h>
using namespace std;
long long i,n,a[1000000],ans;
void solve() {
    cin>>n;
    if (n<=3&&n>1) {
        cout<<"NO SOLUTION";
        return;
    }
    for (i=2;i<=n;i+=2) {
        cout<<i<<" ";
    }
    for (i=1;i<=n;i+=2) {
        cout<<i<<" ";
    }
}
int main() {
    solve();
}