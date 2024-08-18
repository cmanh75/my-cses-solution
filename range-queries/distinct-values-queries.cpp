#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
struct iii {
    int x,y,z;
};
typedef pair <int,int> pa;
int n,a[1009][1009],res[1000009],bit[1000009],q,x,y,z;
vector <iii> s;
map <int,int> last;
bool cmp(iii m,iii n) {
    return (m.y<n.y||(m.y==n.y&&m.z<n.z));
}
int ans(int x) {
    int z=0;
    for (;x>0;x&=(x-1)) {
        z+=bit[x];
    }
    return z;
}
void update(int x,int val) {
    for (;x<=n;x+=(x&-x)) {
        bit[x]+=val;
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
        cin>>x;
        s.push_back({x,i,0});
    }
    for (int i=1;i<=q;i++) {
        cin>>x>>y;
        s.push_back({x,y,i});
    }
    sort(s.begin(),s.end(),cmp);
    for (auto [x,y,z] : s) {
        if (z>0) {
            res[z]=ans(y)-ans(x-1);
        }
        else {
            if (last[x]) {
                update(last[x],-1);
            }
            last[x]=y;
            update(y,1);
        }
    }
    for (int i=1;i<=q;i++) {
        cout<<res[i]<<"\n";
    }
}