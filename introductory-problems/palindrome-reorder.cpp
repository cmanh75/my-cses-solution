#include<bits/stdc++.h>
using namespace std;
long long i,n,d[1000000],ans,x,y,t;
vector <long long> a;
string s;
void solve() {
    cin>>s;
    for (i=0;i<s.size();i++) {
        if (d[s[i]]==0) {
            a.push_back((int)(s[i]));
        }
        d[(int)s[i]]++;
        if (d[s[i]]%2!=0) {
            t++;
        }
        else {
            t--;
        }
    }
    if (t>1) {
        cout<<"NO SOLUTION";
        return;
    }
    for (auto j : a) {
        for (i=1;i<=d[j]/2&&d[j]%2==0;i++) {
            cout<<char(j);
        }
        if (d[j]%2!=0) {
            x=j;
        }
    }
    for (i=1;i<=d[x];i++) {
        cout<<char(x);
    }
    for (y=a.size()-1;y>=0;y--) {
        int j=a[y];
        for (i=1;i<=d[j]/2&&d[j]%2==0;i++) {
            cout<<char(j);
        }
    }
}
int main() {
    solve();
}
