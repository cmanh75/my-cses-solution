#include<bits/stdc++.h>
using namespace std;
long long n,bit[1000009],q,a[1000009],x,y,c;
void update(int x,int val) {
    for (;x<=n;x+=(x&(-x))) {
        bit[x]+=val;
    }
}
long long ans(int x) {
    long long res=0;
    for (;x>0;x&=(x-1)) {
        res+=bit[x];
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        update(i,a[i]);
    }
    while (q--) {
        cin>>c>>x>>y;
        if (c==1) {
            update(x,y-a[x]);
            a[x]=y;
        }
        else {
            cout<<ans(y)-ans(x-1)<<"\n";
        }
    }
}