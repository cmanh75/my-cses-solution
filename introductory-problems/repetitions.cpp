#include<bits/stdc++.h>
using namespace std;
long long i,d,ans;
string s;
void solve() {
    cin>>s;
    d=1;
    s=s+'a';
    for (i=1;i<s.size();i++) {
        if (s[i]==s[i-1]) {
            d++;
        }
        else {
            ans=max(ans,d);
            d=1;
        }
    }
    cout<<ans;
}
int main() {
    solve();
}
