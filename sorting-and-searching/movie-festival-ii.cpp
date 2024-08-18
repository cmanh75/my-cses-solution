#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair <int,int> pa;
int n,k,ans,it[2000009][2],d[2000009];
pa a[200009];
bool cmp(pa x,pa y) {
    return x.fi<y.fi;
}
void build(int i,int l,int r) {
    d[i]=1;
    if (l==r) {
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
}
void updatemin(int val) {
    int i=1;
    while (d[i*2]) {
        if (it[i*2][0]>it[i*2+1][0]) {
            i=i*2+1;
        }
        else {
            i*=2;
        }
    }
    it[i][1]=val;
    it[i][0]=val;
    i/=2;
    while (i) {
        it[i][1]=max(it[i*2][1],it[i*2+1][1]);
        it[i][0]=min(it[i*2][0],it[i*2+1][0]);
        i/=2;
    }
}
void updatemax(int val) {
    int i=1;
    while (d[i*2]) {
        if (it[i*2][1]<it[i*2+1][1]) {
            i=i*2+1;
        }
        else {
            i*=2;
        }
    }
    it[i][1]=val;
    it[i][0]=val;
    i/=2;
    while (i) {
        it[i][1]=max(it[i*2][1],it[i*2+1][1]);
        it[i][0]=min(it[i*2][0],it[i*2+1][0]);
        i/=2;
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        cin>>a[i].fi>>a[i].se;
    }
    build(1,1,k);
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;i++) {
        if (a[i].fi>=it[1][0]) {
            updatemin(a[i].se);
            ans++;
        }
        else {
            if (a[i].se<it[1][1]) {
                updatemax(a[i].se);
            }
        }
    }
    cout<<ans;
}
