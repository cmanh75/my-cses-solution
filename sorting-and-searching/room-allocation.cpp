#include<bits/stdc++.h>
using namespace std;
int n,res;
priority_queue <pair <int ,int > > q;
struct ii {
    int x,y,z,t;
} a[1000009];
bool ss(ii m,ii n) {
    return m.x<n.x;
}
bool sss(ii m,ii n) {
    return m.z<n.z;
}
set <int> s;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i].x>>a[i].y;
        a[i].z=i;
    }
    sort(a+1,a+n+1,ss);
    for (int i=1;i<=n;i++) {
        while (q.size()&&-q.top().first<a[i].x) {
            s.insert(q.top().second);
            q.pop();
        }
        if (!s.size()) {
            a[i].t=q.size()+1;
            q.push({-a[i].y,q.size()+1});
        }
        else {
            auto it=s.begin();
            a[i].t=*it;
            s.erase(*it);
            q.push({-a[i].y,*it});
        }
        if (res<q.size()) {
            res=q.size();
        }
    }
    cout<<res<<"\n";
    sort(a+1,a+n+1,sss);
    for (int i=1;i<=n;i++) {
        cout<<a[i].t<<" ";
    }
}
