#include<bits/stdc++.h>
using namespace std;
long long i,n,a[1000000],ans,x,y,t,d;
vector <long long> setf,sets;
void solve() {
    cin>>x>>y;
    if (x>y) {
        d=x-y;
        if (y<d) {
            cout<<"NO\n";
            return;
        }
        else {
            if ((y-d)%3==0) {
                cout<<"YES\n";
            }
            else {
                cout<<"NO\n";
            }
        }
    }
    else {
        d=y-x;
        if (x<d) {
            cout<<"NO\n";
            return;
        }
        else {
            if ((x-d)%3==0) {
                cout<<"YES\n";
            }
            else {
                cout<<"NO\n";
            }
        }
    }
}
int main() {
    for (cin>>t;t--;) {
        solve();
    }
}
