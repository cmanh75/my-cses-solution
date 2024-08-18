#include<bits/stdc++.h>
using namespace std;
long long i,n,a[1000000],ans,x,y,t;
vector <long long> setf,sets;
void solve() {
    cin>>n;
    t=n*(n+1)/2;
    if (t%2) {
        cout<<"NO";
        return;
    }
    else {
        cout<<"YES\n";
        t/=2;
        for (i=n;i>=1;i--) {
            if (t-i>=0) {
                setf.push_back(i);
                t-=i;
            }
            else {
                sets.push_back(i);
            }
        }
        cout<<setf.size()<<"\n";
        for (long long j : setf) {
            cout<<j<<" ";
        }
        cout<<"\n"<<sets.size()<<"\n";
        for (long long j : sets) {
            cout<<j<<" ";
        }
    }
}
int main() {
    solve();
}
