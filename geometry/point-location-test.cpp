#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
typedef pair<ll,pii> plii;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pil> vil;
typedef vector<plii> vlii;
typedef vector<pli> vli;
typedef vector<ll> vl;
const int N=300005;
const int M=100005;
const int moh=1e9+3;
const ll mod=1e9+7;
const int base=311;
const int oi=1e9+1;
const ll oo=1e18;
const double eps=1e-9;
int dx[]={1,0,0,-1,1,1,-1,-1};
int dy[]={0,1,-1,0,-1,1,-1,1};
struct point {
    int x,y;
}a,b,c;
struct vt {
    int x,y;
    vt operator + (const vt& a) const {
        return {x+a.x,y+a.y};
    }
    vt operator - (const vt& a) const {
        return {a.x-x,a.y-y};
    }
    double operator * (const vt& a) const {
        return x*a.x+y*a.y;
    }
    ll operator ^ (const vt& a) const {
        return 1ll*x*a.y-1ll*y*a.x;
    }
    double legth() const {
        return sqrt(x*x+y*y);
    }
};
vt vec(point a,point b){
    return {b.x-a.x,b.y-a.y};
}
struct seg {
    double a,b,c;
    double dist(const point& x) const{
        return (a*x.x+b*x.y+c)/sqrt((a*a+b*b));
    }
} r;
void solve() {
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
    vt o=vec(a,b);
    vt u=vec(b,c);
    if ((o^u)>0) {
        cout<<"LEFT"<<"\n";
    }
    if ((o^u)<0) {
        cout<<"RIGHT"<<"\n";
    }
    if ((o^u)==0) {
        cout<<"TOUCH"<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    int test;
    cin>>test;
    while (test--) {
        solve();
    }
}
