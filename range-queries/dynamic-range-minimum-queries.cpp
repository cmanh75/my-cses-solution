#include<bits/stdc++.h>
using namespace std;
long long n,it[2000009],q,a[1000009],x,y,c,pos[2000009];
void build (int i,int l,int r) {
    if (l==r) {
        it[i]=a[l];
        pos[l]=i;
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    it[i]=min(it[i*2],it[i*2+1]);
}
void update(int x,int val) {
    int u=pos[x];
    it[u]=val;
    u/=2;
    while (u>0) {
        it[u]=min(it[u*2],it[u*2+1]);
        u/=2;
    }
}
long long ans(int i,int l,int r,int L,int R) {
    if (l>R||r<L) {
        return 1e18;
    }
    if (l>=L&&r<=R) {
        return it[i];
    }
    int mid=(l+r)/2;
    return min(ans(i*2,l,mid,L,R),ans(i*2+1,mid+1,r,L,R));
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    build(1,1,n);
    while (q--) {
        cin>>c>>x>>y;
        if (c==1) {
            update(x,y);
        }
        else {
            cout<<ans(1,1,n,x,y)<<"\n";
        }
    }
}
