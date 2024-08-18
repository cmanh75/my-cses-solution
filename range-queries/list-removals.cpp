#include<bits/stdc++.h>
using namespace std;
int n,it[2000009],pos[2000009],a[1000009],x;
void build(int i,int l,int r) {
    if (l==r) {
        it[i]=1;
        pos[i]=l;
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    it[i]=it[i*2]+it[i*2+1];
}
void update(int x) {
    it[x]--;
    x/=2;
    while (x) {
        it[x]=it[x*2]+it[x*2+1];
        x/=2;
    }
}
int ans(int x) {
    int i=1,cs;
    while (it[i]) {
        cs=i;
        if (x>it[i*2]) {
            x-=it[i*2];
            i=i*2+1;
        }
        else {
            i*=2;
        }
    }
    return cs;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    build(1,1,n);
    for (int i=1;i<=n;i++) {
        cin>>x;
        int u=ans(x);
        cout<<a[pos[u]]<<" ";
        update(u);
    }
}