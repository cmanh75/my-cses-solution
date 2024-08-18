#include<bits/stdc++.h>
using namespace std;
int n,q,c,x,y,a[1000009][3],pos[1000009];
long long it[3000009][3];
void build(int i,int l,int r) {
    if (l==r) {
        it[i][0]=a[l][0];
        it[i][1]=a[l][1];
        pos[l]=i;
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    it[i][1]=min(it[i*2][1],it[i*2+1][1]);
    it[i][0]=max(it[i*2][0],it[i*2+1][0]);
}
void update(int x,int y) {
    int i=pos[x];
    it[i][0]=x-y;
    it[i][1]=y+x;
    i/=2;
    while (i) {
        it[i][1]=min(it[i*2][1],it[i*2+1][1]);
        it[i][0]=max(it[i*2][0],it[i*2+1][0]);
        i/=2;
    }
}
long long ans(int i,int l,int r,int L,int R,int c) {
    if (l>R||r<L) {
        if (c) {
            return 1e18;
        }
        else {
            return -1e18;
        }
    }
    if (l>=L&&r<=R) {
        return it[i][c];
    }
    int mid=(l+r)/2;
    if (c) {
        return min(ans(i*2,l,mid,L,R,1),ans(i*2+1,mid+1,r,L,R,1));
    }
    return max(ans(i*2,l,mid,L,R,0),ans(i*2+1,mid+1,r,L,R,0));
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
        cin>>x;
        a[i][0]=i-x;
        a[i][1]=x+i;
    }
    build(1,1,n);
    while (q--) {
        cin>>c>>x;
        if (c==1) {
            cin>>y;
            update(x,y);
        }
        else {
            cout<<min(x-ans(1,1,n,1,x-1,0),ans(1,1,n,x,n,1)-x)<<"\n";
        }
    }
}
